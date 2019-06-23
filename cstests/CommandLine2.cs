using System;

public class CommandLine2
{
	public static void Main(string[] args)
	{
		Console.WriteLine("Quandidade de args: {0}", args.Length);
		foreach (string s in args)
		{
			Console.WriteLine(s);
		}
	}
}

