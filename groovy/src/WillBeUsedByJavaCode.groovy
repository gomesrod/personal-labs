/**
 * Created by rodrigo on 28/02/17.
 */
class WillBeUsedByJavaCode {

    public publicProp
    private privProp

    // Ira criar acessors automaticamente
    String stringWithAcessors

    public Closure printClosure = {println "Hello ${it}"}

    def methodMissing(String name, args) {
        println "Chamado metodo ${name} com parametros ${args}"
    }
}

