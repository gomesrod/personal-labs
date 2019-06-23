// compile with: /target:library /reference:abstractshape.dll
//
using System;

public class Square : Shape
{
	private int mySide;

	public Square(string id, int side) : base(id)
	{
		mySide = side;
	}

	public override double Area
	{
		get
		{
			return mySide * mySide;
		}
	}

}

public class Circle : Shape
{
	private int myRadius;

	public Circle(string id, int radius) : base(id)
	{
		myRadius = radius;
	}

	public override double Area
	{
		get
		{
			return Math.PI * myRadius * myRadius;
		}
	}
}

public class Rectangle : Shape
{
	private int myWidth;
	private int myHeight;

	public Rectangle(string id, int width, int height) : base(id)
	{
		myWidth = width;
		myHeight = height;
	}

	public override double Area
	{
		get
		{
			return myWidth * myHeight;
		}
	}
}


