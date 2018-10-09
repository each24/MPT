#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab2/TComplex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TComplex a(1.0, -1.1);
			Assert::AreEqual(a.getReal(), float(1.0));
			Assert::AreEqual(a.getMnim(), float(-1.1));
		}
		TEST_METHOD(TestMethod2)
		{
			TComplex a(1.0, 1.1);
			Assert::AreEqual(a.getReal(), float(1.0));
			Assert::AreEqual(a.getMnim(), float(1.1));
		}
		TEST_METHOD(TestMethod3)
		{
			TComplex a(1.0, 2.2);
			TComplex b = a.Add(a);
			Assert::AreEqual(b.getReal(), float(2.0));
			Assert::AreEqual(b.getMnim(), float(4.4));
		}
		TEST_METHOD(TestMethod4)
		{
			TComplex a(1.0, 3.0);
			TComplex b = a.copy();
			Assert::AreEqual(b.getReal(), float(1.0));
			Assert::AreEqual(b.getMnim(), float(3.0));
		}
		TEST_METHOD(TestMethod5)
		{
			TComplex a(3.0, 3.0);
			TComplex b = a.multiplie(a);
			Assert::AreEqual(b.getReal(), float(0.0));
			Assert::AreEqual(b.getMnim(), float(18.0));
		}
		TEST_METHOD(TestMethod6)
		{
			TComplex a(1.0, 3.0);
			TComplex b = a.minus();
			Assert::AreEqual(b.getReal(), float(-1.0));
			Assert::AreEqual(b.getMnim(), float(3.0));
		}
		TEST_METHOD(TestMethod7)
		{
			TComplex a(1.0, 3.0);
			TComplex b = a.minus();
			a = a.multiplie(b);
			Assert::AreEqual(a.getReal(), float(-10.0));
			Assert::AreEqual(a.getMnim(), float(0.0));
		}
		TEST_METHOD(TestMethod8)
		{
			TComplex a(1.0, 3.0);
			TComplex b(2.0, 6.0);
			a = a.cut(b);
			Assert::AreEqual(a.getReal(), float(0.5));
			Assert::AreEqual(a.getMnim(), float(0));
		}
		TEST_METHOD(TestMethod9)
		{
			TComplex a(1.0, 3.0);
			a = a.squer();
			Assert::AreEqual(a.getReal(), float(-8));
			Assert::AreEqual(a.getMnim(), float(6));
		}
		TEST_METHOD(TestMethod10)
		{
			TComplex a(-1.0, 3.0);
			a = a.squer();
			Assert::AreEqual(a.getReal(), float(-8));
			Assert::AreEqual(a.getMnim(), float(-6));
		}
		TEST_METHOD(TestMethod11)
		{
			TComplex a(1.0, 3.0);
			a = a.obratnoe();
			Assert::AreEqual(a.getReal(), float(0.1));
			Assert::AreEqual(a.getMnim(), float(-0.3));
		}
		TEST_METHOD(TestMethod12)
		{
			TComplex a(-1.0, 3.0);
			a = a.obratnoe();
			Assert::AreEqual(a.getReal(), float(-0.1));
			Assert::AreEqual(a.getMnim(), float(-0.3));
		}
		TEST_METHOD(TestMethod13)
		{
			TComplex a(1.0, 1.0);
			float b = a.ugolG();
			Assert::AreEqual(b, float(45));
			//Assert::AreEqual(int(a.getMnim()), -6);
		}
		TEST_METHOD(TestMethod14)
		{
			// TODO: Разместите здесь код своего теста
			TComplex a(1.0, 1.0);
			float b = a.ugolR();
			Assert::AreEqual(b, float(Pi/4));
		}
		TEST_METHOD(TestMethod15)
		{
			// TODO: Разместите здесь код своего теста
			TComplex a(1.0, 3.0);
			a = a.Step(2);
			Assert::AreEqual(a.getReal(), float(-8), float(0.01));
			Assert::AreEqual(a.getMnim(), float(6), float(0.01));
		}

	};
}