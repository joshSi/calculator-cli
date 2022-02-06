#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack& s);
	Stack& operator= (const Stack& s);
	~Stack();

	void push(const T& elem);

	// Assumes not empty, otherwise undefined behavior
	T top();
	// Assumes not empty, otherwise undefined behavior
	void pop();

	bool empty();
	void clear();
private:
	struct Node {
		T val;
		Node* prev = nullptr;
		Node* next = nullptr;
	};

	Node* m_top = nullptr;
};

#endif