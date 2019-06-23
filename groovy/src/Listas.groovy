/**
 * Created by rodrigo on 27/02/17.
 */

def list1 = ["um", "dois", "tres"];

println list1;

println (list1 instanceof java.util.List)

// Algumas operacoes com operadores sobrecarregados

list1 += "intruso";
list1 += "quatro";
list1 += "intruso";

println list1;

list1 -= "intruso";
println list1;
println list1[1];

list2 = ["1", "2", "3", "4"] + list1;
println list2;

list2.each {element -> println "### ${element}"}

