#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
public:
	void push(T elem);
	int top();
	void pop();
	bool empty();
	bool clear();
private:
	struct Node {
		T val;
		Node* next;
	};

	Node* m_top = nullptr;
	Node* m_fst = nullptr;
};

#endif