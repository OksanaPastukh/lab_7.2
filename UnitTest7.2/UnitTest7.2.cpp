#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2/project7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int rowCount = 2;
			int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < 2; i++)
			{
				a[i] = new int[colCount];
			}
			a[0][0] = 1;
			a[0][1] = 2;
			a[0][2] = 0;
			a[1] [0] = 2;
			a[1] [1] = 4;
			a[1] [2] = 0;

			c = find_min_index(a, 0, colCount);
			Assert::AreEqual(c, 2);
		}
	};
}
