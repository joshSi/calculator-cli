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

template <typename T>
Stack<T>::Stack() {}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
	Node* i = s.m_top;
	if (i != nullptr) {
		m_top = new Node({ i->val, nullptr, nullptr });
		i = i->prev;
	}

	Node* j = m_top;
	Node* k;
	while (i != nullptr) {
		k = new Node({ i->val, nullptr, j });
		j->prev = k;
		i = i->prev;
		j = k;
	}
}

template <typename T>
Stack<T>& Stack<T>::operator= (const Stack<T>& s) {
	clear();
	Node* i = s.m_top;
	if (i != nullptr) {
		m_top = new Node({ i->val, nullptr, nullptr });
		i = i->prev;
	}

	Node* j = m_top;
	Node* k;
	while (i != nullptr) {
		k = new Node({ i->val, nullptr, j });
		j->prev = k;
		i = i->prev;
		j = k;
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack() {
	if (m_top != nullptr) {
		while (m_top->prev != nullptr) {
			m_top = m_top->prev;
			delete m_top->next;
		}
		delete m_top;
	}
}

template <typename T>
void Stack<T>::push(const T& elem) {
	if (m_top == nullptr) {
		m_top = new Node({ elem });
	}
	else {
		m_top->next = new Node({ elem, m_top, nullptr });
		m_top = m_top->next;
	}
}

template <typename T>
T Stack<T>::top() {
	return m_top->val;
}

template <typename T>
void Stack<T>::pop() {
	Node* prevptr = m_top->prev;
	delete m_top;
	m_top = prevptr;
}

template <typename T>
bool Stack<T>::empty() {
	return (m_top == nullptr);
}

template <typename T>
void Stack<T>::clear() {
	if (m_top == nullptr)
		return;
	while (m_top->prev != nullptr) {
		m_top = m_top->prev;
		delete m_top->next;
	}
	delete m_top;
	m_top = nullptr;
}

#endif