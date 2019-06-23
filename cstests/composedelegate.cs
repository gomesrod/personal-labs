using System;

delegate void MyDelegate(string s);

class MyClass
{
	public static void Hello(string s)
	{
		Console.WriteLine("  Hello, {0}!", s);
	}

	public static void Goodbye(string s)
	{
		Console.WriteLine("  Goodbye, {0}", s);
	}

	public static void Main()
	{
		MyDelegate a, b, c, d;
		a = new MyDelegate(Hello);
		b = new MyDelegate(Goodbye);
		c = a + b;
		d = c - a;
		
		a("A");
		b("B");
		c("C");
		d("D");
	}
}

