/*
In any language program mostly syntax error occurs due to unbalancing delimiter such
as () , {} , []. Write C++ program using stack to check whether given expression is well
Parenthesized or not.
*/
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
	char *st;
	int top;
	Stack(int n);
	void push(char t);
	void pop();
	bool isFull();
	bool isEmpty();
	char Top();
};
Stack :: Stack(int n) {
	st = new char[n];
	top = -1;
}
void Stack :: push(char t) {
	if(this->isFull()) {
		cout << "Stack is Full!" << endl;
	}
	else {
		top++;
		st[top] = t;
	}
}
void Stack :: pop() {
	if(this->isEmpty()) {
		cout << "Stack Is Empty!" << endl;
	}
	else {
		st[top] = ' ';
		top--;
	}
}
bool Stack :: isFull() {
	if(top == strlen(st)) {
		return true;
	}
	else {
		return false;
	}
}
bool Stack :: isEmpty() {
	if(top == -1) {
		return true;
	}
	else {
		return false;
	}
}
char Stack :: Top() {
	return st[top];
}

class Expression {
	char *ar;
public:
	Expression(int n) {
		ar = new char[n];
	}
	bool check(char *ar) {
		this->ar = ar;
		bool r = true;
		int n = strlen(ar);
		Stack s(n);
		for(int i = 0 ; i < n ; i++) {
			if(ar[i] == '(' || ar[i] == '[' || ar[i] == '{') {
				s.push(ar[i]);
			}
			else if(s.st[s.top] == '(' && ar[i] == ')') {
				s.pop();
			}
			else if(s.st[s.top] == '[' && ar[i] == ']') {
				s.pop();
			}
			else if(s.st[s.top] == '{' && ar[i] == '}') {
				s.pop();
			}
			else if(s.isEmpty() && (ar[i] == ')' || ar[i] == ']' || ar[i] == '}') ){
				r = false;
				break;
			}
		}
		if(s.isEmpty() && r) {
			return true;
		}
		else {
			return false;
		}
	}
};
int main() {
	char c = 'Y';
	while(c == 'Y') {
		char ar[50];
		cout << "Enter Expression : ";
		cin >> ar;
		int n = strlen(ar);
		Expression exp(n);
		bool r = exp.check(ar);
		if(r) {
			cout << "Valid Expression!" << endl;
		}
		else {
			cout << "Invalid Expression!" << endl;
		}
		cout << "Do you want to check more expressions?(Y/N)";
		cin >> c;
	}
	return 0;
}

/*
OUTPUT :

Enter Expression : a^b*c-c+d/a
Valid Expression!
Do you want to check more expressions?(Y/N)Y

Enter Expression : {a+b*(c/d)}
Valid Expression!
Do you want to check more expressions?(Y/N)Y

Enter Expression : {(a+b)*[e+f]}
Valid Expression!
Do you want to check more expressions?(Y/N)Y

Enter Expression : {(a+b]}
Invalid Expression!
Do you want to check more expressions?(Y/N)Y

Enter Expression :  {a+b*d]
Invalid Expression!
Do you want to check more expressions?(Y/N)N

*/
