package com.packtpub.microservices;

import com.packtpub.microservices.domain_copy.Temperature;
import io.reactivex.Flowable;
import org.glassfish.jersey.client.rx.rxjava2.RxFlowableInvoker;
import org.glassfish.jersey.client.rx.rxjava2.RxFlowableInvokerProvider;

import javax.ws.rs.client.*;
import javax.ws.rs.core.Response;
import java.util.concurrent.CompletionStage;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

public class TemperatureResourceClient {
    public static void main(String[] args) throws Exception {
        Client client = ClientBuilder.newClient();

        client = client.register(RxFlowableInvokerProvider.class);

        try {
            WebTarget webTarget = client.target("http://localhost:8080/temperature");

//            performSyncRequest(webTarget);
//            performAsyncRequest(webTarget);
//            performAsyncWithCallbackRequest(webTarget);
//            performReactiveRequest(webTarget);
            performRxJavaRequest(webTarget);

        } finally {
            client.close();
        }
    }

    private static void performSyncRequest(WebTarget target) {
        Invocation.Builder builder = target.request();
        Temperature result = builder.get(Temperature.class);

        System.out.println(result);
    }

    private static void performAsyncRequest(WebTarget target) throws ExecutionException, InterruptedException {
        Invocation.Builder builder = target.request();

        Future<Temperature> futureResult = builder
                .async()
                .get(Temperature.class);

        System.out.println("Started the async request");
        System.out.println(futureResult.get());
    }

    private static void performAsyncWithCallbackRequest(WebTarget target) {
        Invocation.Builder builder = target.request();

        Future<Temperature> futureResult = builder
                .async()
                .get(new InvocationCallback<Temperature>() {
                    public void completed(Temperature temperature) {
                        System.out.println(temperature);
                    }

                    public void failed(Throwable t) {
                        System.err.println("Invocation error! " + t);
                        t.printStackTrace();
                    }
                });
        System.out.println("Requested async with callback");
    }

    private static void performReactiveRequest(WebTarget target) {
        Invocation.Builder builder = target.request();

        // Using the default reactive invoker
        CompletionStage<Response> response = builder.rx().get();

        response.thenAccept(res -> {
            System.out.println("Received response in thread: " + Thread.currentThread().getName()
                    + " daemon=" + Thread.currentThread().isDaemon());

            Temperature t = res.readEntity(Temperature.class);
            System.out.println(t);
        });

        System.out.println("Requested async with default rx()");
    }

    private static void performRxJavaRequest(WebTarget target) throws InterruptedException {
        Invocation.Builder builder = target.request();

        Flowable<Response> flowable = builder
                .rx(RxFlowableInvoker.class)
                .get();

        flowable.subscribe(res -> {
            System.out.println("Received response in thread: " + Thread.currentThread().getName()
                    + " daemon=" + Thread.currentThread().isDaemon());

            Temperature t = res.readEntity(Temperature.class);
            System.out.println(t);
        });

        System.out.println("Requested async with RxJava rx()");

        Thread.sleep(1000);
    }
}
