using System;

public class Hello3
{
	public static int Main(string[] args)
	{
		Console.WriteLine("Hello 3, C# world");
		Console.WriteLine("You entered the following {0} arguments: ", args.Length);
		for (int i = 0; i < args.Length; i++) 
		{
			Console.WriteLine("{0}", args[i]);
		}

		return 9;
	}
}

