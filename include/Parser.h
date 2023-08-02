#ifndef PARSER_H
#define PARSER_H
#include <string>

int cardinality(const char& i);

bool to_postfix(const std::string& infix, std::string& postfix);

class Parser
{
	bool parse(const std::string& infix);
private:
	struct Node {
		char* token;
		Node* next = nullptr;
	};

	// postfix char[] queue (implemeneted by Linked List)
	Node* postfix = nullptr;
	Node* endptr = nullptr;
};

#endif