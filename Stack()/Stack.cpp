#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	enum { EMPTY = -1, FULL = 20 };

	char st[FULL + 1];

	int top;

public:
	Stack();


	void Push(char c);


	char Pop();

	char Top() {
		return st[top];
	}


	void Clear();


	bool IsEmpty();


	bool IsFull();

	int GetCount();

	void Output()
	{
		for (int i = 0; i < top + 1; i++)
		{
			cout << st[i] << " ";
		}
		cout << endl;
	}

	void CheckExpression(string expression);
};


Stack::Stack()
{
	top = EMPTY;
}

void Stack::Clear()
{
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	return top == EMPTY;
}

bool Stack::IsFull()
{

	return top == FULL;
}

int Stack::GetCount()
{
	return top + 1;
}



void Stack::Push(char c)
{
	if (!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	if (!IsEmpty())
		return st[top--];
	else
		return 0;
}
void Stack::CheckExpression(string expression)
{
	int index = 0;	//saves error index
	bool error = false;	//to save error only once
	for (int i = 0; expression[i] != ':' && expression[i] != '\0'; i++) //Cycle work while symbol is not : and \0
	{
		switch (expression[i])				//If the bracket is open, pushes respective closed bracket to the stack.
		{
	
		case '(':
			Push(')');
			break;

		case '{':
			Push('}');
			break;

		case '[':
			Push(']');
			break;
		}

		switch (expression[i])				//If the bracket is closed, checks if the matched bracket is already in the stack, in successfull case, deletes it from the stack, otherwise will save error index.

		{
		case ')':
			if (IsEmpty() || Top() != expression[i]) {
				if (error == false) {
					index = i;
					error = true;
				}
				break;
			}
			Pop();
			break;
		case '}':
			if (IsEmpty() || Top() != expression[i]) {
				if (error == false) {
					index = i;
					error = true;
				}
				break;
			}
			Pop();
			break;
		case ']':
			if (IsEmpty() || Top() != expression[i]) {
				if (error == false) {
					index = i;
					error = true;
				}
				break;
			}
			Pop();
			break;
		}

	}

	if (IsEmpty() && error == false) {		//If the stack is empty and error = false, the еxpression is correct.
		cout << "Everything's good!";
	}
	else {										//Otherwise, prints the expression until an error occurs.
		for (int i = 0; i < index+1; i++)
		{
			cout << expression[i];
		}
		cout << " <---- ERROR" << endl;
	}
	Clear();

}


void main()
{
	srand(time(0));
	
	Stack ST;

	ST.CheckExpression("(5+5)*)[10+10]"); //Error

	ST.CheckExpression("10+20/(5+10) + {15 + 20}"); // Good
	




}

