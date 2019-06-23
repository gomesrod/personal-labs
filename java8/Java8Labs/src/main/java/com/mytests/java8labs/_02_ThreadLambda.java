package com.mytests.java8labs;

/**
 *
 * @author t3276780
 */
public class _02_ThreadLambda {
    
    public static void main(String[] args) {
        Runnable listaNumeros = () -> {
            for (int i = 0; i < 50; i++) {
                System.out.println(i);
                Thread.yield();
            }
        };

        Runnable listaLetras = () -> {
            for (char c = 'a'; c <= 'z'; c++) {
                System.out.println(c);
                Thread.yield();
            }
        };
        
        new Thread(listaNumeros).start();
        new Thread(listaLetras).start();      
    }
    
}
