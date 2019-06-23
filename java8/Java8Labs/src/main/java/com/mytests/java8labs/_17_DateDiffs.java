package com.mytests.java8labs;

import java.time.LocalDate;
import java.time.Month;
import java.time.Period;
import java.time.temporal.ChronoUnit;

/**
 *
 */
public class _17_DateDiffs {
    public static void main(String[] args) {
        LocalDate now = LocalDate.now();
        LocalDate birth = LocalDate.of(1981, Month.APRIL, 27);

        long livingDays = ChronoUnit.DAYS.between(birth, now);
        System.out.println(livingDays);

        long livingYears = ChronoUnit.YEARS.between(birth, now);
        System.out.println(livingYears);

        Period period = Period.between(birth, now);
        System.out.printf("%d anos, %d meses, %d dias", period.getYears(), period.getMonths(), period.getDays());
    }
}
