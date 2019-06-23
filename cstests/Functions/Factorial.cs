// Compile with: /target:library
using System;

namespace Functions 
{
	public class Factorial
	{
		public static int Calc (int i)
		{
			return ((i <= 1) ? 1 : (i * Calc(i-1)));
		}
	}

}
