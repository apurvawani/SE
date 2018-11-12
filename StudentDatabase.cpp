/*
Create student database with appropriate data members that should use the following
features of object oriented programming in C++. Class, Object, array of objects, new ,
delete, default constructor to initialize student class fields, parameterized constructor
to set the values into the objects, access specifiers, this pointer.
*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Student {
protected:
	char *name;
	int rno;
	char *dept;
	int div;
	char *dob;
	char *bldgrp;
public:
	Student();
	void getinfo(int rno , char *name , char *dept , int div , char *dob , char *bldgrp);
	~Student();
};
Student :: Student() {
	rno = 0;
	name = new char[1];
	dept = new char[1];
	div = 0;
	dob = new char[1];
	bldgrp = new char[1];
}
void Student :: getinfo(int rno , char *name , char *dept , int div , char *dob , char *bldgrp) {
	this->rno = rno;
	int l1 = strlen(name);
	this->name = new char[l1+1];
	strcpy(this->name , name);
	int l2 = strlen(dept);
	this->dept = new char[l2+1];
	strcpy(this->dept , dept);
	int l3 = strlen(dob);
	this->dob = new char[l3+1];
	strcpy(this->dob , dob);
	this->div = div;
	int l = strlen(bldgrp);
	this->bldgrp = new char[l+1];
	strcpy(this->bldgrp , bldgrp);
}
Student :: ~Student() {
	rno = 0;
	delete name;
	delete dept;
	div = 0;
	delete dob;
	delete bldgrp;
	cout << "Student details successfully deleted!" << endl;
}

class Marks : public Student {
	float int_mks;
	float UT1_mks;
	float UT2_mks;
	float online_mks;
	float theory_mks;
public :
	Marks();
	void display();
	void read();
};
Marks :: Marks() {
	int_mks = 0;
	UT1_mks = 0;
	UT2_mks = 0;
	online_mks = 0;
	theory_mks = 0;
}
void Marks :: read() {
	cout << endl;
	int rn , division;
	char bg[5] , s[15] , dpt[10] , d[12];
	cout << "Enter Name : ";
	cin >> s;
	cout << "Enter Division : ";
	cin >> division;
	cout << "Enter Roll No : ";
	cin >> rn;
	cout << "Enter Department : ";
	cin >> dpt;
	cout << "Enter Date Of Birth : ";
	cin >> d;
	cout << "Enter Blood Group : ";
	cin >> bg;
	this-> Student :: getinfo(rn , s , dpt , division , d , bg);
	cout << "Enter internal marks : ";
	cin >> this-> int_mks;
	cout << "Enter Unit Test 1 marks : ";
	cin >> this-> UT1_mks;
	cout << "Enter Unit Test 2 marks : ";
	cin >> this-> UT2_mks;
	cout << "Enter Online Exam marks : ";
	cin >> this-> online_mks;
	cout << "Enter Theory Exam marks : ";
	cin >> this-> theory_mks;
}
void Marks :: display() {
	cout << "NAME          : " << this-> Student :: name << endl;
	cout << "DIVISION      : " << this-> Student :: div << endl;
	cout << "ROLL NO       : " << this-> Student :: rno << endl;
	cout << "DEPARTMENT    : " << this-> Student :: dept << endl;
	cout << "BLOOD GROUP   : " << this-> Student :: bldgrp << endl;
	cout << "DATE OF BIRTH : " << this-> Student :: dob << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "   INT MARKS   UT1 MARKS   UT2 MARKS   ONLINE   THEORY   " << endl;
	cout << setw(8) << this->int_mks << setw(12) << this->UT1_mks << setw(12) << this->UT2_mks << setw(12) << this->online_mks << setw(9) << this->theory_mks << endl;
	//cout << "      " << this-> int_mks << "          " << this-> UT1_mks << "          " << this-> UT2_mks << "         " << this-> online_mks << "       " << this-> theory_mks << endl;
	cout << "----------------------------------------------------------" << endl;
}

int main() {
	Marks *ob;
	int n;
	cout << "Enter no. of students : ";
	cin >> n;
	ob = new Marks[n];
	cout << "Enter Student Details : " << endl;
	for(int i = 0 ; i < n ; i++) {
		ob[i].read();
	}
	cout << "*************** Student Information System ***************" << endl;
	for(int i = 0 ; i < n ; i++) {
		ob[i].display();
	}
	return 0;
}
