#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(StackTest)
	{
	public:
		TEST_METHOD(IntStack)
		{
			Logger::WriteMessage("Test Stack<int>\n");
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
			Stack<int> p_stack = t_stack;
			for (int i = 9; i >= 0; i--) {
				Assert::AreEqual(p_stack.top(), list[i]);
				p_stack.pop();
			}
			p_stack = t_stack;
			Assert::IsFalse(p_stack.empty());
			for (int i = 9; i >= 0; i--) {
				Assert::AreEqual(p_stack.top(), list[i]);
				p_stack.pop();
			}
			Assert::IsTrue(p_stack.empty());
			t_stack.clear();
			Assert::IsTrue(t_stack.empty());
			Logger::WriteMessage("Stack<int> tests passed");
		}

		TEST_METHOD(StringStack)
		{
			Logger::WriteMessage("Test Stack<string>\n");
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
			Logger::WriteMessage("Stack<string> tests passed");
		}
	};
	TEST_CLASS(TrieTest)
	{
	public:
		TEST_METHOD(FloatTrie)
		{
			Logger::WriteMessage("Test TrieNode<float>\n");
			TrieNode<float> t(34);
			Assert::IsTrue(t.insert("hello", 24.f));
			Assert::IsFalse(t.insert("he%%%llo", 21.f));
			float v;
			Assert::IsTrue(t.get("hello", v) && v == 24.f);
			Assert::IsFalse(t.get("haa!e llo", v));
			Assert::AreEqual(v, 24.f);
			Assert::IsTrue(t.insert("hello", 22.f));
			Assert::IsTrue(t.insert("world", 6.2f));
			Assert::IsTrue(t.insert("food", 10.f));
			Assert::IsTrue(t.insert("foo", 1.3f));
			Assert::IsTrue(t.get("hello", v) && v == 22.f);
			Assert::IsTrue(t.get("foo", v) && v == 1.3f);
			Assert::IsTrue(t.get("food", v) && v == 10.f);
			t.erase("hello");
			Assert::IsFalse(t.get("hello", v));
			Logger::WriteMessage("TrieNode<float> tests passed");
		}
	};
}
