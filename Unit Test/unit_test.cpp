#include "pch.h"
#include "CppUnitTest.h"
#include "../Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(StackTest)
	{
	public:
		TEST_METHOD(IntStack)
		{
			Logger::WriteMessage("Test stack<int>");
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

		TEST_METHOD(StringStack)
		{
			Logger::WriteMessage("Test stack<string>");
			Stack<std::string> t_stack;
			Assert::IsTrue(t_stack.empty());

			std::string list[10] = {"one", "two", "three", "four","five",
				"six", "seven", "eight", "nine", "ten"};

			for (int i = 0; i < 10; i++) {
				t_stack.push(list[i]);
				Assert::AreEqual(t_stack.top(), list[i]);
			}

			Assert::AreEqual(t_stack.top().c_str(), "ten");

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
