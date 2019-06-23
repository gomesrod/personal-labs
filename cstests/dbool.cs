using System;

public struct DBBool
{
	public static readonly DBBool dbNull = new DBBool(0);
	public static readonly DBBool dbFalse = new DBBool(-1);
	public static readonly DBBool dbTrue = new DBBool(1);

	int value;

	//Private constructor
	DBBool(int value)
	{
		this.value = value;
	}

	// Implicit conversion from bool
	public static implicit operator DBBool(bool v)
	{
		return v ? dbTrue : dbFalse;
	}

	// Explicit conversion to bool
	public static explicit operator bool(DBBool v)
	{
		if (v.value == 0) throw new InvalidOperationException("Cannot convert null to bool");
		return v.value > 0;
	}

	// Equality Operator - return dbNull if an argument is dbNull
	public static DBBool operator ==(DBBool x, DBBool y)
	{
		if (x.value == 0 || y.value == 0) return dbNull;
		return x.value == y.value ? dbTrue : dbFalse;
	}

	// Inequality operator
	public static DBBool operator !=(DBBool x, DBBool y)
	{
		if (x.value == 0 || y.value == 0) return dbNull;
		return x.value != y.value ? dbTrue : dbFalse;
	}

	// Logical negation operator
	public static DBBool operator !(DBBool x)
	{
		return new DBBool(-x.value);
	}

	// Logical AND
	public static DBBool operator &(DBBool x, DBBool y)
	{
		return new DBBool(x.value < y.value ? x.value : y.value);
	}

	// Logical OR
	public static DBBool operator |(DBBool x, DBBool y)
	{
		return new DBBool(x.value > y.value ? x.value : y.value);
	}

	// Definetely true operator
	public static bool operator true(DBBool x)
	{
		return x.value > 0;
	}

	// Definetely false operator
	public static bool operator false(DBBool x)
	{
		return x.value < 0;
	}

	// Conversion to string
	public static implicit operator string(DBBool x)
	{
		return x.value > 0 ? "dbTrue"
			: x.value < 0 ? "dbFalse"
			: "dbNull";
	}
	
	public override bool Equals(object o)
	{
		try
		{
			return (bool) (this == (DBBool) o);
		}
		catch
		{
			return false;
		}
	}

	public override int GetHashCode()
	{
		return value;
	}

	public override string ToString()
	{
		return (string)this;
	}
}

class Test
{
	static void Main()
	{
		DBBool a, b;
		a = DBBool.dbTrue;
		b = DBBool.dbFalse;

		Console.WriteLine("!{0} = {1}", a, !a);
		Console.WriteLine("!{0} = {1}", b, !b);
		Console.WriteLine("{0} & {1} = {2}", a, b, a & b);
		Console.WriteLine("{0} | {1} = {2}", a, b, a | b);

		if (b)
		{
			Console.WriteLine("b is definetely true");
		}
		else
		{
			Console.WriteLine("b is not definetely true");
		}
	}
}

