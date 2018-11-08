/*
Create employee bio-data using classes
Classes are:
• Personal record
• Professional record
• Academic record 
Assume appropriate data members and member function to accept required data & print 
bio-data. Create bio-data using multiple inheritances using C++.
*/
#include <bits/stdc++.h>
using namespace std;
class Personal {
protected:
	string name;
	char *add;
	long long int mob;
	string dob;
public:
	Personal();
	virtual void display();
};
Personal :: Personal() {
	name = "";
	add = new char[100];
	mob = 0;
	dob = " ";
}
void Personal :: display() {
	cout << "NAME          : " << name << endl;
	cout << "ADDRESS       : " << add << endl;
	cout << "MOBILE NO.    : " << mob << endl;
	cout << "DATE OF BIRTH : " << dob << endl;
	cout << endl;
}

class Academics {
protected:
	string qual;
	float SSC_mks , HSC_mks;
public:
	Academics();
	virtual void display();
};
Academics :: Academics() {
	qual = " ";
	SSC_mks = 0;
	HSC_mks = 0;
}
void Academics :: display() {
	cout << "ACADEMICS : " << endl;
	cout << endl;
	cout << "SSC Marks     : " << SSC_mks << endl;
	cout << "HSC Marks     : " << HSC_mks << endl;
	cout << "Qualification : " << qual << endl;
	cout << endl;
}

class Professional {
protected:
	int exp;
	string cmp;
	string dsg;
public:
	Professional();
	virtual void display();
};
Professional :: Professional() {
	exp = 0;
	cmp = " ";
	dsg = " ";
}
void Professional :: display() {
	cout << "PROFESSIONAL : " << endl;
	cout << endl;
	cout << "Experience : " << exp << endl;
	cout << "Currently Working In : " << cmp << endl;
	cout << "Designation : " << dsg << endl;
}
class Biodata : public Personal , public Academics , public Professional {
public:
	void accept();
	void display();
};
void Biodata :: accept() {
	cout << "Enter Employee Information" << endl;
	cout << "Enter Personal Details" << endl;
	cout << "Enter Name : ";
	getline(cin , name);
	cout << "Enter Address : ";
	cin.getline(add , 100);
	cout << "Enter Date Of Birth : ";
	getline(cin , dob);
	cout << "Enter Mobile No. : ";
	cin >> mob;
	cout << "Enter Academic Details" << endl;
	cout << "Enter HSC Marks: ";
	cin >> HSC_mks;
	cout << "Enter SSC Marks: ";
	cin >> SSC_mks;
	cout << "Enter Qualification : ";
	cin.ignore();
	getline(cin , qual);
	cout << "Enter Professional Details" << endl;
	cout << "Enter Years Of Experience :";
	cin >> exp;
	cout << "Enter Presently Working Company Name :";
	cin.ignore();
	getline(cin , cmp);
	cout << "Enter Current Designation :";
	getline(cin , dsg);
}
void Biodata :: display() {
	Personal :: display();
	Academics :: display();
	Professional :: display();
}
int main() {
	Biodata b;
	b.accept();
	b.display();
	return 0;
}
