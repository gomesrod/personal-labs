/**
 * Created by rodrigo on 27/02/17.
 */

String varMultiLinha = """
Ocupando
Varias
Linhas ! ! !
Com aspas triplas

"""

println varMultiLinha

def varSemTipo1 = "Um"
def varSemTipo2 = 1;
def varSemTipo3 = algumValor();

println varSemTipo1.substring(1);

try {
    println varSemTipo2.substring(1);
} catch (e) {
    println "+++" + e.getMessage();
}

println varSemTipo3.toString();
try {
    println varSemTipo3.substring(1);
} catch (e) {
    println "===> ${e.getMessage()}"; // Usando acoplamento de strings
}

/**
 * Retorna um valor sem um tipo definido na assinatura.
 */
def algumValor() {
    BigDecimal bd = new BigDecimal("3.11");
    bd; //return opcional
}