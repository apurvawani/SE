/*
Implement a class Complex which represents the Complex Number data type and perform the 
following operations:
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overloaded operator+ to add two complex numbers.
3.	Overloaded operator* to multiply two complex numbers.
4. 	Overloaded operator- to subtract two complex numbers.
5. 	Overloaded operator/ to divide two complex numbers.
6.	Overloaded <<and >> to print and read Complex Numbers.
*/

#include <bits/stdc++.h>
using namespace std;

class Complex {
public :
	float real;
	float img;
	Complex() {
		real = 0;
		img = 0;
	}
	Complex operator+(Complex);
	Complex operator*(Complex);
	Complex operator-(Complex);
	Complex operator/(Complex);
	friend ostream & operator<<(ostream &output , Complex &c);
	friend istream & operator>>(ostream &input , Complex &c);
};

Complex Complex :: operator+(Complex c2) {
	Complex temp;
	temp.real = real + c2.real;
	temp.img = img + c2.img;
	return temp;
}

Complex Complex :: operator-(Complex c2) {
	Complex temp;
	temp.real = real - c2.real;
	temp.img = img - c2.img;
	return temp;
}

Complex Complex :: operator*(Complex c2) {
	Complex temp;
	temp.real = (real * c2.real) - (img * c2.img);
	temp.img = (real * c2.img) + (c2.real * img);
	return temp;
}

Complex Complex :: operator/(Complex c2) {
	Complex temp;
	int m = ( (c2.real) * (c2.real) ) + ( (c2.img) * (c2.img) );
	temp.real = ( (real * c2.real) - (img * (-c2.img)) ) / m;
	temp.img = ( (real * (-c2.img)) + (c2.real * img) ) / m;
	return temp;
}

istream & operator>>(istream &input , Complex &c) {
	cout << "Enter real & imaginary part of complex no :" << endl;
	input >> c.real;
	input >> c.img;
	return input;
}

ostream & operator<<(ostream &output , Complex &c) {
	output << "(" << c.real << ")";
	output << "+i" << "(" << c.img << ")" << endl;
	return output;
}

int main() {
	Complex c1 , c2 , c3 , c4 , c5 , c6;
	cin >> c1 >> c2;
	c3 = c1 + c2;
	cout << "Addition of two complex numbers is : " << c3 << endl;
	c5 = c1 - c2;
	cout << "Subtraction of two complex numbers is : " << c5 << endl;
	c4 = c1 * c2;
	cout << "Multiplication  of two complex numbers is : " << c4 << endl;
	c6 = c1 / c2;
	cout << "Division  of two complex numbers is : " << c6 << endl;
	return 0;
}
