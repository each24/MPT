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
			test.setNumber("7");
			Assert::AreEqual(test.isZero(), false);
		}
		
		TEST_METHOD(AddDigit)
		{
			TFracEdit test;
			test.setNumber("5");
			Assert::AreEqual(test.addDigit(5), (std::string)"5/15");
		}

		TEST_METHOD(ChangeSign1)
		{
			TFracEdit test;
			test.setNumber("1");
			Assert::AreEqual(test.changeSign(), (std::string)"-1/1");
			Assert::AreEqual(test.changeSign(), (std::string)"1/1");
		}

		TEST_METHOD(ChangeSign0)
		{
			TFracEdit test;
			test.setNumber("0");
			Assert::AreEqual(test.changeSign(), (std::string)"0/1");
			Assert::AreEqual(test.changeSign(), (std::string)"0/1");
		}

		TEST_METHOD(AddSplit)
		{
			TFracEdit test;
			test.addDigit(5);
			test.addZero();
			Assert::AreEqual(test.getNumber(), (std::string)"50/1");
			Assert::AreEqual(test.addSplit(), (std::string)"50/"); ;
			test.addDigit(2);
			Assert::AreEqual(test.getNumber(), (std::string)"50/2");
		}

		TEST_METHOD(AddZero)
		{
			TFracEdit test;
			test.addDigit(1);
			test.addZero();
			Assert::AreEqual(test.getNumber(), (std::string)"10/1");
		}

		TEST_METHOD(BackSpaceOne)
		{
			TFracEdit test;
			test.addDigit(5);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (std::string)"0");
		}

		TEST_METHOD(BackSpaceMulti)
		{
			TFracEdit test;
			for (int i = 0; i < 4; ++i)
				test.addDigit(5);
			test.changeSign();
			std::string a = "-555";
			for(int i = 0; i < 3; ++i, a.pop_back())
				Assert::AreEqual(test.backspace(), a);
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

		TEST_METHOD(SetNumber0)
		{
			TFracEdit test;
			std::string number = "3/1";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), (std::string)"3/1");
		}

		TEST_METHOD(SetNumber1)
		{
			TFracEdit test;
			std::string number = "-3/1";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), (std::string)"-3/1");
		}
	};
}