package com.packtpub.microservices.smartcity;

import com.packtpub.microservices.smartcity.domain.Temperature;
import com.packtpub.microservices.smartcity.domain.TemperatureScale;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.util.Random;

@Path("/temperature")
public class TemperatureResource {

    @GET
    @Path("/{city}")
    @Produces(MediaType.APPLICATION_JSON)
    public Response getAverageTemperature(
            @PathParam("city") String cityName) {

        Temperature temperature = new Temperature();
        temperature.setTemperature(calculateTemperature());
        temperature.setTemperatureScale(TemperatureScale.CELSIUS);

        return Response.ok(temperature).build();
    }

    private Double calculateTemperature() {
        Random r = new Random();
        int low = 30, high = 50;

        try {
            // Simulating the temperature measurement processing...
            Thread.sleep(500);
        } catch (InterruptedException ignored) {}

        return (double) (r.nextInt(high - low) + low);
    }
}
