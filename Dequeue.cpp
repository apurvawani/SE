/*
Write C++ program using STL for Dqueue (Double ended queue).
*/
#include <bits/stdc++.h>
#include <deque>
using namespace std;

int main() {
	deque <int> d;
	int data , ch;
	while(ch != 6) {
		cout << endl;
		cout << "Enter choice : " << endl;
		cout << "1. Enter element at front. " << endl;
		cout << "2. Enter element at Rear. "<< endl;
		cout << "3. Delete element at front. "<< endl;
		cout << "4. Delete element at Rear. "<< endl;
		cout << "5. Display the elements of dequeue. "<< endl;
		cout << "6. Exit" << endl;
		cin >> ch;
		switch(ch) {
		case 1:
			cout << "Enter data : ";
			cin >> data;
			d.push_front(data);
			break;
		case 2:
			cout << "Enter data : ";
			cin >> data;
			d.push_back(data);
			break;
		case 3:
			if(d.empty()) {
				cout << "Queue Is Empty!" << endl;
			}
			else {
				d.pop_front();
				cout << "Element Removed Successfully" << endl;
			}
			break;
		case 4:
			if(d.empty()) {
				cout << "Queue Is Empty!" << endl;
			}
			else {
				d.pop_back();
				cout << "Element Removed Successfully" << endl;
			}
			break;
		case 5:
			if(d.empty()) {
				cout << "Queue Is Empty!" << endl;
			}
			else {
				deque <int> :: iterator i;
				for(i = d.begin() ; i != d.end() ; i++) {
					cout << *i << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}

