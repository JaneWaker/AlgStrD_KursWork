#include "List.h"

List::List(){
	head = nullptr;
	last = nullptr;
}

bool List::IsEmpty() {
	return (head == nullptr);
}

void List::push_back(Node* new_Elem)
{
	if (!(IsEmpty())) {
		last->next = new_Elem;
		last = last->next;
	}
	else {
		head = new_Elem;
		head->next = nullptr;
		last = head;
	}
}

void List::push_back_string(string new_Elem, int first_action)
{
	if (!(IsEmpty())) {
		last->next = new Node(new_Elem, first_action);
		last = last->next;
	}
	else {
		head = new Node(new_Elem, first_action);
		last = head;
	}
}

void List::print_to_console() {
	Node* cur = head;
	while (cur != nullptr) {
		cout << cur->data << ' ';
		cur = cur->next;
	}
	cout << endl;
	cout << endl;
}


void List::clear() {
	Node* cur = head;
	while (!(this->IsEmpty())) {
		cur = head;
		head = cur->next;
		delete cur;
	}
	if (IsEmpty()) {
		throw out_of_range("List is empty");
	}
}

List::~List() {
	clear();
}