println "Executando codigo no corpo do script sem Main"

boolean gt(int a, int b) {
	return a > b; // ponto-e-virgula eh opcional
}

String str = null;

if (str) {
	println "String e = true"
} else {
	println "String e = false"
}
println str

str = "Hello Groovy"

if (str) {
	println "String e = true"
} else {
	println "String e = false"
}
println str

println()
println "2 gt 1 ? " + gt(2,1)
