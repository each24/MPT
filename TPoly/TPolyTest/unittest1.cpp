#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TPoly/TPoly.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TPolyTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TMemConstructor)
		{
			TMember test(0,0);
			TMember test2(2, 1);
			Assert::AreEqual(test.getK(), 0);
			Assert::AreEqual(test.getN(), 0);
			Assert::AreEqual(test2.getK(), 2);
			Assert::AreEqual(test2.getN(), 1);
		}
		TEST_METHOD(TMemSets)
		{
			TMember test(0,0);
			test.setK(2);
			test.setN(3);
			Assert::AreEqual(test.getK(), 2);
			Assert::AreEqual(test.getN(), 3);
		}
		TEST_METHOD(TMemEqual)
		{
			TMember test(2, 3);
			TMember test2(2, 3);
			TMember test3(3, 4);
			Assert::IsTrue(test == test2);
			Assert::IsFalse(test == test3);
		}
		TEST_METHOD(TMemDifferentiate)
		{
			TMember test(3, 2);
			TMember res(6, 1);
			Assert::IsTrue(test.differentiate() == res);
		}
		TEST_METHOD(TMemCalculate)
		{
			TMember test(4, 3);
			Assert::IsTrue(test.calculate(-2) == -32);
		}
		TEST_METHOD(TPolyConstructor)
		{
			TPoly test(4, 3);
			TPoly test2;
			//Assert::IsTrue(test.elemAt(0) == TMember(4, 3));
			Assert::AreEqual(test2.getN(), 0);
			Assert::AreEqual(test2.getK(0), 0);
		}
		TEST_METHOD(TPolyClear)
		{
			TPoly test(4, 3);
			test.clear();
			Assert::AreEqual(test.getN(), 0);
			Assert::AreEqual(test.getK(0), 0);
		}
		TEST_METHOD(TPolyPlus)
		{
			TPoly test(4, 3);
			TPoly test2 = test + TMember(2, 4);
			Assert::AreEqual(test2.getN(), 4);
			Assert::AreEqual(test2.getK(4), 2);
			Assert::AreEqual(test2.getK(3), 4);
			Assert::AreEqual(test2.calculate(2), 64.0);
			TPoly test3 = test + test;
			Assert::AreEqual(test3.getN(), 3);
			Assert::AreEqual(test3.getK(3), 8);
		}
		TEST_METHOD(TPolyMinus)
		{
			TPoly test(4, 3);

			TPoly test2 = test - TMember(2, 4);
			Assert::AreEqual(test2.getN(), 4);
			Assert::AreEqual(test2.getK(4), -2);
			Assert::AreEqual(test2.getK(3), 4);
			Assert::AreEqual(test2.calculate(2), 0.0);

			TPoly test3 = test2 - TMember(2, 4);
			TPoly test4 = test - test;
			TPoly test5 = test - TMember(4, 3);
			Assert::AreEqual(test3.getN(), 4);
			Assert::AreEqual(test3.getK(4), -4);
			Assert::AreEqual(test3.getK(3), 4);
			Assert::AreEqual(test3.calculate(2), -32.0);
			Assert::AreEqual(test4.getN(), 3);
			Assert::AreEqual(test4.getK(0), 0);
			Assert::AreEqual(test5.getN(), 3);
			Assert::AreEqual(test5.getK(0), 0);
		}
		TEST_METHOD(TPolyMulti)
		{
			TPoly test = TPoly(2, 2) + TMember(3, 1); // 2x^2 + 3x
			TPoly test2 = TPoly(3, 2) + TMember(2, 1); // 3x^2 + 2x
			TPoly test3 = test * test2; // 6x^4 + 13x^3 + 6x^2

			Assert::AreEqual(test3.getK(4), 6);
			Assert::AreEqual(test3.getK(3), 13);
			Assert::AreEqual(test3.getK(2), 6);
			Assert::AreEqual(test3.getK(1), 0);
			Assert::AreEqual(test3.getK(0), 0);
		}
		TEST_METHOD(TPolyEqual)
		{
			TPoly test(2, 2);
			TPoly test2(3, 2);
			TPoly test3(3, 2);
			Assert::IsFalse(test == test2);
			Assert::IsFalse(test == test3);
			Assert::IsFalse(test == test2 + test3);
			Assert::IsTrue(test2 == test3);
			Assert::IsTrue(test3 == test3);
		}
		TEST_METHOD(TPolyDifferentiate)
		{
			TPoly test = (TPoly(2, 2) + TMember(3, 4)).differentiate();
			Assert::AreEqual(test.getK(0), 0);
			Assert::AreEqual(test.getK(1), 4);
			Assert::AreEqual(test.getK(2), 0);
			Assert::AreEqual(test.getK(3), 12);
			Assert::AreEqual(test.getK(4), 0);
		}
		TEST_METHOD(TPolyCalculate)
		{
			TPoly test = TPoly(2, 1) + TMember(1, 2);
			Assert::AreEqual(test.calculate(3), 15.0);
		}
	};
}