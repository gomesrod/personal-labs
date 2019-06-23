using System;
using System.IO;

// Class to provide access to a large file
// as if it were a byte array
public class FileByteArray
{
	Stream stream;

	public FileByteArray(string fileName)
	{
		stream = new FileStream(fileName,FileMode.Open);
	}

	public void Close()
	{
		stream.Close();
	}

	// The indexer
	public byte this[long index]
	{
		get
		{
			byte[] buffer = new byte[1];
			stream.Seek(index, SeekOrigin.Begin);
			stream.Read(buffer,0,1);
			return buffer[0];
		}
		set
		{
			byte[] buffer = new byte[1] {value};
			stream.Seek(index, SeekOrigin.Begin);
			stream.Write(buffer, 0, 1);
		}
	}

	public long Length
	{
		get
		{
			return stream.Seek(0,SeekOrigin.End);
		}
	}
}

//Demonstration of the FileByteArray class
public class Reverse
{
	public static void Main(string[] args)
	{
		if (args.Length == 0)
		{
			Console.WriteLine("syntax: indexer [filename]");
			return;
		}

		FileByteArray file = new FileByteArray(args[0]);
		long len = file.Length;

		// Do the swap
		for (long i = 0; i < len/2 ; i++)
		{
			byte t = file[i];
			file[i] = file[len - i - 1];
			file[len - i - 1] = t;
		}

		file.Close();
	}
}

			
			
