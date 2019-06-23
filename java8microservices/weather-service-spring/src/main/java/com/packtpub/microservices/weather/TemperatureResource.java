package com.packtpub.microservices.weather;

import com.packtpub.microservices.weather.domain.Temperature;
import com.packtpub.microservices.weather.domain.TemperatureScale;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping(path = "/temperature")
public class TemperatureResource {

    @RequestMapping(method = RequestMethod.GET)
    public ResponseEntity<Temperature> getAverageTemperature() {
        Temperature temperature = new Temperature();
        temperature.setTemperature(35D);
        temperature.setTemperatureScale(TemperatureScale.CELSIUS);

        return ResponseEntity.ok(temperature);
    }

}
