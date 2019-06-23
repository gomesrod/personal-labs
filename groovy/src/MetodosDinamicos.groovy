/**
 * Created by rodrigo on 27/02/17.
 */

class FazTudo {
    void andar() {
        println "Andando"
    }
    void deitar() {
        println "Deitado"
    }
    void trabalhar() {
        println "Trabalhando"
    }
    void falar(palavra) {
        println "Falando ${palavra}"
    }

    def methodMissing(String name, args) {
        if (args) {
            println "Ainda nao sei ${name} : ${args}"
        } else {
            println "Ainda nao sei ${name}"
        }
    }
}

FazTudo ft = new FazTudo()

// Invocacao de metodo normal
ft.andar()

// Invoca como string
ft.deitar()

// Invoca usando variavel
def metodo = "trabalhar"
ft."${metodo}"()

metodo = "falar"
ft."${metodo}"("Oi");

// Metodos nao existem mas serao respondidos pelo methodMissing
ft.correr()
ft."sentar"()
ft.comprar("Arroz", "Feijao")