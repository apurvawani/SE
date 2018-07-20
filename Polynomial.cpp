/*
Write a C++ program to realize polynomial equation and perform operations. Write function for :   
a) To input and output polynomials represented as bmxem+ bm-1xem-1 +….. +b0xe0.Your functions should overload the << and >> operators.  
b) Evaluates a polynomial at given value of x 
c) Add two polynomials    
d) Multiplies two polynomials  
*/

#include <bits/stdc++.h>
using namespace std;

class Term {
	int e;
	float c;
public :
	Term() {
		e = 0;
		c = 0;
	}
	friend class Polynomial;
	friend istream & operator>>(istream &in , Term &t);
	friend ostream & operator<<(ostream &out , Term &t);
};
istream & operator>>(istream &in , Term &t) {
	in >> t.e;
	in >> t.c;
	return in;
}
ostream & operator<<(ostream &out , Term &t) {
	if(t.e!=0) {
		out << t.c << "x^" << t.e;
		out << " +";
	}
	else if(t.c!=0){
		out << t.c;
	}
	return out;
}
class Polynomial {
	int n;
	Term *t;
public:
	Polynomial(int nterms) {
		n = nterms;
		t = new Term [n];
	}
	void read();
	void display();
	Polynomial add(Polynomial , Polynomial);
	float evaluate(float);
	Polynomial multiply(Polynomial , Polynomial);
};
void Polynomial :: read() {
	for(int i = 0 ; i < n ; i++) {
		cin >> t[i];
	}
}
void Polynomial :: display() {
	for(int i = 0 ; i < n ; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
}
Polynomial Polynomial :: add(Polynomial p2 , Polynomial p3) {
	int j = 0 , k = 0 , i = 0;
	while(j < n || k < p2.n) {
		if(t[j].e == p2.t[k].e) {
			p3.t[i].e = t[j].e;
			p3.t[i].c = t[j].c + p2.t[k].c;
			j++;
			k++;
			i++;
		}
		else {
			if(t[j].e > p2.t[k].e) {
				p3.t[i].e = t[j].e;
				p3.t[i].c = t[j].c;
				i++;
				j++;
			}
			else {
				p3.t[i].e = p2.t[k].e;
				p3.t[i].c = p2.t[k].c;
				k++;
				i++;
			}
		}
	}
	while(j < n) {
		p3.t[i].e = t[j].e;
		p3.t[i].c = t[j].c;
		j++;
		i++;
	}
	while(k < p2.n) {
		p3.t[i].e = p2.t[k].e;
		p3.t[i].c = p2.t[k].c;
		k++;
		i++;
	}
	return p3;
}
float Polynomial :: evaluate(float v) {
	float val = 0;
	for(int i = 0 ; i < n ; i++) {
		if(t[i].c!=0) {
			val = val + (t[i].c * pow(v , t[i].e));
		}
	}
	return val;
}
Polynomial Polynomial :: multiply(Polynomial p2 , Polynomial p4) {
	Term temp;
	int count = 0 , k = 1;
	p4.t[0].e = t[0].e + p2.t[0].e;
	p4.t[0].c = t[0].c * p2.t[0].c;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < p2.n ; j++) {
			temp.e = t[i].e + p2.t[j].e;
			temp.c = t[i].c * p2.t[j].c;
			if(p4.t[k-1].e > temp.e) {
				p4.t[k].e = temp.e;
				p4.t[k].c = temp.c;
				k++;
			}
			else {
				count = k - 1;
				while(count >= 0 && p4.t[count].e < temp.e) {
					p4.t[count+1].e = p4.t[count].e;
					p4.t[count+1].c = p4.t[count].c;
					count--;
				}
				if(p4.t[count].e==temp.e && count!=0) {
					p4.t[count].c += temp.c;
				}
				else {
					p4.t[count+1].e = temp.e;
					p4.t[count+1].c = temp.c;
				}
			}
		}
	}
	return p4;
}

int main() {
	int n1 , n2;
	cout << "Enter number of terms in first polynomial : ";
	cin >> n1;
	cout << "Enter number of terms in second polynomial : ";
	cin >> n2;
	Polynomial p1(n1) , p2(n2);
	Polynomial p3(n1+n2) , p4(n1*n2);
	cout << "Enter corresponding exponent & coefficient for first matrix : ";
	p1.read();
	cout << "First Polynomial : ";
	p1.display();
	cout << "Enter corresponding exponent & coefficient for second matrix : ";
	p2.read();
	cout << "Second Polynomial : ";
	p2.display();
	p3 = p1.add(p2 , p3);
	cout << "Sum Of Two Polynomials : ";
	p3.display();
	float v;
	cout << "Enter value : ";
	cin >> v;
	cout << "Value of first Polynomial at x = " << v << " is : " << p3.evaluate(v) << endl;
	p4 = p1.multiply(p2 , p4);
	cout << "Product Of Two Polynomials : ";
	p4.display();
	return 0;
}
