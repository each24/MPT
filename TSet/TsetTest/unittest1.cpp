#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TSet/TSet.h"
#include "../../Lab1/Lab1/Drobi.h"
#include "../TSet/TSetInh.h"
#include <random>
#include <ctime>
#include <iterator>

/*
const bool Drobi::operator < (const Drobi &b) {
	Drobi other = b;
	Drobi a = *this - other;
	if (a.getChislitel() >= 0)
		return true;
	else
		return false;
}
*/

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace TsetTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(EraseTest) {
			srand(time(NULL));
			TSet< Drobi > testClass;
			set< Drobi > testSet;
			//TSetInh<Drobi> testISet;

			for (int i = 0; i < 10; ++i) {
				Drobi frac(1, i + 1);
				testClass.add(frac);
				testSet.insert(frac);
				//testISet.insert(frac);
			}
			Assert::AreEqual(testClass.count(), 10);
			int numberOfElems = rand() % 5 + 2;
			/*for (int i = 0; i < numberOfElems; ++i) {
				testClass.del(testClass.elem(i));
				//testISet.erase(testISet.elemAt(i));
				testSet.erase(testClass.elem(i));
			}*/
			//Assert::AreEqual(testClass.count(), (int)(10 - numberOfElems));
			//Assert::AreEqual((int)testISet.size(), (int)(10 - numberOfElems));
			//Assert::AreEqual((int)testSet.size(), (int)(10 - numberOfElems));
		}
		
		TEST_METHOD(AdditionTestTSetAll1) {
			TSet<Drobi> testClass1;
			TSet<Drobi> testClass2;
			TSet<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i + 25, i + 26);
				testClass1.add(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.add(frac);
			}
			testClassResult = testClass1.addition(testClass2);
			Assert::AreEqual(testClassResult.count(), 40);
		}
		TEST_METHOD(AdditionTestTSetAll0) {
			srand(time(NULL));
			TSet<Drobi> testClass1;
			TSet<Drobi> testClass2;
			TSet<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass1.add(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.add(frac);
			}
			testClassResult = testClass1.addition(testClass2);
			Assert::AreEqual(testClassResult.count(), 20);
		}
		TEST_METHOD(AdditionTestTSetInhAll1) {
			TSetInh<Drobi> testClass1;
			TSetInh<Drobi> testClass2;
			TSetInh<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i + 25, i + 26);
				testClass1.insert(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.insert(frac);
			}
			testClassResult = testClass1.addition(testClass2);
			Assert::AreEqual((int)testClassResult.size(), 40);
		}
		TEST_METHOD(AdditionTestTSetInhAll0) {
			TSetInh<Drobi> testClass1;
			TSetInh<Drobi> testClass2;
			TSetInh<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass1.insert(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.insert(frac);
			}
			testClassResult = testClass1.addition(testClass2);
			Assert::AreEqual((int)testClassResult.size(), 20);
		}
		
		TEST_METHOD(SubtractionTest0) {
			TSet<Drobi> testClass1;
			TSet<Drobi> testClass2;
			TSet<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass1.add(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.add(frac);
			}
			testClassResult = testClass1.subtraction(testClass2);
			Assert::AreEqual(testClassResult.count(), 0);
		}
		TEST_METHOD(SubtractionTest1) {
			TSet<Drobi> testClass1;
			TSet<Drobi> testClass2;
			TSet<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i + 25, i + 26);
				testClass1.add(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.add(frac);
			}
			testClassResult = testClass1.subtraction(testClass2);
			Assert::AreEqual(testClassResult.count(), 20);
		}
		TEST_METHOD(SubtractionTest2) {
			TSet<Drobi> testClass1;
			TSet<Drobi> testClass2;
			TSet<Drobi> testClassResult;
			for (int i = 0; i < 10; ++i) {
				Drobi frac(i, i + 1);
				testClass1.add(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.add(frac);
			}
			testClassResult = testClass2.subtraction(testClass1);
			Assert::AreEqual(testClassResult.count(), 10);
		}
		TEST_METHOD(SubtractionTestINH0) {
			TSetInh<Drobi> testClass1;
			TSetInh<Drobi> testClass2;
			TSetInh<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass1.insert(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.insert(frac);
			}
			testClassResult = testClass1.substraction(testClass2);
			Assert::AreEqual((int)testClassResult.size(), 0);
		}
		TEST_METHOD(SubtractionTestINH1) {
			TSetInh<Drobi> testClass1;
			TSetInh<Drobi> testClass2;
			TSetInh<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i + 25, i + 26);
				testClass1.insert(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.insert(frac);
			}
			testClassResult = testClass1.substraction(testClass2);
			Assert::AreEqual((int)testClassResult.size(), 20);
		}
		TEST_METHOD(SubtractionTestINH2) {
			TSetInh<Drobi> testClass1;
			TSetInh<Drobi> testClass2;
			TSetInh<Drobi> testClassResult;
			for (int i = 0; i < 10; ++i) {
				Drobi frac(i, i + 1);
				testClass1.insert(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.insert(frac);
			}
			testClassResult = testClass2.substraction(testClass1);
			Assert::AreEqual((int)testClassResult.size(), 10);
		}
		TEST_METHOD(MultiplyTestINH1) {
			TSetInh<Drobi> testClass1;
			TSetInh<Drobi> testClass2;
			TSetInh<Drobi> testClassResult;
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass1.insert(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.insert(frac);
			}
			testClassResult = testClass1.multiply(testClass2);
			Assert::AreEqual((int)testClassResult.size(), 20);
		}
		TEST_METHOD(MultiplyTestINH0) {
			TSetInh<Drobi> testClass1;
			TSetInh<Drobi> testClass2;
			TSetInh<Drobi> testClassResult;
			for (int i = 0; i < 10; ++i) {
				Drobi frac(i, i + 1);
				testClass1.insert(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.insert(frac);
			}
			testClassResult = testClass1.multiply(testClass2);
			Assert::AreEqual((int)testClassResult.size(), 10);
		}
		TEST_METHOD(MultiplyTest0) {
			TSet<Drobi> testClass1;
			TSet<Drobi> testClass2;
			TSet<Drobi> testClassResult;
			for (int i = 0; i < 10; ++i) {
				Drobi frac(i, i + 1);
				testClass1.add(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.add(frac);
			}
			testClassResult = testClass2.subtraction(testClass1);
			Assert::AreEqual(testClassResult.count(), 10);
		}
		TEST_METHOD(MultiplyTest1) {
			TSet<Drobi> testClass1;
			TSet<Drobi> testClass2;
			TSet<Drobi> testClassResult;
			for (int i = 0; i < 10; ++i) {
				Drobi frac(i, i + 1);
				testClass1.add(frac);
			}
			for (int i = 0; i < 20; ++i) {
				Drobi frac(i, i + 1);
				testClass2.add(frac);
			}
			testClassResult = testClass2.subtraction(testClass1);
			Assert::AreEqual(testClassResult.count(), 10);
		}
	};
}