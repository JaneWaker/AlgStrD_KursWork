#include "Stack.h"
#include <stdexcept>

Stack::Stack() {
	first_S = nullptr;
	last_S = nullptr;
}

bool Stack::IsEmpty() {
	return (first_S == nullptr);
}

void Stack::push(Node* new_elem) {
	first_S = new Node_S(new_elem, first_S);
}

void Stack::push_string(string data, int first_action) {
	first_S = new Node_S(data, first_action, first_S);
}

void Stack::push_char(char new_elem, int first_action) {
	string insert;
	insert.push_back(new_elem);
	first_S = new Node_S(insert, first_action, first_S);
}

Node* Stack::pop() {
	Node* a = first_S->elem;
	first_S = first_S->next;
	return a;
}

Node* Stack::front() {
	return first_S->elem;
}

Stack::~Stack() {
	while (!IsEmpty()) {
		pop();
	}
}