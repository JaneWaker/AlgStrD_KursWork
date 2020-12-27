#include "Postfix.h"
double pi = 3.14159265358979323846;
double e = 2.71828182845904523536;

Postfix::Postfix() {
	Stack_elem = new Stack();
	List_postfix = new List();
}

bool Postfix::Number(char Symbol) {
	int i = 0;
	string Numbers = { 
		"1234567890.," 
	};
	for (char CurNumber : Numbers) {
		if (CurNumber == Symbol) {
			return true;
		}

	}
	return false;
}

bool Postfix::Function(char Symbol) {
	int i = 0;
	string Symbols = { 
		"abcdefghijklmnopqrstuvwxyz" 
	};
	for (char CurSymbol : Symbols) {
		if (CurSymbol == Symbol) {
			return true;
		}
	}
	return false;
}

int Postfix::WhichOperator(char Symbol) {
	if (Symbol == '(') {
		return left_brecket;
	}
	else {
		if (Symbol == ')') {
			return right_brecket;
		}
		else {
			if (Symbol == '+' || Symbol == '-') {
				return add_sub;
			}
			else {
				if (Symbol == '*' || Symbol == '/') {
					return multipl_division;
				}
				else {
					if (Symbol == '(') { 
						return left_brecket;
					}
					else {
						if (Symbol == ')') {
							return right_brecket;
						}
						else {
							if (Symbol == '^') {
								return degree;
							}
							else {
								return not_operator;
							}
						}
					}
				}
			}
		}
	}
}

double Postfix::Operator_last(char Symbol, double A1, double A2) {
	double Response = 0;
	switch (Symbol) {
		case '+': {
			Response = A1 + A2;
			break;
		}
		case '-': {
			Response = A1 - A2;
			break;
		}
		case '*': {
			Response = A1 * A2;
			break;
		}
		case '/': {
			Response = A1 / A2;
			break;
		}
		case '^': {
			Response = pow(A1, A2);
			break;
		}
	}
	return Response;
}

