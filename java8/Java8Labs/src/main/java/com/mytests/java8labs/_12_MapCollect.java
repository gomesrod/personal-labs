
package com.mytests.java8labs;

import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 *
 * @author t3276780
 */
public class _12_MapCollect {
	public static void main(String[] args) throws IOException {
		
		System.out.println("----------- modo 1");
		Map<Path, Long> linesPerFile = new HashMap<>();
		Files.list(Paths.get("./src/main/java/com/mytests/java8labs"))
				.forEach(p-> linesPerFile.put(p, toLines(p).count()));
		System.out.println(linesPerFile);
		
		System.out.println("----------- usando map collector");
		Map<Path, Long> linesPerFile2 = 
		Files.list(Paths.get("./src/main/java/com/mytests/java8labs"))
				.collect(Collectors.toMap(
						Function.identity(), 
						p -> toLines(p).count()));
		System.out.println(linesPerFile2);

	}
	
	static Stream<String> toLines(Path p) {
		try {
			return Files.lines(p);
		} catch (IOException ex) {
			throw new UncheckedIOException(ex);
		}
	}
}
