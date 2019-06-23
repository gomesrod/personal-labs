package com.mytests.java8labs;

import java.util.Arrays;
import java.util.List;
import java.util.function.Consumer;

/**
 *
 * @author t3276780
 */
public class _01_Foreach {
    public static void main(String[] args) {
        List<Usuario> usuarios = Usuario.criaListaUsuarios();

        System.out.println("_____________ Declarando Consumer inteiro");
        usuarios.forEach(new Consumer<Usuario>() {
            @Override
            public void accept(Usuario u) {
                System.out.println(u);
            }
        });

        System.out.println("_____________ Declarando Consumer lambda");
        Consumer<Usuario> mostrador = (Usuario u) -> {System.out.println(u);};
        usuarios.forEach(mostrador);

        System.out.println("_____________ Declarando Consumer lambda - syntax 2");
        Consumer<Usuario> mostrador2 = u -> {System.out.println(u);};
        usuarios.forEach(mostrador2);
        
        System.out.println("_____________ Tornando moderador com lambda anonimo");
        usuarios.forEach(u -> {u.tornaModerador();});
        
        System.out.println("_____________ Anonymous simplificado");
        Consumer<Usuario> mostrador3 = u -> System.out.println(u);
        usuarios.forEach(mostrador3);
    }
}
