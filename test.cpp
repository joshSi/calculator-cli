#include "Stack.h"
#include <iostream>

void test_stack() {
	Stack<int> s;
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (auto i : list) {
		s.push(i);
	}

	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

int main() {
	test_stack();
	return 0;
}