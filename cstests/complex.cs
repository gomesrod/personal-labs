using System;

public struct Complex
{
	public int real;
	public int imaginary;

	public Complex(int real, int imaginary)
	{
		this.real = real;
		this.imaginary = imaginary;
	}

	public static Complex operator +(Complex c1, Complex c2)
	{
		return new Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
	}

	public override string ToString()
	{
		return String.Format("{0}+{1}i", real, imaginary);
	}

	public static void Main()
	{
		Complex num1 = new Complex(2,3);
		Complex num2 = new Complex(3,4);

		Complex sum = num1 + num2;

		Console.WriteLine("{0}  (+)  {1}  =  {2}", num1, num2, sum);
	}
}

