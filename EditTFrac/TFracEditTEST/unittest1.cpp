#include "stdafx.h"
#include <assert.h>
#include "../EditTFrac/TFracEdit.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TFracEditTEST
{		
	TEST_CLASS(TFracEditTEST)
	{
	public:
		TEST_METHOD(Constructor)
		{
			TFracEdit test;
			Assert::AreEqual(test.getNumber(), (std::string)"0/1");
		}

		TEST_METHOD(IsZero)
		{
			TFracEdit test;
			Assert::AreEqual(test.isZero(), true);
			test.addDigit(5);
			Assert::AreEqual(test.isZero(), false);
		}

		TEST_METHOD(AddSignAndAddDigit)
		{
			TFracEdit test;
			test.addDigit(5);
			Assert::AreEqual(test.changeSign(), (std::string)"-5");
			Assert::AreEqual(test.changeSign(), (std::string)"5");
		}

		TEST_METHOD(AddSplit)
		{
			TFracEdit test;
			test.addDigit(5);
			test.addZero();
			Assert::AreEqual(test.getNumber(), (std::string)"50/1");
			test.addSplit();
			test.addZero();
			test.addDigit(2);
			Assert::AreEqual(test.getNumber(), (std::string)"50/2");
		}

		TEST_METHOD(AddZeroAndAddSplit)
		{
			TFracEdit test;
			test.addDigit(5);
			test.addZero();
			Assert::AreEqual(test.getNumber(), (std::string)"50/1");
			test.addSplit();
			test.addZero();
			test.addDigit(2);
			Assert::AreEqual(test.getNumber(), (std::string)"50/2");
		}

		TEST_METHOD(BackSpace)
		{
			TFracEdit test;
			test.addDigit(5);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (std::string)"0");
		}

		TEST_METHOD(Clear)
		{
			TFracEdit test;
			test.addDigit(5);
			test.addDigit(6);
			test.changeSign();
			Assert::AreEqual(test.clear(), (std::string)"0");
		}

		TEST_METHOD(WriteString)
		{
			TFracEdit test;
			std::string number = "3/1";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), (std::string)"3/1");
		}


	};
}