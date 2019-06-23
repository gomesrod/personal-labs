/**
 * Created by rodrigo on 27/02/17.
 */

def map1 = ["um": 1, "dois": 2, "tres": 3];

println map1;
println map1.getClass();
println (map1 instanceof java.util.Map<String, Integer>);
println map1.size();
println()
println map1.get("dois");
println map1["dois"];

println()
void funcaoQueRecebeUmMap(inputMap) {
    println("FQRM ${inputMap}")
    println(inputMap["Val2"])
}
// Passa mapa direto no argumento
funcaoQueRecebeUmMap("Val1": new Date(), "Val2": 3.14f)

println()
class AClass {
    String nome
    int valor
}
// Passando parametros para construcao do objeto usando sintaxe de map
AClass obj = new AClass("nome":"Um Objeto", "valor": 50)
println(obj.nome + "  " + obj.valor)

