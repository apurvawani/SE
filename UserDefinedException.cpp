/*
Crete User defined exception to check the following conditions and throw the exception if 
the criterion does not meet.
1. User has age between 18 and 55
2. User has income between Rs. 50,000 – Rs.1,00,000 per month
3. User stays in Pune / Mumbai / Bangalore / Chennai
4. User has 4-wheeler
Accept age, Income, City, Vehicle from the user and check for the conditions mentioned
above. If any of the condition not met then throw the exception.
*/

#include <iostream>
#include <exception>
#include <string.h>
using namespace std;

int main() {
	int age;
	float income;
	char city[10];
	char vehicle;
	cout << "Enter User Data : " << endl;
	cout << "Enter Age : ";
	cin >> age;
	cout << "Enter Income : ";
	cin >> income;
	cout << "Enter Residence City : ";
	cin >> city;
	cout << "Do you have a 4-wheeler?(Y/N)";
	cin >> vehicle;
	try {
		if(age < 18 || age > 55) {
			throw age;
		}
		else {
			cout << "Age : " << age << endl;
		}
	}
	catch(int age) {
			cout << "Age should be between 18 and 55!" << endl;
	}
	try {
		if(income <= 50000 || income >= 100000) {
			throw income;
		}
		else {
			cout << "Income : " << income << endl;
		}
	}
	catch(float income) {
			cout << "Monthly income should be between Rs.50,000 – Rs.1,00,000!" << endl;
	}
	try {
		if(strcmp(city , "Pune") && strcmp(city , "Mumbai") && strcmp(city , "Chennai") && strcmp(city , "Bangalore")) {
			throw city;
		}
		else {
			cout << "City : " << city << endl;
		}
	}
	catch(char *city) {
			cout << "User Location must be one of these Pune , Mumbai , Bangalore or Chennai!" << endl;
	}
	try {
		if(vehicle == 'N') {
			throw vehicle;
		}
		else {
			cout << "User has 4-wheeler." << endl;
		}
	}
	catch(char vehicle) {
		cout << "User must have a 4-wheeler!" << endl;
	}
	return 0;
}
