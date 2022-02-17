#ifndef TRIE_H
#define TRIE_H
#include <string>

template <typename T>
class TrieNode
{
public:
	TrieNode();
	TrieNode(T value);
	~TrieNode();
	bool insert(const std::string& key, T val);
	void erase(const std::string& key);
	T get(const std::string& key) const;

private:
	T* t_val;
	TrieNode* t_next[26];
	short alpha_int(char a) const;
};

template<class T>
TrieNode<T>::TrieNode() : t_val(nullptr), t_next() {
}

template<class T>
TrieNode<T>::TrieNode(T val) : t_next() {
	t_val = new T(val);
}

template<class T>
TrieNode<T>::~TrieNode() {
	delete t_val;
	for (int i = 0; i < 26; i++) {
		delete t_next[i];
	}
}

template<class T>
bool TrieNode<T>::insert(const std::string& key, T val) {
	if (key.empty()) {
		if (t_val == nullptr) {
			t_val = new T(val);
		}
		else {
			*t_val = val;
		}
		return true;
	}
	int idx = alpha_int(key[0]);
	if (idx == -1)
		return false;
	if (t_next[idx])
		return t_next[idx]->insert(key.substr(1), val);
	t_next[idx] = new TrieNode();
	return t_next[idx]->insert(key.substr(1), val);
}

template<class T>
T TrieNode<T>::get(const std::string& key) const {
	if (key.empty())
		return *t_val;
	TrieNode* ptr = t_next[alpha_int(key[0])];
	if (ptr)
		return ptr->get(key.substr(1));
	else
		return false;
}

template<class T>
void TrieNode<T>::erase(const std::string& key) {
	if (key.empty())
		delete t_val;
	else {
		if (alpha_int(key[0]) == -1)
			return;
		TrieNode* ptr = t_next[alpha_int(key[0])];
		if (ptr)
			ptr->erase(key.substr(1));
	}
}

template<class T>
short TrieNode<T>::alpha_int(char a) const {
	switch (a) {
	case 'a':
		return 0;
	case 'b':
		return 1;
	case 'c':
		return 2;
	case 'd':
		return 3;
	case 'e':
		return 4;
	case 'f':
		return 5;
	case 'g':
		return 6;
	case 'h':
		return 7;
	case 'i':
		return 8;
	case 'j':
		return 9;
	case 'k':
		return 10;
	case 'l':
		return 11;
	case 'm':
		return 12;
	case 'n':
		return 13;
	case 'o':
		return 14;
	case 'p':
		return 15;
	case 'q':
		return 16;
	case 'r':
		return 17;
	case 's':
		return 18;
	case 't':
		return 19;
	case 'u':
		return 20;
	case 'v':
		return 21;
	case 'w':
		return 22;
	case 'x':
		return 23;
	case 'y':
		return 24;
	case 'z':
		return 25;
	default:
		return -1;
	}
}

#endif