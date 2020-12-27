#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	Node* next = nullptr;
	string data;
	size_t size;
	int first_action = -1;

	Node(string data, int first_action = -1, Node* next = nullptr) {
		this->data = data;
		this->first_action = first_action;
		this->next = next;
	};
	~Node() {};
};
