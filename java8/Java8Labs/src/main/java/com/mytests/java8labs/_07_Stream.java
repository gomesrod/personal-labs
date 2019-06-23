
package com.mytests.java8labs;

import java.util.ArrayList;
import java.util.List;
import java.util.function.BiConsumer;
import java.util.function.Predicate;
import java.util.function.Supplier;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 *
 * @author t3276780
 */
public class _07_Stream {

    public static void main(String[] args) {
        final List<Usuario> usuarios = Usuario.criaListaUsuarios();
        
        System.out.println("Modo mais verbose");
        Stream<Usuario> stream = usuarios.stream();
        Predicate<Usuario> maisDe100pontos = u -> {return u.getPontos() > 130;};
        Stream<Usuario> filtered = stream.filter(maisDe100pontos);
        filtered.forEach(System.out::println);
        
        System.out.println("Modo enxuto");
        usuarios.stream()
                .filter(u -> u.getPontos() < 160)
                .forEach(System.out::println);
        
        System.out.println("Coletando para lista");
        Supplier<ArrayList<Usuario>> supplier = ArrayList::new;
        BiConsumer<ArrayList<Usuario>, Usuario> accumulator = ArrayList::add;
        BiConsumer<ArrayList<Usuario>, ArrayList<Usuario>> combiner = ArrayList::addAll;
        
        List<Usuario> comecaComR = usuarios.stream()
                .filter(u -> u.getNome().matches("^R.*"))
                .collect(supplier, accumulator, combiner);
        comecaComR.forEach(System.out::println);
        
        System.out.println("Coletando com collector");
        List<Usuario> comecaComP = usuarios.stream()
                .filter(u -> u.getNome().matches("^P.*"))
                .collect(Collectors.toList());
    }
}
