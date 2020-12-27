#include "CppUnitTest.h"
#include "../AlgStrD_KursWork/Node.h"
#include "../AlgStrD_KursWork/List.h"
#include "../AlgStrD_KursWork/Stack.h"
#include "../AlgStrD_KursWork/Postfix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestKursWork
{
	TEST_CLASS(UnitTestKursWork)
	{
	public:

		Postfix* check;

		TEST_METHOD_INITIALIZE(setUp)
		{
			check = new Postfix();
		}

		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete check;
		}

		TEST_METHOD(check_1)
		{
			string input = { "1+5" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 4.0);
		}
		TEST_METHOD(check_2)
		{
			string input = { "5^3" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 125.0);
		}
		TEST_METHOD(check_3)
		{
			string input = { "(5+3)*6" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 48.0);
		}
		TEST_METHOD(check_4)
		{
			string input = { "cos(pi)" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), -1.0);
		}
		TEST_METHOD(check_5)
		{
			string input = { "sin(5-5)" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 0.0);
		}
		TEST_METHOD(check_6)
		{
			string input = { "cos(2*pi)" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 1.0);
		}
		TEST_METHOD(check_7)
		{
			string input = { "ln(e)" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 1.0);
		}
		TEST_METHOD(check_8)
		{
			string input = { "log(10)" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 1.0);
		}
		TEST_METHOD(check_9)
		{
			string input = { "tg(0)" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 0.0);
		}
		TEST_METHOD(check_10)
		{
			string input = { "sqrt(25)" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 5.0);
		}
		TEST_METHOD(check_11)
		{
			string input = { "abs(-125)" };
			check->Infix_to_Postfix(input);
			Assert::AreEqual(check->process(), 125.0);
		}
		TEST_METHOD(check_12)
		{

			try {
				string input = { "abs(" };
				check->Infix_to_Postfix(input);
				check->process();
			}
			catch (const char* error) {
				Assert::AreEqual("Entry error, please try again", error);
			}
		}
		TEST_METHOD(check_13)
		{
			try {
				string input = { "5*()" };
				check->Infix_to_Postfix(input);
			}
			catch (const char* error) {
				Assert::AreEqual("Entry error, please try again", error);
			}
		}
		TEST_METHOD(check_14)
		{
			try {
				string input = { "5*)" };
				check->Infix_to_Postfix(input);
			}
			catch (const char* error) {
				Assert::AreEqual("Entry error, please try again", error);
			}
		}
	};
}
