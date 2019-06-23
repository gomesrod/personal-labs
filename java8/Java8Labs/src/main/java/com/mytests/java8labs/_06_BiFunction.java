
package com.mytests.java8labs;

import java.util.function.BiFunction;

/**
 *
 * @author t3276780
 */
public class _06_BiFunction {
    public static void main(String[] args) {
        
        BiFunction<Integer, Integer, Integer> max = Math::max;
        
        System.out.println(max.apply(20, 35));
        
        BiFunction<String, Integer, Usuario> criaUsu = Usuario::new;
        
        System.out.println(criaUsu.apply("Jose", 22));
    }
}
