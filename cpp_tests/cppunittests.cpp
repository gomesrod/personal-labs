//
// g++ cppunittests.cpp -L /usr/local/lib -l cppunit -o cppunittests.exe
//
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include <iostream>
#include <stdexcept>

class Vector2D
{
public:
	const int x;
	const int y;

	Vector2D(int _x, int _y) : x(_x),y(_y) {}

	bool operator==(const Vector2D& other) const
	{
		return this->x == other.x && this->y == other.y;
	}

	bool operator!=(const Vector2D& other) const
	{
		return !operator==(other);
	}

	const Vector2D operator+(const Vector2D&parcel) const
	{
		return Vector2D(this->x + parcel.x, this->y + parcel.y);
	}

	const Vector2D operator/(const int denom) const
	{
		if (denom == 0) throw std::logic_error("Division by zero");

		return Vector2D(this->x / denom, this->y / denom);
	}
};

class Vector2DTests : public CppUnit::TestFixture
{
public:
	void setUp()
	{
		std::cout << "setUp()... ";
	}
	
	void tearDown()
	{
		std::cout << "tearDown()" << std::endl;
	}

	// Automatic suite generation
	CPPUNIT_TEST_SUITE(Vector2DTests);
	CPPUNIT_TEST(objectConstruction);
	CPPUNIT_TEST(equality);
	CPPUNIT_TEST(unequality);
	CPPUNIT_TEST(sum);
	CPPUNIT_TEST(division);
	CPPUNIT_TEST_EXCEPTION(divisionByZero, std::logic_error);
	CPPUNIT_TEST_SUITE_END();
	//////////////////////////////////////////////

public:
	void objectConstruction()
	{
		Vector2D vec(3, 5);
		CPPUNIT_ASSERT(vec.x == 3);
		CPPUNIT_ASSERT(vec.y == 5);
	}

	void equality()
	{
		Vector2D v1(100,101);
		Vector2D v2(100,101);
		Vector2D v3(99 ,101);
		Vector2D v4(100,102);

		CPPUNIT_ASSERT(v1 == v2);
		CPPUNIT_ASSERT(v2 == v1);
		CPPUNIT_ASSERT(!(v1 == v3));
		CPPUNIT_ASSERT(!(v1 == v4));
	}

	void unequality()
	{
		Vector2D v1(100,101);
		Vector2D v2(100,101);
		Vector2D v3(99 ,101);
		Vector2D v4(100,102);

		CPPUNIT_ASSERT(!(v1 != v2));
		CPPUNIT_ASSERT(!(v2 != v1));
		CPPUNIT_ASSERT(v1 != v3);
		CPPUNIT_ASSERT(v1 != v4);
	}

	void sum()
	{
		Vector2D v1(7,20);
		Vector2D v2(1000, 2000);

		CPPUNIT_ASSERT((v1+v2) == Vector2D(1007,2020));
	}

	void division()
	{
		Vector2D vec(100, 15);

		CPPUNIT_ASSERT(vec/5 == Vector2D(20, 3));
	}

	void divisionByZero()
	{
		Vector2D vec(1,1);
		vec/0;
	}

};

// Manual suite creation
CppUnit::TestSuite* suite()
{
	CppUnit::TestSuite* suit = new CppUnit::TestSuite("Vector-2D Tests");

	suit->addTest(new CppUnit::TestCaller<Vector2DTests>("objectConstruction", &Vector2DTests::objectConstruction));
	suit->addTest(new CppUnit::TestCaller<Vector2DTests>("equality", &Vector2DTests::equality));
	suit->addTest(new CppUnit::TestCaller<Vector2DTests>("unequality", &Vector2DTests::unequality));

	return suit;
}


int main()
{
	CppUnit::TextUi::TestRunner runner;

	CppUnit::TestSuite* suit = suite();
	// Includes the automatically generated suite
	CppUnit::TestSuite* suit2 = Vector2DTests::suite();

	runner.addTest(suit);
	runner.addTest(suit2);

	runner.run();

	return 0;
}
