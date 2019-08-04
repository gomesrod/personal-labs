package com.packtpub.microservices.weather;

import eu.agilejava.snoop.annotation.EnableSnoopClient;

import javax.ws.rs.ApplicationPath;
import javax.ws.rs.core.Application;

@EnableSnoopClient(serviceName = "weatherSnoop")
@ApplicationPath("/weather")
public class WeatherMicroService extends Application {
}