int Postfix::WhichFunction(string function) {
	if (function == "cos") {
		return Cos;
	}
	else {
		if (function == "sin") {
			return Sin;
		}
		else {
			if (function == "tg") {
				return Tg;
			}
			else {
				if (function == "ctg") {
					return Ctg;
				}
				else {
					if (function == "log") {
						return Log;
					}
					else {
						if (function == "ln") {
							return Ln;
						}
						else {
							if (function == "sqrt") {
								return Sqrt;
							}
							else {
								if (function == "abs") {
									return Abs;
								}
								else {
									if (function == "exp") {
										return Exp;
									}
									else {
										if (function == "pi") {
											return Pi;
										}
										else {
											if (function == "e") {
												return E;
											}
											else {
												return not_operator;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

double Postfix::Function_last(int Function, double Argument) {
	double Response = 0;
	switch (Function) {
	case Cos: {
		Response = cos(Argument);
		break;
	}
	case Sin: {
		Response = sin(Argument);
		break;
	}
	case Tg: {
		Response = tan(Argument);
		break;
	}
	case Ctg: {
		Response = 1 / (tan(Argument));
		break;
	}
	case Log: {
		Response = log10(Argument);
		break;
	}
	case Ln: {
		Response = log(Argument);
		break;
	}
	case Sqrt: {
		Response = sqrt(Argument);
		break;
	}
	case Abs: {
		Response = abs(Argument);
		break;
	}
	case Exp: {
		Response = exp(Argument);
		break;
	}
	}
	return Response;
}

void Postfix::Infix_to_Postfix(string read) {
	size_t i = 0, left_breckets = 0, right_breckets = 0, dots = 0;
	string Cur_postfix;
	/*for (i = 0; i < read.size(); i++)*/
	while (i < read.size()) {
		Cur_postfix.clear();
		if (read[i] == '-' && List_postfix->IsEmpty()) {
			Cur_postfix.push_back('0');
			List_postfix->push_back_string(Cur_postfix, not_operator);
			Cur_postfix.clear();
			Stack_elem->push_char(read[i++], add_sub);
		}
		if (read[i] == ' ') {
			i++;
		}
		if (Number(read[i])) {	
			dots = 0;
			while (Number(read[i])) {
				if (read[i] == '.') {
					dots++;
				}
				Cur_postfix.push_back(read[i++]);
			}
			if (read[i] == ' ') {
				i++;
			}
			if (read[i] == '(') {
				throw ("Entry error, please try again");
			}
			List_postfix->push_back_string(Cur_postfix, not_operator);
			Cur_postfix.clear();
		}
		if (WhichOperator(read[i]) == left_brecket) { 
			left_breckets++;
			Stack_elem->push_char(read[i++], left_brecket);
			if (read[i] == '-') {
				Cur_postfix.push_back('0');
				List_postfix->push_back_string(Cur_postfix, not_operator);
				Cur_postfix.clear();
				Stack_elem->push_char(read[i++], add_sub);
			}
			if (WhichOperator(read[i]) == right_brecket) {
				throw ("Entry error, please try again");
			}
		}
		else {
			if (WhichOperator(read[i]) == right_brecket) {
				right_breckets++;
				while ((!Stack_elem->IsEmpty()) && (Stack_elem->front()->first_action != left_brecket)) {
					List_postfix->push_back(Stack_elem->pop());
				}
				Stack_elem->pop();
				i++;
			}
			else {

				if (WhichOperator(read[i]) != not_operator) {
					if (Stack_elem->IsEmpty()) {
						Stack_elem->push_char(read[i], WhichOperator(read[i]));
					}
					else {
						if (!Stack_elem->IsEmpty()) {
							if (Stack_elem->front()->first_action < WhichOperator(read[i])) {
								Stack_elem->push_char(read[i], WhichOperator(read[i]));
							}
						}
						else {
							if (!Stack_elem->IsEmpty()) {
								if (Stack_elem->front()->first_action >= WhichOperator(read[i])) {
									while ((!Stack_elem->IsEmpty()) && (Stack_elem->front()->first_action >= WhichOperator(read[i]))) {
										List_postfix->push_back(Stack_elem->pop());
									}
									Stack_elem->push_char(read[i], WhichOperator(read[i]));
								}
							}
						}
					}
					i++;
				}
				if (Function(read[i])) {
					string function;
					while (Function(read[i]))
						function.push_back(read[i++]);
					if (WhichFunction(function) != not_operator) {
						if (Stack_elem->IsEmpty()) {
							Stack_elem->push_string(function, func);
						}
						else {
							if (!Stack_elem->IsEmpty()) { 
								if (Stack_elem->front()->first_action < func) {
								Stack_elem->push_string(function, func);
								}
							}
							else {
								if (!Stack_elem->IsEmpty()) {
									if (Stack_elem->front()->first_action >= func) {
										while (!Stack_elem->IsEmpty() && (Stack_elem->front()->first_action >= func)) {
											List_postfix->push_back(Stack_elem->pop());
										}
										Stack_elem->push_string(function, func);
									}
								}
							}
						}
						if (read[i] == ' ') {
							i++;
						}
						if (WhichOperator(read[i]) == left_brecket) {
							left_breckets++;
							Stack_elem->push_char(read[i++], left_brecket);
							if (read[i] == '-') {
								Cur_postfix.push_back('0');
								List_postfix->push_back_string(Cur_postfix, not_operator);
								Cur_postfix.clear();
								Stack_elem->push_char(read[i++], add_sub);
							}
							if (Number(read[i])) {
								dots = 0;
								while (Number(read[i])) {
									if (read[i] == '.') {
										dots++;
									}
									Cur_postfix.push_back(read[i++]);
								}
								if (read[i] == ' ') {
									i++;
								}
								if (dots > 1) {
									throw ("Entry error, please try again");
								}
								if (read[i] == '(') {
									throw ("Entry error, please try again");
								}
								List_postfix->push_back_string(Cur_postfix, not_operator);
								Cur_postfix.clear();
							}
						}
						if (WhichOperator(read[i]) == right_brecket) {
							right_breckets++;
							while (Stack_elem->front()->first_action != left_brecket) {
								List_postfix->push_back(Stack_elem->pop());
							}
							Stack_elem->pop();
							i++;

						}

					}
				}
			}
		}
		if (read[i] == ' ') {
			i++;
		}
		if (i == read.size()) {
			break;
		}
		if (!Number(read[i]) && !Function(read[i]) && WhichOperator(read[i]) == not_operator) {
			throw ("Entry error, please try again");
			break;
		}
	}
	if (!Stack_elem->IsEmpty()) {
		while (!Stack_elem->IsEmpty()) {
			List_postfix->push_back(Stack_elem->pop());
		}
	}
}

double  Postfix::process() {
	Node* Cur = List_postfix->set_head();
	double A1 = 0, A2 = 0, Response = 0;
	string number;
	number.clear();
	Stack_elem = new Stack();
	while (Cur != nullptr) {
		if (Number(Cur->data[0])) {
			Stack_elem->push_string(Cur->data, not_operator);
		}
		if (WhichFunction(Cur->data) == Pi) {
			Stack_elem->push(Cur);
		}
		if (WhichFunction(Cur->data) == E) {
			Stack_elem->push(Cur);
		}
		if (WhichOperator(Cur->data[0]) != not_operator) {
			number.clear();
			if (!Stack_elem->IsEmpty()) {
				number = Stack_elem->pop()->data;
				if (WhichFunction(number) == Pi) A2 = pi;
				else if (WhichFunction(number) == E) A2 = e;
				else A2 = stod(number);
				number.clear();
			}
			else throw("Entry error, please try again");
			if (!Stack_elem->IsEmpty()) {
				number = Stack_elem->pop()->data;
				if (WhichFunction(number) == Pi) A1 = pi;
				else if (WhichFunction(number) == E) A1 = e;
				else A1 = stod(number);
				number.clear();
			}
			else throw("Entry error, please try again");
			Response = Operator_last(Cur->data[0], A1, A2);
			Stack_elem->push_string(to_string(Response), not_operator);
		}
		if (WhichFunction(Cur->data) != not_operator) {
			if (WhichFunction(Cur->data) != Pi) {
				if (WhichFunction(Cur->data) != E) {
					number.clear();
					if (!Stack_elem->IsEmpty()) {
						number = Stack_elem->pop()->data;
						if (WhichFunction(number) == Pi) {
							A1 = pi;
						}
						else {
							if (WhichFunction(number) == E) {
								A1 = e;
							}
							else {
								A1 = stod(number);
							}
							number.clear();
						}
					}
					else {
						throw("Entry error, please try again");
					}
					Response = Function_last(WhichFunction(Cur->data), A1);
					Stack_elem->push_string(to_string(Response), not_operator);
				}
			}
		}
		Cur = Cur->next;
	}
	if (!Stack_elem->IsEmpty()) {
		if (Response == 0) {
			Response = stod(Stack_elem->pop()->data);
		}
	}
	return Response;
}

void Postfix::out() {
	List_postfix->print_to_console();
}

Postfix::~Postfix() {
	List_postfix->~List();
	Stack_elem->~Stack();

}

int main() {
	Postfix* Postfix_elem = nullptr;
	double Response;
	string read;
	while (1) {
		Postfix_elem = new Postfix();
		cout << "Enter the expression in infix form: ";
		getline(cin, read);
		cout << endl;
		if (read == "Exit") {
			break;
		}
		try {
			Postfix_elem->Infix_to_Postfix(read);
			cout << "Postfix form: ";
			Postfix_elem->out();
			Response = Postfix_elem->process();
			cout << "Response: " << Response << endl;
			cout << endl;
			cout << endl;
		}
		catch (const char* error) {
			cout << error << endl;
		}
	}
	return 0;
}