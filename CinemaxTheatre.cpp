/*
The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained
to keep track of free seats at rows. Assume some random booking to start with. Use array to
store pointers (Head pointer) to each row.  On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c)  The booking can be cancelled.
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
	Node * prev;
	bool status;
	string movie_name;
	Node * next;
public :
	friend class DCLL;
	friend class Cinemax;
};

class DCLL {
	Node * head;
public :
	friend class Cinemax;
};

class Cinemax {
	DCLL * row[10];
	Node * temp;
public :
	Cinemax();
	void seatsAvailable();
	bool bookSeat(int r , int c , int n , string s);
	void cancelSeat(int r , int c , int n , string s);
	int noOfVacantSeats();
};
int Cinemax :: noOfVacantSeats() {
	temp = row[0]->head;
	int count , k = 70;
	while(k) {
		if(temp->status) {
			temp = temp->next;
			count++;
		}
		else {
			break;
		}
		k--;
	}
	return count;
}
Cinemax :: Cinemax() {
	for(int j = 0 ; j < 10 ; j++) {
		row[j] = new DCLL;
		row[j]->head = NULL;
		Node *t = new Node;
		t->prev = NULL;
		t->next = NULL;
		t->status = true;
		t->movie_name = "\0";
		if(row[j]->head == NULL) {
			row[j]->head = t;
			t->next = t;
		}
		temp = row[j]->head;
		for(int k = 0 ; k < 6 ; k++) {
			Node *p = new Node;
			p->prev = temp;
			p->status = true;
			p->movie_name = "\0";
			p->next = row[j]->head;
			temp->next = p;
			temp = temp->next;
		}
	}
}
void Cinemax :: seatsAvailable() {
	for(int x = 1 ; x <= 7 ; x++) {
		cout <<"\t" << x;
	}
	cout << endl;
	int j = 0;
	while(j < 10) {
		cout << j+1 << "\t";
		temp = row[j]->head;
		while(temp->next != row[j]->head) {
			if(temp->status == true) {
				cout << "A\t";
			}
			else {
				cout << "NA\t";
			}
			temp = temp->next;
		}
		if(temp->status == true) {
			cout << "A\t";
		}
		else {
			cout << "NA\t";
		}
		cout << endl;
		j++;
	}
}
bool Cinemax :: bookSeat(int r , int c , int n , string s) {
	temp = row[r-1]->head;
	int t = 0;
	int count = 7;
	bool flag = true;
	while(count != 0) {
		if(temp->status==true) {
			t++;
		}
		temp = temp->next;
		count--;
	}
	if(t >= n) {
		int k = 1;
		while(k != c) {
			temp = temp->next;
			k++;
		}
		char ch = ' ';
		while(n != 0) {
			if(temp->status == false) {
				cout << "Continuous seats are not available in this row!" << endl;
				cout << "Do you want continue?(Y/N)";
				cin >> ch;
			}
			else {
				temp->status = false;
			}
			if(ch == 'N'){
				flag = false;
				break;
			}
			else if(ch == 'Y' && n != 0){
				while(temp->status == false) {
					temp = temp->next;
				}
				temp->status = false;
				flag = true;
			}
			temp = temp->next;
			n--;
		}
	}
	else {
		cout << "Requested no of seats are not available in this row!" << endl;
		flag = false;
	}
	return flag;
}
void Cinemax :: cancelSeat(int r , int c , int n , string s) {
	cout << "5% will be deducted as cancellation charges. Do you want to continue?(Y/N)" << endl;
	temp = row[r-1]->head;
	int k = 1;
	while(k != c) {
		temp = temp->next;
		k++;
	}
	while(n != 0) {
		if(temp->status == false) {
			temp->status = true;
		}
		temp = temp->next;
		n--;
	}
	cout << "Refund Amount : " << n*150*(1-0.05) << endl;
	cout << "Successfully canceled!" << endl;
}
int main() {
	/*int m;
	cout << "Movies available in Cinemax theatre this week : " << endl;
	cout << "1. Thugs Of Hindustan" << endl;
	cout << "2. Sarkar" << endl;
	cout << "3. Badhaai Ho" << endl;
	cout << "4. Zero" << endl;
	cout << "Select Movie : ";
	cin >> m;
	if(m == 1) {Cinemax m1 , m2 , m3 , m4;}*/
	Cinemax m;
    int ch;
	while(ch != 4) {
		cout << "Enter your choice : " << endl;
		cout << "1. Show Available Seats" << endl;
		cout << "2. Book Seat" << endl;
		cout << "3. Cancel Seat" << endl;
        cout << "4. Exit" << endl;
		cin >> ch;
		switch(ch) {
			case 1:
				{
					m.seatsAvailable();
					break;
				}
			case 2:
				{
					int rno , cno , no;
					string n;
					cout << "Enter Movie Name : ";
					cin >> n;
					cout << "Enter Row No , Column No , No of seats : ";
					cin >> rno >> cno >> no;
					cout << "Ticket cost : 150" << endl; 
					cout << "Booking Initiated!" << endl;
					bool x = m.bookSeat(rno , cno , no , n);
					if(x == true) {
						cout << "Booking Successful!" << endl;
						cout << "Total Amount : " << no * 150 << endl;
					}
					else {
						cout << "Try again!" << endl;
					}
					break;
				}
			case 3:
				{
					if(m.noOfVacantSeats() == 0) {
						cout << "No Seats are booked!" << endl;
					}
					else {
						int rno , cno , no;
						string n;
						cout << "Enter Movie Name : ";
						cin >> n;
						cout << "Enter Row No , Column No , No of seats : ";
						cin >> rno >> cno >> no;
						m.cancelSeat(rno , cno , no , n);
					}
					break;
				}
		}
	}
	return 0;
}
