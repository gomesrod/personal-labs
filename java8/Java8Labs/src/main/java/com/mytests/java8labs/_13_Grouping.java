package com.mytests.java8labs;

import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

/**
 * TODO: Class description
 */
public class _13_Grouping {
    public static void main(String[] args) {
        Usuario user1 = new Usuario("Paulo Silveira", 150, true);
        Usuario user2 = new Usuario("Rodrigo Turini", 120, true);
        Usuario user3 = new Usuario("Guilherme Silveira", 90);
        Usuario user4 = new Usuario("Sergio Lopes", 120);
        Usuario user5 = new Usuario("Adriano Almeida", 100);

        List<Usuario> usuarios = Arrays.asList(user1, user2, user3, user4, user5);

        Map<Integer, List<Usuario>> pontuacao = new HashMap<>();

        System.out.println("Meio manual");
        for (Usuario u : usuarios) {
            pontuacao.computeIfAbsent(u.getPontos(), p -> new ArrayList<>())
                .add(u);
        }
        System.out.println(pontuacao);

        System.out.println("GroupingBy");
        pontuacao = usuarios.stream()
                .collect(Collectors.groupingBy(Usuario::getPontos));
        System.out.println(pontuacao);

        System.out.println("PartitioningBy");
        Map<Boolean, List<Usuario>> moderadores = usuarios.stream()
                .collect(Collectors.partitioningBy(Usuario::isModerador));
        System.out.println(moderadores);

        // TODO Estudar melhor esse caso
        System.out.println("Transforma em list<String>");
        Map<Boolean, List<String>> moderatorNames = usuarios.stream()
                .collect(Collectors.partitioningBy(Usuario::isModerador,
                        Collectors.mapping(Usuario::getNome, Collectors.toList())));
        System.out.println(moderatorNames);
    }

}
