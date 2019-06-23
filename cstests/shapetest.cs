// compile with: /reference:abstractshape.dll;shapes.dll

using System;

public class TestShapes
{
	public static void Main()
	{
		Shape[] shapes = 
			{
			new Square("Square #1", 5),
			new Circle("Circle #1", 3),
			new Rectangle("Rectang #1", 4, 6)
			};
		Console.WriteLine("Shapes Collection");
		foreach(Shape s in shapes)
		{
			Console.WriteLine(s);
		}
	}
}



