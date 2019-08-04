package com.packtpub.microservices.smartcity.domain;

import java.util.ArrayList;
import java.util.Collection;

public class ServiceResponse {
    private final Collection<Forecast> forecasts;
    private long processingTime;

    public ServiceResponse() {
        forecasts = new ArrayList<>();
    }

    public Collection<Forecast> getForecasts() {
        return forecasts;
    }

    public void setProcessingTime(long processingTime) {
        this.processingTime = processingTime;
    }

    public long getProcessingTime() {
        return processingTime;
    }
}
