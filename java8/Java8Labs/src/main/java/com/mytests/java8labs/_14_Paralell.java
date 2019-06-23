package com.mytests.java8labs;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.LongStream;

/**
 *
 */
public class _14_Paralell {
    public static void main(String[] args) {
        List<Usuario> usuarios = Usuario.criaListaUsuarios();
        System.out.println(usuarios);

        List<Usuario> usuariosOrdenados = usuarios.parallelStream()
                .filter(u -> u.getPontos() > 130)
                .sorted(Comparator.comparing(Usuario::getNome))
                .collect(Collectors.toList());

        System.out.println(usuariosOrdenados);

        System.out.println("Performance warm up");

        // Warm up
        for (int i = 0; i < 100; ++i) {
            LongStream.range(0, 1_000L)
                    .parallel()
                    .filter(x -> x % 2 == 0)
                    .sum();
            LongStream.range(0, 1_000L)
                    .filter(x -> x % 2 == 0)
                    .sum();
        }

        System.out.println("Starting comparation");

        {
            long begin = System.currentTimeMillis();

            long sum = LongStream.range(0, 1_000_000_000L)
                    .filter(x -> x % 2 == 0)
                    .sum();

            long diff = System.currentTimeMillis() - begin;
            System.out.println("Sequential: " + diff + " millis");
        }

        {
            long begin = System.currentTimeMillis();

            long sum = LongStream.range(0, 1_000_000_000L)
                    .parallel()
                    .filter(x -> x % 2 == 0)
                    .sum();

            long diff = System.currentTimeMillis() - begin;
            System.out.println("Paralell: " + diff + " millis");
        }

    }
}
