#pragma once
#include "List.h"

class Stack {
private:
	class Node_S {
	public:
		Node_S(Node* elem = nullptr, Node_S* next = nullptr) {
			this->elem = elem;
			this->next = next;
		};

		Node_S(string data = "__", int first_action = -1, Node_S* next = nullptr) {
			this->elem = new Node(data, first_action, nullptr);
			this->next = next;
		};

		~Node_S() {};
		Node* elem;
		Node_S* next;
	};
	Node_S* first_S;
	Node_S* last_S;
public:
	Stack();
	bool IsEmpty();
	void push(Node*);
	void push_string(string data, int first_action);
	void push_char(char new_elem, int first_action);
	Node* pop();
	Node* front();
	~Stack();
};
