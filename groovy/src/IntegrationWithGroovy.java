import groovy.lang.Closure;

/**
 * Created by rodrigo on 28/02/17.
 */
public class IntegrationWithGroovy {
    public static void main(String[] args) {
        WillBeUsedByJavaCode groovyClass = new WillBeUsedByJavaCode();

        groovyClass.setStringWithAcessors("getSet");
        groovyClass.publicProp = "Pub";

        Closure closu = groovyClass.printClosure;
        closu.call( "Integrated Groovy");
        closu.call(groovyClass.getStringWithAcessors());
        closu.call(groovyClass.publicProp);

        groovyClass.invokeMethod("printSomething", "MSG");
    }
}
