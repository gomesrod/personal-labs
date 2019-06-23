
package com.mytests.java8labs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 *
 * @author t3276780
 */
public class _04_Comparator {
    public static void main(String[] args) {
        List<Usuario> usuarios = Usuario.criaListaUsuarios();
        
        Comparator<Usuario> nameComparator = (u1, u2) -> {
            return String.CASE_INSENSITIVE_ORDER.compare(u1.getNome(), u2.getNome());
        };
        
        Collections.sort(usuarios, nameComparator);
        
        usuarios.forEach(u -> System.out.println(u));

        System.out.println("-------------");
        
        usuarios.sort((u1, u2) -> u1.getPontos() - u2.getPontos());
        usuarios.forEach(u -> System.out.println(u));
        
        
        System.out.println("-------------");
        
        Comparator<Usuario> simpleComparator = Comparator.comparing(u->u.getNome());        
        usuarios.sort(simpleComparator);
        usuarios.forEach(u -> System.out.println(u));
    }
}
