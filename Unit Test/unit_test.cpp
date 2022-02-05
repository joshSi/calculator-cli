#include "pch.h"
#include "CppUnitTest.h"
#include "../Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestStack)
		{
			Logger::WriteMessage("Test stack class");
			Stack<int> t_stack;
			Assert::IsTrue(t_stack.empty());

			int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

			for (int i = 0; i < 10; i++) {
				t_stack.push(list[i]);
				Assert::AreEqual(t_stack.top(), list[i]);
			}

			for (int i = 9; i >= 0; i--) {
				Assert::AreEqual(t_stack.top(), list[i]);
				t_stack.pop();
			}

			for (int i = 0; i < 10; i++) {
				t_stack.push(list[i]);
			}
			Assert::IsFalse(t_stack.empty());
			t_stack.clear();
			Assert::IsTrue(t_stack.empty());
			Logger::WriteMessage("All test passed");
		}
	};
}
