package com.packtpub.microservices.smartcity.domain;

public class Forecast {
    private final Location location;
    private final Temperature temperature;

    public Forecast(Location location, Temperature temperature) {

        this.location = location;
        this.temperature = temperature;
    }

    public Location getLocation() {
        return location;
    }

    public Temperature getTemperature() {
        return temperature;
    }
}
