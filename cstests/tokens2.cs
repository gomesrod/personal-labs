using System;
using System.Collections;

public class Tokens : IEnumerable
{
	private string[] elements;

	Tokens(string source, char[] delimiters)
	{
		elements = source.Split(delimiters);
	}

	// non-IEnumerable version
	public TokenEnumerator GetEnumerator()
	{
		return new TokenEnumerator(this.elements);
	}


	// IEnumerable version
	IEnumerator IEnumerable.GetEnumerator()
	{
		return (IEnumerator) new TokenEnumerator(this.elements);
	}

	// Inner class implementation
	public class TokenEnumerator : IEnumerator
	{
		private int position = -1;
		private string[] elements;

		public TokenEnumerator(string[] elems)
		{
			this.elements = elems;
		}

		public bool MoveNext()
		{
			if (position < elements.Length - 1)
			{
				position++;
				return true;
			}
			else
			{
				return false;
			}
		}

		public void Reset()
		{
			position = -1;
		}

		// non IEnumerator version: type safe
		public string Current
		{
			get
			{
				return elements[position];
			}
		}

		// IEnumerator version
		object IEnumerator.Current
		{
			get
			{
				return elements[position];
			}
		}

	}

	static void Main()
	{
		Tokens f = new Tokens("This is a well-done program.", new char[] {' ', '-'});
		foreach (string item in f)
		{
			Console.WriteLine(item);
		}
	}
}

