#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "../Lab3/TPNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TPNumber A(10, 2, 3);
			Assert::AreEqual(10.0, A.getA());
			Assert::AreEqual(2, A.getB());
			Assert::AreEqual(3, A.getC());
		}
		TEST_METHOD(TestMethod2)
		{
			TPNumber A(-10, 2, 3);
			Assert::AreEqual(-10.0, A.getA());
			Assert::AreEqual(2, A.getB());
			Assert::AreEqual(3, A.getC());
		}
		TEST_METHOD(TestMethod3)
		{
			TPNumber A("10", "2", "3");
			Assert::AreEqual(10.0, A.getA());
			Assert::AreEqual(2, A.getB());
			Assert::AreEqual(3, A.getC());
		}
		TEST_METHOD(TestMethod4)
		{
			TPNumber A("-10", "2", "3");
			Assert::AreEqual(-10.0, A.getA());
			Assert::AreEqual(2, A.getB());
			Assert::AreEqual(3, A.getC());
		}
		TEST_METHOD(TestMethod5)
		{
			//TPNumber A("-10", "1", "3");
			string str;
			exception e;
			try {
				TPNumber A("-10", "1", "3");
			}
			catch (exception e) {
				str = string(e.what());
				return;
			}
			Assert::Fail();
			//Assert::ExpectException(TPNumber A("-10", "1", "3"),"error","");
			//Assert::AreEqual(str, string("error"));
			//Assert::AreEqual(-10.0, A.getA());
			//Assert::AreEqual(1, A.getB());
			//Assert::AreEqual(3, A.getC());
		}
		TEST_METHOD(TestMethod6)
		{
			TPNumber A("-10", "2", "3");
			TPNumber B(4, 2, 3);
			A = A.minus(B);
			Assert::AreEqual(A.getA(), -14.0);
			Assert::AreEqual(A.getB(), B.getB());
			Assert::AreEqual(A.getC(), B.getC());
			//Assert::ExpectException(TPNumber A("-10", "1", "3"), "error", "");
			//Assert::AreEqual(-10.0, A.getA());
			//Assert::AreEqual(1, A.getB());
			//Assert::AreEqual(3, A.getC());
		}
		TEST_METHOD(TestMethod7)
		{
			TPNumber A("-10", "2", "3");
			TPNumber B(4, 2, 3);
			A = A.Add(B);
			Assert::AreEqual(A.getA(), -6.0);
			Assert::AreEqual(A.getB(), 2);
			Assert::AreEqual(A.getC(), 3);
		}
		TEST_METHOD(TestMethod8)
		{
			string str;
			TPNumber A("-10", "2", "3");
			TPNumber B(4, 2, 5);
			try {
				A.Add(B);
			}
			catch (exception e) {
				str = string(e.what());
				Assert::AreEqual(str, string("not addable"));
				return;
			}
			try {
				B.Add(A);
			}
			catch (exception e) {
				str = string(e.what());
				Assert::AreEqual(str, string("not addable"));
				return;
			}
			//Assert::AreEqual(A.getA(), B.getA());
			//Assert::AreEqual(A.getB(), B.getB());
			//Assert::AreEqual(A.getC(), B.getC());
		}
		TEST_METHOD(TestMethod9)
		{
			TPNumber A("-10", "2", "3");
			TPNumber B(2, 2, 3);
			A = A.cut(B);
			Assert::AreEqual(A.getA(), -5.0);
			Assert::AreEqual(A.getB(), 2);
			Assert::AreEqual(A.getC(), 3);
		}
		TEST_METHOD(TestMethod10)
		{
			TPNumber A("-10", "2", "3");
			TPNumber B(2, 2, 3);
			A = A.multiplie(B);
			Assert::AreEqual(A.getA(), -20.0);
			Assert::AreEqual(A.getB(), 2);
			Assert::AreEqual(A.getC(), 3);
		}
		TEST_METHOD(TestMethod11)
		{
			string str;
			TPNumber A("-10", "3", "3");
			TPNumber B(2, 2, 3);
			try {
				A.multiplie(B);
			}
			catch (exception e) {
				str = string(e.what());
				Assert::AreEqual(str, string("not addable"));
				return;
			}
			Assert::Fail();
		}
		TEST_METHOD(TestMethod12)
		{
			TPNumber A("-10", "2", "3");
			TPNumber B(2, 2, 3);
			A = A.obratnoe();
			Assert::AreEqual(A.getA(), -0.1);
			Assert::AreEqual(A.getB(), 2);
			Assert::AreEqual(A.getC(), 3);
		}
		TEST_METHOD(TestMethod13)
		{
			TPNumber A("0.1", "2", "3");
			TPNumber B(2, 2, 3);
			A = A.obratnoe();
			Assert::AreEqual(A.getA(), 10.0);
			Assert::AreEqual(A.getB(), 2);
			Assert::AreEqual(A.getC(), 3);
		}
		TEST_METHOD(TestMethod14)
		{
			TPNumber A("-10", "2", "3");
			TPNumber B(10,2);
			B = A.copy();
			Assert::AreEqual(A.getA(), B.getA());
			Assert::AreEqual(A.getB(), B.getB());
			Assert::AreEqual(A.getC(), B.getC());
		}
		TEST_METHOD(TestMethod15)
		{
			TPNumber A("-10", "2", "3");
			A = A.squer();
			Assert::AreEqual(A.getA(), 100.0);
			Assert::AreEqual(A.getB(), A.getB());
			Assert::AreEqual(A.getC(), A.getC());
		}
		TEST_METHOD(TestMethod16)
		{
			string str = "-1 0 1 0 ";
			TPNumber A("-10", "2", "3");
			Assert::AreEqual(A.strN(), str);
		}
		TEST_METHOD(TestMethod17)
		{
			string str = "1 0 1 0 ";
			TPNumber A("10", "2", "3");
			Assert::AreEqual(A.strN(), str);
		}
		TEST_METHOD(TestMethod18)
		{
			string str = "-A ";
			TPNumber A("-10", "16", "3");
			Assert::AreEqual(A.strN(), str);
		}
		TEST_METHOD(TestMethod19)
		{
			TPNumber A("-10", "2", "3");
			A = A.squer();
			Assert::AreEqual(A.getA(), 100.0);
			Assert::AreEqual(A.getB(), A.getB());
			Assert::AreEqual(A.getC(), A.getC());
		}
	};
}