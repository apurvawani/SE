/*
Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions :
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack {
public:
	T *st;
	int top;
	Stack(int n) {
		st = new T[n];
		top = -1;
	}
	void push(T c) {
		top++;
		st[top] = c;
	}
	void pop() {
		st[top] = ' ';
		top--;
	}
	bool isFull() {
		if(top == sizeof(st)/sizeof(st[0])) {
			return true;
		}
		else {
			return false;
		}

	}
	bool isEmpty() {
		if(top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Expression {
	char *ar;
public:
	Expression(int n) {
		ar = new char[n];
	}
	void infixToPostfix(char *i , int size);
	int priority(char op);
	void evaluate(int size);
};
int Expression :: priority(char op) {
	if(op == '*' || op == '/') {
		return 2;
	}
	else if(op == '+' || op == '-') {
		return 1;
	}
	else if(op == '^') {
		return 3;
	}
	else if(op == ')') {
		return 4;
	}
	else {
		return 0;
	}
}
void Expression :: infixToPostfix(char *i , int size) {
	Stack<char> s(size);
	s.push('(');
	i[size] = ')';
	int t = 0;
	for(int k = 0 ; k <= size ; k++) {
		if(i[k] - '0' >= 0 && i[k] - '0' <= 9) {
			ar[t] = i[k];
			t++;
		}
		else {
			if(i[k] == '(') {
				s.push(i[k]);
			}
			else {
				while(this->priority(s.st[s.top]) >= this->priority(i[k])) {
					ar[t] = s.st[s.top];
					t++;
					s.pop();
				}
				s.push(i[k]);
				if(i[k] == ')') {
					s.pop();
					while(s.st[s.top] != '(') {
						ar[t] = s.st[s.top];
						t++;
						s.pop();
					}
					s.pop();
				}
			}
		}
	}
	cout << "Postfix expression is : ";
	for(int x = 0 ; x < t ; x++) {
		cout << ar[x];
	}
	cout << endl;
	this->evaluate(t);
}

void Expression :: evaluate(int size) {
	Stack <float> eval(size);
	for(int i = 0 ; i < size ; i++) {
		if(ar[i] - '0' >= 0 && ar[i] - '0' <= 9) {
			eval.push(ar[i] - '0');
		}
		else {
			float a , b;
			b = eval.st[eval.top];
			eval.pop();
			a = eval.st[eval.top];
			eval.pop();
			if(ar[i] == '*') {
				eval.push(a*b);
			}
			else if(ar[i] == '/') {
				eval.push(a/b);
			}
			else if(ar[i] == '+') {
				eval.push(a+b);
			}
			else if(ar[i] == '-') {
				eval.push(a-b);
			}
			else if(ar[i] == '^') {
				eval.push(pow(a,b));
			}
		}
	}
	cout << "Value of the expression is : " << eval.st[eval.top] << endl;
}

int main() {
	char c = 'Y';
	while(c == 'Y') {
		char i[50];
		cout << "Enter the expression : ";
		cin >> i;
		int size = 0 , t = 0;
		while(i[t] != '\0') {
			size++;
			t++;
		}
		Expression e(size);
		e.infixToPostfix(i ,size);
		cout << "Do you want to evaluate more expressions?(Y/N)";
		cin >> c;
	}
	return 0;
}
