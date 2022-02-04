#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack& s);
	Stack& operator= (const Stack& other);
	~Stack();

	void push(const T& elem);
	T top();
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