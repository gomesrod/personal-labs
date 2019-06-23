
package com.mytests.java8labs;

import java.util.Comparator;
import java.util.List;
import java.util.function.Consumer;

/**
 *
 * @author t3276780
 */
public class _05_MethodReference {
    public static void main(String[] args) {
        List<Usuario> usuarios = Usuario.criaListaUsuarios();
        
        Consumer<Usuario> tornaModeradorMethodReference = Usuario::tornaModerador;
        usuarios.forEach(tornaModeradorMethodReference);
        
        usuarios.forEach(u->System.out.println(u));
        
        System.out.println("----------------------");
        usuarios.sort(Comparator.comparing(Usuario::getNome));
        usuarios.forEach(u->System.out.println(u));
                
        /////////////////////////////////////////////////////////
        //
        usuarios = Usuario.criaListaUsuarios();
        
        // Referenciando metodo de uma instancia especifica
        Runnable r = usuarios.get(1)::tornaModerador;
        r.run();
        
        System.out.println("----------------------");
        Consumer<Usuario> imprimeUsuarios = System.out::println; // equivalente a u->System.out.println(u);        
        usuarios.forEach(imprimeUsuarios);
    }
}
