#include "stdafx.h"
#include "../TComplexEdit/Edit.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EditorTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			TComplexEditor test;
			Assert::AreEqual(test.getNumber(), to_string(0.0) + "+i*" + to_string(0.0));
		}
		TEST_METHOD(TestIsZero)
		{
			TComplexEditor test;
			Assert::AreEqual(test.isZero(), true);
			test.addDigit(5);
			Assert::AreEqual(test.isZero(), false);
		}
		TEST_METHOD(AddDigit)
		{
			TComplexEditor test;
			test.addDigit(1);
			Assert::AreEqual(test.getNumber(), to_string(1.0) + "+i*" + to_string(0.0));
		}
		TEST_METHOD(ChangeSIGN1)
		{
			TComplexEditor test;
			test.setNumber(to_string(1));
			Assert::AreEqual(test.changeSign(), to_string(-1.0) + "+i*" + to_string(0.0));
			Assert::AreEqual(test.changeSign(), to_string(1.0) + "+i*" + to_string(0.0));
		}
		
		TEST_METHOD(ChangeSIGN0)
		{
			TComplexEditor test;
			test.setNumber("0");
			Assert::AreEqual(test.changeSign(), to_string(0.0) + "+i*" + to_string(0.0));
			Assert::AreEqual(test.changeSign(), to_string(0.0) + "+i*" + to_string(0.0));
		}
		TEST_METHOD(AddZeroAndAddSplit)
		{
			TComplexEditor test;
			test.addDigit(1);
			test.addZero();
			Assert::AreEqual(test.getNumber(), to_string(10.0) + "+i*" + to_string(0.0));
			test.addSplit();
			test.addZero();
			test.addDigit(2);
			Assert::AreEqual(test.getNumber(), to_string(10.0) + "+i*" + to_string(2.0));
		}
		TEST_METHOD(BackSpace)
		{
			TComplexEditor test;
			test.addDigit(5);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (string)"0");
		}
		TEST_METHOD(Clear)
		{
			TComplexEditor test;
			test.addDigit(1);
			test.addDigit(2);
			test.changeSign();
			Assert::AreEqual(test.clear(), (string)"0");
		}
		TEST_METHOD(GetNumber)
		{
			TComplexEditor test;
			string number = "2";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), to_string(2.0) + "+i*" + to_string(0.0));
		}

	};
}