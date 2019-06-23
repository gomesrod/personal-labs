
package com.mytests.java8labs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Predicate;

/**
 *
 * @author t3276780
 */
public class _03_RemoveIf {
    private static Consumer<Usuario> mostrador = u -> System.out.println(u);
    
    public static void main(String[] args) {
      
        List<Usuario> usuarios = Usuario.criaListaUsuarios();
        
        usuarios.forEach(mostrador);
        
        System.out.println("------------------");
        Predicate<Usuario> removedor = u -> {return u.getPontos() < 140;};
        usuarios.removeIf(removedor);
        
        usuarios.forEach(mostrador);
        
        System.out.println("------------------");
        Predicate<Usuario> removedor2 = u -> u.getPontos() > 160;
        usuarios.removeIf(removedor2);
        
        usuarios.forEach(mostrador);
    }
}
