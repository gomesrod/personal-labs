package com.mytests.java8labs;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Month;
import java.time.format.DateTimeFormatter;
import java.time.format.TextStyle;
import java.util.Locale;

/**
 *
 */
public class _16_DateFormat {
    public static void main(String[] args) {
        Locale pt = new Locale("pt","BR");

        System.out.println(Month.DECEMBER.getDisplayName(TextStyle.FULL, pt));
        System.out.println(Month.DECEMBER.getDisplayName(TextStyle.SHORT, pt));

        System.out.println(DayOfWeek.THURSDAY.getDisplayName(TextStyle.FULL, pt));

        LocalDateTime now = LocalDateTime.now();
        System.out.println(now.format(DateTimeFormatter.ISO_LOCAL_TIME));

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        System.out.println(now.format(formatter));

        System.out.println(LocalDate.parse("30/01/2015", formatter));
    }
}
