#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class List
{
private:
	Node* head;
	Node* last;

public:
	List();
	bool IsEmpty();
	Node* set_head() {
		return head;
	};
	void push_back(Node* new_Elem);
	void push_back_string(string new_Elem, int first_action);
	void print_to_console();
	void clear();
	~List();
};

