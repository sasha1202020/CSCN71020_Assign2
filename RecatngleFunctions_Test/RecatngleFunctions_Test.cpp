#include "pch.h"
#include "CppUnitTest.h"

extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" int setLength(int input, int* length);
extern "C" int setWidth(int input, int* width);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecatngleFunctionsTest
{
	TEST_CLASS(RecatngleFunctionsTest)
	{
	public:
		
		TEST_METHOD(PerimeterTest)
		{
			//This testing the getPerimeter function using 
			//4 as a lentgh and 2 as a width
			//formula : 4*2 + 2*2 = 12 or 4 + 4 + 2 + 2 = 12
			int Result = 0;
			int length = 4;
			int width = 2;
			Result = getPerimeter(&length, &width);
			Assert::AreEqual(12, Result);
		}


		TEST_METHOD(AreaTest)
		{
			//This testing the getArea function using
			//5 as a length and 3 as a width
			//formula : 5 * 3 = 15
			int Result = 0;
			int length = 5;
			int width = 3;
			Result = getArea(&length, &width);
			Assert::AreEqual(15, Result);

		}


		//Testing the setLength function
		//1) By exceeding The upper limits
		//2) Testing the number inside limits
		//3) By understating the lower limits
		TEST_METHOD(LengthOutOfBoundsMoreThanNinetyNine)
		{
			//This testing that function should fail if input is more than 99 inclusive
			//The next integer after 99 is 100, will try with 100.
			int length = 0;
			setLength(100, &length);
			Assert::IsTrue(100 != length);
		}

		TEST_METHOD(LenghtInsideTheBounds)
		{
			//This testing that function should  if input is more than 1 and less than 99 inclusive
			//Let's take a half, this means 50
			int length = 0;
			setLength(50, &length);
			Assert::IsTrue(50 == length);
		}

		TEST_METHOD(LengthOutOfBoundsLessThanOne)
		{
			//This testing that function should fail if input is less than 1 inclusive
			//The previous number before 1 is 0, will try with 0
			int length = 6;         //Put a 6 and not 0 like in the others TEST_METHOD,
			//because In this case it will always return true if length = 0 ( input(0) = lenght(0) even if "if" statement fails.
			setLength(0, &length);
			Assert::IsTrue(0 != length);
		}
		//END OF setLength TESTING
		//
		//

		// 
		//Testing the setWidth function
		//1)By exceeding upper limits
		//2)By testing the  number inside limits
		//3)By understating the lower limits

		TEST_METHOD(WidthOutOfBoundsMoreThanNinetyNine)
		{
			//This testing that function should fail if input is more than 99 inclusive
			//The next number after 99 is 100, will try with 100
			int width = 0;
			setWidth(100, &width);
			Assert::IsTrue(100 != width);
		}

		TEST_METHOD(WidthInputInsideTheBounds)
		{
			//This testing that function should  if input is more than 1 and less than 99 inclusive
			//Let's take a liitle less than a half, this means 49
			int width = 0;
			setWidth(49, &width);
			Assert::IsTrue(49 == width);
		}

		TEST_METHOD(WidthOutOfBoundsLessThanOne)
		{
			//This testing that function should fail if input is less than one inclusive
			//The previous number before 1 is 0, will try with 0
			int width = 6; //Put a 6 and not 0 like in the others TEST_METHOD,
			//because In this case it will always return true if length = 0 ( input(0) = lenght(0) even if "if" statement fails.
			setWidth(0, &width);
			Assert::IsTrue(0 != width);
		}
		//END OF setWidth FUNCTION
	};
}
