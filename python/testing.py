def average(values):
	"""Computes the arithmetic mean of a list of numbers.

	>>> print(average([20, 30, 70]))
	40.0
	"""
	return sum(values) / len(values)

import doctest
print("Executing doctest...")
doctest.testmod()
print("Doctest complete")

def wrongsum(a,b):
	"""Sum the values, with an error;

	>>> print(wrongsum(3,5))
	8
	"""
	return a - b

print("Executing doctest... (WITH AN ERROR!)")
doctest.testmod()
print("Doctest complete")
print()
print()

print("UNIT TESTING")
import unittest

class TestStatisticalFunctions(unittest.TestCase):
	def test_average(self):
		self.assertEqual(average([20, 30, 70]), 40.0)
		with self.assertRaises(ZeroDivisionError):
			average([])
		with self.assertRaises(TypeError):
			average(20,30,70)

unittest.main()




