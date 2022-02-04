#include "pch.h"
#include "CppUnitTest.h"
#include "../Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Stack<int> t_stack;
			Assert::IsTrue(t_stack.empty());
		}
	};
}
