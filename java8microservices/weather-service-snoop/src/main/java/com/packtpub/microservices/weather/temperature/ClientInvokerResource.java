package com.packtpub.microservices.weather.temperature;

import eu.agilejava.snoop.annotation.Snoop;
import eu.agilejava.snoop.client.SnoopServiceClient;

import javax.enterprise.context.RequestScoped;
import javax.inject.Inject;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

@Path("/invoke")
@RequestScoped
public class ClientInvokerResource {
    @Inject
    @Snoop(serviceName = "weatherSnoop")
    private SnoopServiceClient client;

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String invoke() {
        String response = client.simpleGet("temperature")
                .filter(r -> r.getStatus() == 200)
                .map(r -> r.readEntity(String.class))
                .orElse("Problem occurred!");
        return response;
    }
}
