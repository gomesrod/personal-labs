package com.packtpub.microservices.weather.temperature;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.core.Response;

@Path("/temperature")
public class TemperatureResource {

    @GET
    public Response getAverageTemperature() {
        return Response.ok("35 degrees").build();
    }


}
