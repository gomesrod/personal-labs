/**
 * Created by rodrigo on 27/02/17.
 */

def interval = 0..5;

println interval
println interval.contains(4)
println interval.contains(40)

for (a in interval) {
    println "-> ${a}";
}

// Usando diretamente no loop
for (a in 1000..<1005) {   // Com o operador < o intervalo fica aberto (exclusivo)
    println "-> ${a}";
}

// Com lambda
(2001..2005).each({elemento -> println "---> ${elemento}"});