/**
 * Created by rodrigo on 27/02/17.
 */

class SomeClosures {
    def closureSemParametros = {println "Sou uma closure"}

    def closureComParametroImplicito = {println "Recebido parametro: ${it}"}

    def closureComParametros = {a, b -> println("Recebi os parametros a=${a} e b=${b}")}
}

SomeClosures closures = new SomeClosures();

closures.closureSemParametros();

closures.closureComParametroImplicito();
closures.closureComParametroImplicito("Param");

try {
    closures.closureComParametros()
} catch (e) {
    println "xxxx-> ${e.getMessage()}"
}

println()
closures.closureComParametros("Prime", "Segu")

Closure closureRef = closures.closureComParametros;
closureRef("Terce", "Quar")

///////////////////////////////////////
// Closure mantendo referencia ao contexto
println()

Closure criaUmaClosure() {
    int localVal = 5;
    def retClos = {
        println "Vou imprimir uma variavel do contexto em que fui criada: ${localVal}"
    };

    // Alterando a variavel para demonstrar que existe referencia ao contexto e nao simples copia da variavel
    localVal = 6;

    return retClos;
}

def closuCtx = criaUmaClosure();
closuCtx();

