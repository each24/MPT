#include "stdafx.h"
#include "CppUnitTest.h"
#include "../EditTPNum/EditTPNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TesrEditTPNum
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			TPNumberEditor test;
			Assert::AreEqual(test.getNumber(), (string)"0");
		}

		TEST_METHOD(TestIsZero)
		{
			TPNumberEditor test;
			Assert::AreEqual(test.isZero(), true);
			test.addDigit(5);
			Assert::AreEqual(test.isZero(), false);
		}
		TEST_METHOD(ChangeSIGN)
		{
			TPNumberEditor test;
			test.addDigit(5);
			Assert::AreEqual(test.changeSign(), (string)"-5");
			Assert::AreEqual(test.changeSign(), (string)"5");
		}
		TEST_METHOD(AddDigit)
		{
			TPNumberEditor test;
			test.addDigit(5);
			Assert::AreEqual(test.getNumber(), (string)"5");
		}
		TEST_METHOD(AddZeroAndAddSplit)
		{
			TPNumberEditor test;
			test.addDigit(5);
			test.addZero();
			Assert::AreEqual(test.getNumber(), (string)"50");
			test.addSplit();
			test.addZero();
			test.addDigit(1);
			Assert::AreEqual(test.getNumber(), (string)"50.0");
		}
		TEST_METHOD(BackSpace)
		{
			TPNumberEditor test;
			test.addDigit(5);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (std::string)"0");
		}
		TEST_METHOD(Clear)
		{
			TPNumberEditor test;
			test.addDigit(5);
			test.addDigit(6);
			test.changeSign();
			Assert::AreEqual(test.clear(), (std::string)"0");
		}
		TEST_METHOD(WriteString)
		{
			TPNumberEditor test;
			string number = "42";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), number);
		}

	};
}