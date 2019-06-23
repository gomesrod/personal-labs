package com.mytests.java8labs;

import java.time.*;

/**
 *
 */
public class _15_DateAPI {
    public static void main(String[] args) {

        LocalDate today = LocalDate.now();
        System.out.println(today);

        LocalDate vintecincoDeJaneiro = LocalDate.of(2015, Month.JANUARY, 25);
        System.out.println(vintecincoDeJaneiro);

        LocalDate mesquevem = today.plusMonths(1);
        System.out.println(mesquevem);

        LocalTime hour = LocalTime.now();
        System.out.println(hour);

        LocalDateTime now = LocalDateTime.now();
        System.out.println(now);

        LocalDateTime mesQueVemQuatrohoradatarde = mesquevem.atTime(16, 00);
        System.out.println(mesQueVemQuatrohoradatarde);

        System.out.println(mesQueVemQuatrohoradatarde.isAfter(now));
        System.out.println(mesQueVemQuatrohoradatarde.isBefore(now));

        MonthDay thisMonth = MonthDay.from(today);
        System.out.println(thisMonth);
        System.out.println(thisMonth.getDayOfMonth());

    }
}
