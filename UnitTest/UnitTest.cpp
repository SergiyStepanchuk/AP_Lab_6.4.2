#include "pch.h"
#include "CppUnitTest.h"
#include "../Program/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(met_sub_dod)
		{
			double mass[10] = { 9, 8, 7, 6, 5, 4 ,3 ,2, 1, 0 };
			Assert::AreEqual(sum_dod(mass, 10), 45.);
		}
	};
}
