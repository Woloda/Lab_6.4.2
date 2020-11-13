#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4(2)/Lab_6.4(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab642
{
	TEST_CLASS(UnitTestLab642)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double masuv_b[6] = { 6.4, 8.0, 3.0, 4.0, 5.0, 6.0 };
			double sum = suma(masuv_b, 6, 0,0, 5);
			Assert::AreEqual(sum, 20.0);
		}
		TEST_METHOD(TestMethod2)
		{
			double masuv_b[6] = { 6.4, 8.9, 3.2, 4.6, 5.3, 6.0 };
			double min = min_values(masuv_b, 6, 1, masuv_b[0]);
			Assert::AreEqual(min, 3.2);
		}
	};
}
