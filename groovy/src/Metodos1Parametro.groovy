/**
 * Created by rodrigo on 27/02/17.
 */

def umParametro(param) {
    println "Metodo com um parametro: ${param}"
}

def doisParametros(param1, param2) {
    println "Metodo com dois parametros: ${param1} ${param2}"
}

// O metodo de um parametro pode ser chamado sem nenhum, implicitamente sera null
umParametro("Primeiro")
umParametro()

// Com o de dois parametros isso nao é possivel
doisParametros("Primeiro", "Segundo")
doisParametros()