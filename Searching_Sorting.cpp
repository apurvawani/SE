/*
Implementation of C++ program for sorting and searching with user defined record.
Write C++ program using STL for sorting and searching with user defined records such as person record (Name, birth, date, telephone no) 
or item record (item code, item name, quantity and cost).
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Person{
  string name;
  int dd , mm , yyyy;
  long phno;
  friend bool compareName(Person, Person);
  friend bool compareDOB(Person, Person);
  friend bool comparePhone(Person, Person);
  friend bool operator==(Person, string);
  friend bool operator==(Person, int);
  friend bool operator==(Person, long);
public:
  void getData() {
    cout << endl;
    char ch;
    cout << "Enter the name of Person:";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Date of Birth(dd/mm/yyyy): ";
    cin >> dd >> ch >> mm >> ch >> yyyy;
    cout << "Enter Phone Number: ";
    cin >> phno;
  }
  void display(){
    cout << name << setw(12-name.length()) << dd << "/" << mm << "/" << yyyy << setw(12) << phno << endl;
  }
};

bool compareName(Person p1 , Person p2){
  return p1.name < p2.name;
}

bool compareDOB(Person p1 , Person p2){
  if(p1.yyyy == p2.yyyy){
    if(p1.mm == p2.mm){
      return p1.dd < p2.dd;
    }
    else
      return p1.mm < p2.mm;
  }
  else
    return p1.yyyy < p2.yyyy;
}

bool comparePhone(Person p1 , Person p2){
  return p1.phno < p2.phno;
}

bool operator==(Person p , string name){
  return p.name == name;
}

bool operator==(Person p , int dob){
  return (p.dd*1000000)+(p.mm*10000)+p.yyyy == dob;
}

bool operator==(Person p , long phno){
  return p.phno == phno;
}

int main() {
  string name;
  int dd , mm , yyyy , dob;
  long phno;
  int n;
  Person *p, *p2;
  cout << "Enter the Number of People you want to add: ";
  cin >> n;
  p = new Person[n];
  for(int i = 0 ; i < n ; i++) {
    p[i].getData();
  }
  cout << endl << "-------- Data Before Sorting ---------" << endl;
  cout << "Name" << setw(12) << "DOB" << setw(15) << "Phone" << endl;
  for(int i = 0 ; i < n ; i++) {
    p[i].display();
  }
  int ch;
  while(ch != 7) {
    cout<<"1.Sort Data By Name" << endl;
    cout<<"2.Sort Data By DOB" << endl;
    cout<<"3.Sort Data By Phone Number" << endl;
    cout<<"4.Search Record By Name" << endl;
    cout<<"5.Search Record By DOB" << endl;
    cout<<"6.Search Record By Phone Number" << endl;
    cout<<"7.Exit" << endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch) {
	case 1:
        sort(p , p+n , compareName);
        cout << endl;
        cout << endl << "-------- Data After Sorting By Name ---------" << endl;
        cout << "Name" << setw(12) << "DOB" << setw(15) << "Phone" << endl;
        for(int i = 0 ; i < n ; i++) {
          p[i].display();
        }
	break;
	case 2:
        sort(p , p+n , compareDOB);
        cout << endl;
        cout << endl << "-------- Data After Sorting By Name ---------" << endl;
        cout << "Name" << setw(12) << "DOB" << setw(15) << "Phone" << endl;
        for(int i = 0 ; i < n ; i++) {
          p[i].display();
        }
	break;
	case 3:
        sort(p , p+n , comparePhone);
        cout << endl;
        cout << endl << "-------- Data After Sorting By Name ---------" << endl;
        cout << "Name" << setw(12) << "DOB" << setw(15) << "Phone" << endl;
        for(int i = 0 ; i < n ; i++) {
          p[i].display();
        }
	break;
	case 4:
        cout << endl << "Enter Name to find: ";
        cin.ignore();
        getline(cin, name);
        p2 = find(p, p+n, name);
        if (p2 != p+n){
          cout << endl;
          p2->display();
        }
        else
          cout << endl << "Name " << name << " not found in Database!" << endl;
	break;
	case 5:
        char ch;
        cout << endl << "Enter Date of Birth(dd/mm/yyyy) to search: ";
        cin >> dd >> ch >> mm >> ch >> yyyy;
        dob = (dd*1000000)+(mm*10000)+yyyy;
        p2 = find(p, p+n, dob);
        if (p2 != p+n){
          cout << endl;
          p2->display();
        }
        else
          cout << endl << "DOB "<<dd<<ch<<mm<<yyyy<<" not found in Database!" << endl;
	break;
	case 6:
        cout << endl << "Enter Phone Number to search: ";
        cin >> phno;
        p2 = find(p, p+n, phno);
        if (p2 != p+n) {
          cout << endl;
          p2->display();
        }
        else
          cout << endl << "Phone Number " << phno <<" not found in Database!" << endl;
	break;
    }
  }
  return 0;	
}
