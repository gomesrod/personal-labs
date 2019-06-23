
package com.mytests.java8labs;

import java.util.List;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 *
 * @author t3276780
 */
public class _08_Map {
    public static void main(String[] args) {
        List<Usuario> usuarios = Usuario.criaListaUsuarios();
        
        Function<Usuario, Integer> mapper = u -> u.getPontos();
        List<Integer> pontos = usuarios.stream()
                .map(mapper)
                .collect(Collectors.toList());
        System.out.println(pontos);
        
        System.out.println("Mais enxuto");
        pontos = usuarios.stream()
                .map(Usuario::getPontos)
                .collect(Collectors.toList());
        System.out.println(pontos);
        
    }
}
