#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab4/TMemory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TMemoryTest
{
	TEST_CLASS(UnitTest1) {
	public:
		TEST_METHOD(TMemoryAndGetters) {
			TMemory<int> test = TMemory<int>();
			Assert::IsTrue(!test.getState());
			Assert::IsTrue(test.getFNumber() == int());
		}
		TEST_METHOD(Write) {
			TMemory<int> test = TMemory<int>();
			test.write(-10);
			Assert::IsTrue(test.getState());
			Assert::AreEqual(test.get(), -10);
		}
		TEST_METHOD(Add) {
			TMemory<int> test = TMemory<int>();
			test.write(10);
			test.add(-10);
			Assert::IsTrue(test.getState());
			Assert::AreEqual(test.get(), 0);
		}
		TEST_METHOD(ReadMemoryState) {
			TMemory<int> test = TMemory<int>();
			Assert::IsTrue(std::string("_Off") == test.readMemoryState());
			test.write(3);
			Assert::IsTrue(std::string("_On") == test.readMemoryState());
		}
		TEST_METHOD(Clear) {
			TMemory<int> test = TMemory<int>();
			test.write(3);
			Assert::IsTrue(test.getState());
			test.clear();
			Assert::IsTrue(!test.getState());
		}
	};
}