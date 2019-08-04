package com.packtpub.microservices.smartcity;

import javax.ws.rs.ApplicationPath;
import javax.ws.rs.core.Application;
import java.util.HashSet;
import java.util.Set;

@ApplicationPath("/smartcity")
public class SmartCityServices extends Application {

    @Override
    public Set<Class<?>> getClasses() {
        Set<Class<?>> classes = new HashSet<>();

        classes.add(LocationResource.class);
        classes.add(TemperatureResource.class);
        classes.add(ForecastResource.class);

        return classes;
    }
}
