#include "Parser.h"
#include "Stack.h"
#include <iostream>

int cardinality(const char& i) {
	switch (i) {
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '<':
	case '>':
	case '=':
		return -1;
	default:
		return 0;
	}
}

bool to_postfix(const std::string& infix, std::string& postfix) {
	if (infix.size() == 0)
		return false;
	bool v_op = true;
	postfix.clear();
	Stack<char> operator_stack;
	for (int i = 0; i < infix.size(); i++) {
		if (isalpha(infix[i])) {
			postfix += tolower(infix[i++]);
			while (isalpha(infix[i])) {
				postfix += tolower(infix[i++]);
			}
			postfix += ' ';
			if (v_op == false)
				postfix += "* ";
			i--;
			v_op = false;
			continue;
		}
		if (isdigit(infix[i])) {
			postfix += infix[i++];
			while (isdigit(infix[i])) {
				postfix += infix[i++];
			}
			postfix += ' ';
			if (v_op == false)
				postfix += "* ";
			i--;
			v_op = false;
			continue;
		}
		switch (infix[i]) {
		case ' ':
			break;
		case '(':
			if (!v_op)
				return false;
			operator_stack.push('(');
			break;
		case ')':
			if (v_op)
				return false;
			while (!operator_stack.empty() && operator_stack.top() != '(') {
				postfix += operator_stack.top();
				postfix += ' ';
				operator_stack.pop();
			}
			if (operator_stack.empty())
				return false;
			operator_stack.pop();
			break;
		case '+':
		case '-':
		case '/':
		case '*':
			if (v_op)
				return false;
			v_op = true;
			while (!operator_stack.empty() && operator_stack.top() != '(') {
				char top = operator_stack.top();
				if (cardinality(top) < cardinality(infix[i]))
					break;
				postfix += top;
				postfix += ' ';
				operator_stack.pop();
			}
			operator_stack.push(infix[i]);
			break;
		default:		// Other characters; return false
			return false;
		}
	}

	while (!operator_stack.empty()) {
		postfix += operator_stack.top();
		postfix += ' ';
		if (operator_stack.top() == '(')
			return false;
		operator_stack.pop();
	}
	return true;
}
