using System;

namespace Bookstore
{
	using System.Collections;

	public struct Book
	{
		public string Title;
		public string Author;
		public decimal Price;
		public bool Paperback;

		public Book(string title, string author, decimal price, bool paperBack)
		{
			this.Title = title;
			this.Author = author;
			this.Price = price;
			this.Paperback = paperBack;
		}
	}

	public delegate void ProcessBookDelegate(Book book);

	// Maintains a book database
	public class BookDB
	{
		ArrayList list = new ArrayList();

		public void AddBook(string title, string author, decimal price, bool paperBack)
		{
			list.Add(new Book(title, author, price, paperBack));
		}

		public void ProcessPaperbackBooks(ProcessBookDelegate processBook)
		{
			foreach (Book b in list)
			{
				if (b.Paperback)
				{
					processBook(b);
				}
			}
		}
	}

}

namespace BookTestClient
{
	using Bookstore;

	class PriceTotaller
	{
		int countBooks = 0;
		decimal priceBooks = 0.0m;

		internal void AddBookToTotal(Book book)
		{
			countBooks += 1;
			priceBooks += book.Price;
		}

		internal decimal AveragePrice()
		{
			return priceBooks / countBooks;
		}
	}

	class Test
	{
		static void PrintTitle(Book b)
		{
			Console.WriteLine("   {0}", b.Title);
		}

		static void Main()
		{
			BookDB bookDB = new BookDB();
			AddBooks(bookDB);

			Console.WriteLine("Paperback book titles:");
			bookDB.ProcessPaperbackBooks(new ProcessBookDelegate(PrintTitle));

			PriceTotaller totaller = new PriceTotaller();
			bookDB.ProcessPaperbackBooks(new ProcessBookDelegate(totaller.AddBookToTotal));
			Console.WriteLine("Average Paperback book price: {0:#.##}", totaller.AveragePrice());
		}

		static void AddBooks(BookDB bookDB)
		{
		        bookDB.AddBook("The C Programming Language", 
			             "Brian W. Kernighan and Dennis M. Ritchie", 19.95m, true);
			bookDB.AddBook("The Unicode Standard 2.0", 
			              "The Unicode Consortium", 39.95m, true);
			bookDB.AddBook("The MS-DOS Encyclopedia", 
			               "Ray Duncan", 129.95m, false);
			bookDB.AddBook("Dogbert's Clues for the Clueless", 
			               "Scott Adams", 12.00m, true);
		}
	}
}


			
