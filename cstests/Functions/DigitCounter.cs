using System;

namespace Functions
{
	public class DigitCount
	{
		public static int NumberOfDigits(string theStr)
		{
			int count = 0;
			for (int i = 0; i < theStr.Length; i++)
			{
				if (Char.IsDigit(theStr[i]))
				{
					count++;
				}
			}
			return count;
		}
	}
}

