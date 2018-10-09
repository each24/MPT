#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test24)
		{
			Drobi a(3, 5);
			Assert::AreEqual((-a).getChislitel(), -3);
			Assert::AreEqual((-a).getZnamenatel(), 5);
		}
		TEST_METHOD(Test0)
		{
			Drobi a(2);
			Assert::AreEqual(a.getChislitel(), 2);
			Assert::AreEqual(a.getZnamenatel(), 1);
		}
		TEST_METHOD(Test1)
		{
			// TODO: Разместите здесь код своего теста
			Drobi a(1, 1);
			Assert::AreEqual(a.getChislitel(), 1);
			Assert::AreEqual(a.getZnamenatel(), 1);
		}
		TEST_METHOD(Test2)
		{
			Drobi a(0, -1);
			Assert::AreEqual(a.getChislitel(), 0);
			Assert::AreEqual(a.getZnamenatel(), 1);
		}
		TEST_METHOD(Test3)
		{
			Drobi a(1, 2);
			Drobi b = a.Add(a);
			Assert::AreEqual(b.getChislitel(), 1);
			Assert::AreEqual(b.getZnamenatel(), 1);
		}
		TEST_METHOD(Test4)
		{
			Drobi a(1, 3);
			Drobi b = a.copy();
			Assert::AreEqual(b.getChislitel(), 1);
			Assert::AreEqual(b.getZnamenatel(), 3);
		}
		TEST_METHOD(Test5)
		{
			Drobi a(1, 3);
			Drobi b = a.multiplie(a);
			Assert::AreEqual(b.getChislitel(), 1);
			Assert::AreEqual(b.getZnamenatel(), 9);
		}
		TEST_METHOD(Test6)
		{
			Drobi a(2, 3);
			Drobi b = a.multiplie(a);
			Assert::AreEqual(b.getChislitel(), 4);
			Assert::AreEqual(b.getZnamenatel(), 9);
		}
		TEST_METHOD(Test7)
		{
			Drobi a(2, 3);
			Drobi c(3, 2);
			Drobi b = a.multiplie(c);
			Assert::AreEqual(b.getChislitel(), 1);
			Assert::AreEqual(b.getZnamenatel(), 1);
		}
		TEST_METHOD(Test8)
		{
			Drobi a(-2, 3);
			Drobi c(3, 2);
			Drobi b = a.multiplie(c);
			Assert::AreEqual(b.getChislitel(), -1);
			Assert::AreEqual(b.getZnamenatel(), 1);
		}
		TEST_METHOD(Test9)
		{
			Drobi a(2, 3);
			Drobi c(3, 2);
			Drobi b = a.cut(a);
			Assert::AreEqual(b.getChislitel(), 1);
			Assert::AreEqual(b.getZnamenatel(), 1);
		}
		TEST_METHOD(Test10)
		{
			Drobi a(2, 3);
			Drobi c(1, 2);
			Drobi b = a.cut(c);
			Assert::AreEqual(b.getChislitel(), 4);
			Assert::AreEqual(b.getZnamenatel(), 3);
		}
		TEST_METHOD(Test11)
		{
			Drobi a(2, 3);
			Drobi c(1, 2);
			Drobi b = a.minus(c);
			Assert::AreEqual(b.getChislitel(), 1);
			Assert::AreEqual(b.getZnamenatel(), 6);
		}
		TEST_METHOD(Test12)
		{
			Drobi a(3, 5);
			Drobi c(-2, 3);
			Drobi b = a.minus(c);
			Assert::AreEqual(b.getChislitel(), 19);
			Assert::AreEqual(b.getZnamenatel(), 15);
		}
		TEST_METHOD(Test13)
		{
			Drobi a(3, 5);
			Drobi b = a.obratnoe();
			Assert::AreEqual(b.getChislitel(), 5);
			Assert::AreEqual(b.getZnamenatel(), 3);
		}
		TEST_METHOD(Test14)
		{
			Drobi a(-3, 5);
			Drobi b = a.obratnoe();
			Assert::AreEqual(b.getChislitel(), -5);
			Assert::AreEqual(b.getZnamenatel(), 3);
		}
		TEST_METHOD(Test15)
		{
			Drobi a(8, 9);
			Drobi b = a.squer();
			Assert::AreEqual(b.getChislitel(), 64);
			Assert::AreEqual(b.getZnamenatel(), 81);
		}
		TEST_METHOD(Test16)
		{
			Drobi a(-3, 5);
			Drobi b = a.squer();
			Assert::AreEqual(b.getChislitel(), 9);
			Assert::AreEqual(b.getZnamenatel(), 25);
		}
		TEST_METHOD(Test17)
		{
			Drobi a(3, 5);
			string b = a.strChislitel();
			string c = "3";
			Assert::AreEqual(c, b);
		}
		TEST_METHOD(Test18)
		{
			Drobi a(-3, 5);
			string b = a.strChislitel();
			string c = "-3";
			Assert::AreEqual(c, b);
		}
		TEST_METHOD(Test19)
		{
			Drobi a(-3, 5);
			string b = a.strZnamenatel();
			string c = "5";
			Assert::AreEqual(c, b);
		}
		TEST_METHOD(Test20)
		{
			Drobi a(3, 5);
			string b = a.strZnamenatel();
			string c = "5";
			Assert::AreEqual(c, b);
		}
		TEST_METHOD(Test21)
		{
			Drobi a(3, 5);
			string b = a.str();
			string c = "3 / 5";
			Assert::AreEqual(c, b);
		}
		TEST_METHOD(Test22)
		{
			Drobi a(-3, 5);
			string b = a.str();
			string c = "-3 / 5";
			Assert::AreEqual(c, b);
		}
		TEST_METHOD(Test23)
		{
			Drobi a(3, 5);
			Assert::AreEqual(true, a.more(-a));
		}
		TEST_METHOD(Test25)
		{
			Drobi a(1000, 1001);
			Drobi b(1001, 1002);
			Assert::AreEqual(true, b.more(a));
		}
	};
}