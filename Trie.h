#ifndef TRIE_H
#define TRIE_H
#include <string>

template <typename T>
class TrieNode
{
public:
	TrieNode();
	TrieNode(T value);
	bool insert();
	bool replace();
	bool set();
	int size();
	T get(const std::string& key);

private:
	T* m_val;
	TrieNode* m_next[26];
	int count;
};
#endif
