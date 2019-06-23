using System;

class Person
{
	private string myName = "N/A";
	private int myAge = 0;

	public string Name
	{
		get
		{
			return myName;
		}
		set
		{
			myName = value;
		}
	}

	public int Age
	{
		get
		{
			return myAge;
		}
		set
		{
			myAge = value;
		}
	}

	public override string ToString()
	{
		return "Name=" + Name + ", Age=" + Age;
	}


	public static void Main(string[] args)
	{
		Console.WriteLine("Simple Properties");
		Person person = new Person();

		Console.WriteLine("Person Details: {0}", person);

		person.Name = "Joe";
		person.Age = 99;

		Console.WriteLine("Person Details: {0}", person);

		person.Age += 1;
		Console.WriteLine("Person Details: {0}", person);
	}

}
