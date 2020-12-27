#pragma once
#include "Stack.h"
#include <stdexcept>
#include <cmath>
#include <string>

class Postfix {
private:
	Stack* Stack_elem;
	List* List_postfix;
	enum first_action {
		left_brecket, right_brecket, add_sub, multipl_division, degree, func, not_operator = -1
	};
	enum functions { 
		Sin, Cos, Log, Ln, Tg, Ctg, Sqrt, Abs, Exp, Pi ,E
	};

public:
	Postfix();
	bool Number(char Symbol);
	bool Function(char Symbol);
	int WhichOperator(char Symbol);
	double Operator_last(char Symbol, double A1, double A2);
	int WhichFunction(string Function);
	double Function_last(int Function, double Argument);
	void Infix_to_Postfix(string read);
	double process();
	void out();
	~Postfix();
};