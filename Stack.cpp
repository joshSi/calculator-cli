#include "Stack.h"

template <class T>
Stack<T>::Stack() {}

template <class T>
Stack<T>::Stack(const Stack<T>& s) {

}

template <class T>
Stack<T>& Stack<T>::operator= (const Stack<T>& other) {
	Node* i = other.m_top;
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

template <class T>
Stack<T>::~Stack() {
	if (m_top != nullptr) {
		while (m_top->prev != nullptr) {
			m_top = m_top->prev;
			delete m_top->next;
		}
		delete m_top;
	}
}

template <class T>
void Stack<T>::push(const T& elem) {
	if (m_top == nullptr) {
		m_top = new Node({ elem });
	}
	else {
		m_top->next = new Node({ elem, m_top, nullptr });
		m_top = m_top->next;
	}
}

template <class T>
T Stack<T>::top() {
	if (m_top == nullptr)
		throw "Calling top() on empty Stack";
	return m_top->val;
}

template <class T>
void Stack<T>::pop() {
	if (m_top == nullptr)
		throw "Calling pop() on empty Stack";
	Node* prevptr = m_top->prev;
	delete m_top;
	m_top = prevptr;
}

template <class T>
bool Stack<T>::empty() {
	return (m_top == nullptr);
}

template <class T>
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

template class Stack<int>;