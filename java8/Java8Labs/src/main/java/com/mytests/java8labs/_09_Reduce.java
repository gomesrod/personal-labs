
package com.mytests.java8labs;

import java.util.List;
import java.util.function.IntBinaryOperator;
import java.util.stream.IntStream;

/**
 *
 * @author t3276780
 */
public class _09_Reduce {
    public static void main(String[] args) {
        
        List<Usuario> usuarios = Usuario.criaListaUsuarios();
        
        System.out.println("Media");
        IntStream pontosStream = usuarios.stream()
                .mapToInt(Usuario::getPontos);
        double media = pontosStream.average().getAsDouble();
        System.out.println(media);
        
        System.out.println("Total - Reduce completo");
        int valorInicial = 0;
        IntBinaryOperator operacao = (a, b) -> a + b;
        int total = usuarios.stream()
                .mapToInt(Usuario::getPontos)
                .reduce(valorInicial, operacao);
        System.out.println(total);
       
        
        
    }
}
