package com.packtpub.microservices.smartcity;

import com.packtpub.microservices.smartcity.domain.Forecast;
import com.packtpub.microservices.smartcity.domain.Location;
import com.packtpub.microservices.smartcity.domain.ServiceResponse;
import com.packtpub.microservices.smartcity.domain.Temperature;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.client.WebTarget;
import javax.ws.rs.core.GenericType;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.util.List;

@Path("/forecast")
public class ForecastResource {
    private static final String BASE_URL = "http://localhost:8080/smart-city-1.0-SNAPSHOT/smartcity";

    private final WebTarget locationTarget;
    private final WebTarget temperatureTarget;

    public ForecastResource() {
        Client client = ClientBuilder.newClient();
        this.locationTarget = client.target(BASE_URL + "/location");
        this.temperatureTarget = client.target(BASE_URL + "/temperature/{city}");
    }

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Response getLocationsWithTemperature() {
        long startTime = System.currentTimeMillis();
        ServiceResponse response = new ServiceResponse();

        List<Location> locations = locationTarget.request()
                    .get(new GenericType<List<Location>>() {});

        locations.forEach(location -> {
            Temperature temperature = temperatureTarget
                    .resolveTemplate("city", location.getName())
                    .request()
                    .get(Temperature.class);

            response.getForecasts()
                    .add(new Forecast(location, temperature));
        });

        long endTime = System.currentTimeMillis();
        response.setProcessingTime(endTime - startTime);

        return Response.ok(response).build();
    }
}
