
package com.mytests.java8labs;

import java.util.function.IntSupplier;
import java.util.stream.IntStream;

/**
 *
 * @author t3276780
 */
public class _10_Fibo {
    
    static class FiboSupplier implements IntSupplier {
        private int ultimo = 1;
        private int penultimo = 0;
        
        @Override
        public int getAsInt() {
            int result = ultimo + penultimo;
            penultimo = ultimo;
            ultimo = result;
            return result;
        }        
    }
    
    public static void main(String[] args) {
        IntStream.generate(new FiboSupplier())
                .limit(10)
                .forEach(System.out::println);
        
        int maiorQue1000 = IntStream.generate(new FiboSupplier())
                .filter(n -> n > 1000)
                .findFirst().getAsInt();
        System.out.println(maiorQue1000);
    }
}
