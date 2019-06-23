/**
 * Created by rodrigo on 27/02/17.
 */


GroovyBean bean = new GroovyBean()

bean.privateProp = "priva";  // Nao funciona como no Java!
println bean.privateProp;

bean.setAutoGenAccessors("auto gen acessors") // Acesso default gera automaticamente get/set
println bean.getAutoGenAccessors();

