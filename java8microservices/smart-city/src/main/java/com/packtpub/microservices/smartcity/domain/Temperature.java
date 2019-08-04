package com.packtpub.microservices.smartcity.domain;

public class Temperature {

    private Double temperature;
    private TemperatureScale temperatureScale;

    public Double getTemperature() {
        return temperature;
    }

    public void setTemperature(Double temperature) {
        this.temperature = temperature;
    }

    public TemperatureScale getTemperatureScale() {
        return temperatureScale;
    }

    public void setTemperatureScale(TemperatureScale temperatureScale) {
        this.temperatureScale = temperatureScale;
    }

    @Override
    public String toString() {
        return "Temperature{" +
                "temperature=" + temperature +
                ", temperatureScale=" + temperatureScale +
                '}';
    }
}
