
package com.mytests.java8labs;

import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

/**
 *
 * @author t3276780
 */
public class _11_PathStream {
	public static void main(String[] args) throws IOException {
				
		System.out.println("::::::::: Lista tudo");
		Files.list(Paths.get("./src/main/java/com/mytests/java8labs"))
				.forEach(System.out::println);
		
		System.out.println("::::::::: Classes que nao sao exercicios");
		
		Files.list(Paths.get("./src/main/java/com/mytests/java8labs"))
			.filter(p -> !p.getName(p.getNameCount() - 1).toString().startsWith("_"))
			.forEach(p -> System.out.println(p.getName(p.getNameCount() - 1)));
		
		System.out.println("Conteudo - errado Stream<Stream<String>>");
		Files.list(Paths.get("./src/main/java/com/mytests/java8labs"))
			.filter(p -> !p.getName(p.getNameCount() - 1).toString().startsWith("_"))
			//classesStream.map(Files::lines) // Nao compila por causa da excecao checada dentro do lambda
			.map(_11_PathStream::toLines)
			.forEach(System.out::println);
		
		System.out.println("Achata para Stream<String>");
		Files.list(Paths.get("./src/main/java/com/mytests/java8labs"))
			.filter(p -> !p.getName(p.getNameCount() - 1).toString().startsWith("_"))
			//classesStream.map(Files::lines) // Nao compila por causa da excecao checada dentro do lambda
			.flatMap(_11_PathStream::toLines)
			.forEach(System.out::println);
	}
	
	static Stream<String> toLines(Path p) {
		try {
			return Files.lines(p);
		} catch (IOException ex) {
			throw new UncheckedIOException(ex);
		}
	}
}
