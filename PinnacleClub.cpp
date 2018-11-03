/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
Second, third and final year of department can be granted membership on request.  Similarly
one may cancel the membership of club. First node is reserved for president of club and last
node  is  reserved  for  secretary  of  club.  Write  C++  program  to  maintain  club  memberâ€˜s
information using singly
linked list. Store student PRN and Name. Write functions to
a)Add and delete the members as well as president or even secretary.
b)Compute total number of members of club
c)Display members
d)Display list in reverse order using recursion
e)Two linked lists exists for two divisions. Concatenate two lists.
f)Merge two sorted linked list
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
	int PRN;
	string name;
	Node *next;
public :
	Node() {
		PRN = 0;
		name = " ";
		next = NULL;
	}
	Node(int prn , string s);
	friend class PC;
};
Node :: Node(int prn , string s) {
	PRN = prn;
	name = s;
	next = NULL;
}
class PC {
public :
	Node *start , *temp;
	int count;
	PC(){
		start = NULL;
		temp = NULL;
		count = 0;
	}
	void InsertPresident();
	void InsertSecretary();
	void InsertMembers();
	void DeletePresident();
	void DeleteSecretary();
	void DeleteMembers();
	void NoOfMembers();
	void display();
	void rev_display(Node *head);
	void concat_list(PC l1 , PC l2);
	void sort_list();
	void merged_list(PC l1 , PC l2);
};
void PC :: InsertPresident() {
	int n;
	string str;
	cout << "Enter PRN number & name: ";
	cin >> n;
	getline(cin , str);
	Node *p = new Node(n , str);
	temp = start;
	if(start == NULL) {
		start = p;
	}
	else {
        start = p;
		p->next = temp;
	}
	count++;
}
void PC :: InsertSecretary() {
	if(start == NULL) {
		cout << "Appointment of Secretary not possible!" << endl;
	}
	else {
		int n;
		string str;
		cout << "Enter PRN number & name: ";
		cin >> n;
		getline(cin , str);
		Node *p = new Node(n , str);
		temp = start;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = p;
	}
	count++;
}
void PC :: InsertMembers() {
	if(start == NULL || start->next == NULL) {
		cout << "Club is not ready.Cannot add members!" << endl;
	}
	else {
		int n;
		string str;
		cout << "Enter PRN number & name: ";
		cin >> n;
		getline(cin , str);
		Node *p = new Node(n , str);
		temp = start;
		while(temp->next->next != NULL) {
			temp = temp->next;
		}
		p->next = temp->next;
		temp->next = p;
	}
	count++;
}
void PC :: DeletePresident() {
	if(start == NULL) {
		cout << "There is no president in the club!" << endl;
	}
	else {
		temp = start;
		start = start->next;
		delete temp;
		count--;
	}
}
void PC :: DeleteSecretary() {
	if(start == NULL || start->next == NULL) {
		cout << "There is no secretary in the club!" << endl;
	}
	else {
		temp = start;
		while(temp->next->next != NULL) {
			temp = temp->next;
		}
		Node *t;
		t = temp->next;
		temp->next = NULL;
		delete t;
		count--;
	}
}
void PC :: DeleteMembers() {
	if(start == NULL || start->next->next == NULL) {
		cout << "There is no member in the club!" << endl;
	}
	else {
		int n;
		bool p = true;
		cout << "Enter PRN no of the member to be deleted : ";
		cin >> n;
		temp = start;
		while(temp->next->PRN != n) {
			temp = temp->next;
			p = false;
		}
		if(!p) {
			cout << "Member with " << n << " this PRN not present." << endl;
		}
		Node *t;
		t = temp->next;
		temp->next = temp->next->next;
		t->next = NULL;
		delete t;
		count--;
	}
}
void PC :: NoOfMembers() {
	if(start == NULL) {
		cout << "Club is not ready!" << endl;
	}
	else {
		cout << "Pinnacle Club consists of " << count << " members." << endl;
	}
}
void PC :: display() {
	if(start == NULL) {
		cout << "Club is not ready!" << endl;
	}
	else {
		temp = start;
		int i = 0;
		while(i != count) {
			i++;
			cout << i << ". " << temp->name << " " << temp->PRN << endl;
			temp = temp->next;
		}
	}
}
void PC :: rev_display(Node *head) {
	if(head == NULL)
		return;
	rev_display(head->next);
	cout << head->name << "  " << head->PRN << endl;
}
void PC :: concat_list(PC l1 , PC l2) {
	if(l1.start == NULL && l2.start == NULL) {
		cout << "Club of division 1 & 2 is not ready!" << endl;
	}
	else {
		temp = start;
		l1.temp = l1.start;
		while(l1.temp != NULL) {
			Node *p = new Node(l1.temp->PRN , l1.temp->name);
			if(temp == NULL) {
				start = p;
				temp = p;
			}
			else {
				temp->next = p;
				temp = temp->next;
			}
			l1.temp = l1.temp->next;
		}
		l2.temp = l2.start;
		while(l2.temp != NULL) {
			Node *p = new Node(l2.temp->PRN , l2.temp->name);
			temp->next = p;
			temp = temp->next;
			l2.temp = l2.temp->next;
		}
	}
}
void PC :: sort_list() {
	if(start == NULL) {
		cout << "Club is not ready!" << endl;
	}
	else {
		int t_prn;
		string t_name;
		temp = start;
		Node *temp1 = temp->next;
		while(temp->next != NULL) {
			temp1 = temp->next;
			while(temp1 != NULL) {
				if(temp->PRN > temp1->PRN) {
					t_prn = temp->PRN;
					t_name = temp->name;
					temp->PRN = temp1->PRN;
					temp->name = temp1->name;
					temp1->PRN = t_prn;
					temp1->name = t_name;
				}
				temp1 = temp1->next;
			}
			temp = temp->next;
		}
		temp = start;
		int i = 0;
		while(i != count) {
			i++;
			cout << i << ". " << temp->name << " " << temp->PRN << endl;
			temp = temp->next;
		}
	}
}
void PC :: merged_list(PC l1 , PC l2) {
	if(l1.start == NULL && l2.start == NULL) {
		cout << "Club of division 1 & 2 is not ready!" << endl;
	}
	else {
		l1.temp = l1.start;
		l2.temp = l2.start;
		temp = start;
		while(l1.temp != NULL && l2.temp != NULL) {
			if(l1.temp->PRN < l2.temp->PRN) {
				Node *p = new Node(l1.temp->PRN , l1.temp->name);
				if(temp == NULL) {
					temp = p;
					start = p;
				}
				else {
					temp->next = p;
					temp = temp->next;
				}
				l1.temp = l1.temp->next;
			}
			else {
				Node *p = new Node(l2.temp->PRN , l2.temp->name);
				if(temp == NULL) {
					temp = p;
					start = p;
				}
				else {
					temp->next = p;
					temp = temp->next;
				}
				l2.temp = l2.temp->next;
			}
		}
		while(l1.temp != NULL) {
			Node *p = new Node(l1.temp->PRN , l1.temp->name);
			temp->next = p;
			temp = temp->next;
			l1.temp = l1.temp->next;
		}
		while(l2.temp != NULL) {
			Node *p = new Node(l2.temp->PRN , l2.temp->name);
			temp->next = p;
			temp = temp->next;
			l2.temp = l2.temp->next;
		}
	}
}
int main() {
	PC l1 , l2 , l3 , l;
	int ch;
	cout << "Pinnacle Club for division 1 :" << endl;
	while(ch != 11) {
		cout << endl;
		cout << "Enter your choice : " << endl;
		cout << "1. Appoint President" << endl;
		cout << "2. Appoint Secretary" << endl;
		cout << "3. Add Member" << endl;
		cout << "4. Remove President" << endl;
		cout << "5. Remove Secretary" << endl;
		cout << "6. Remove Member" << endl;
		cout << "7. Total no of members in the club." << endl;
		cout << "8. List of members in the club." << endl;
		cout << "9. List of members in reverse order." << endl;
		cout << "10. Sorted list of Pinnacle Club." << endl;
		cout << "11. Exit" << endl;
		cin >> ch;
		switch(ch) {
			case 1:
				l1.InsertPresident();
				break;
			case 2:
				l1.InsertSecretary();
				break;
			case 3:
				l1.InsertMembers();
				break;
			case 4:
				l1.DeletePresident();
				break;
			case 5:
				l1.DeleteSecretary();
				break;
			case 6:
				l1.DeleteMembers();
				break;
			case 7:
				l1.NoOfMembers();
				break;
			case 8:
				cout << "***************** WELCOME TO PINNACLE CLUB *****************" << endl;
				l1.display();
				break;
			case 9:
				cout << "Pinnacle Club List in Reverse Order :" << endl;  
				l1.rev_display(l1.start);
				break;
			case 10:
				cout << "Sorted List : " << endl;
				l1.sort_list();
				break;
		}
	}
	int c;
	cout << "Pinnacle club for division 2 : " << endl;
	while(c != 11) {
		cout << endl;
		cout << "Enter your choice : " << endl;
		cout << "1. Appoint President" << endl;
		cout << "2. Appoint Secretary" << endl;
		cout << "3. Add Member" << endl;
		cout << "4. Remove President" << endl;
		cout << "5. Remove Secretary" << endl;
		cout << "6. Remove Member" << endl;
		cout << "7. Total no of members in the club :" << endl;
		cout << "8. List of members in the club : " << endl;
		cout << "9. List of members in reverse order : " << endl;
		cout << "10. Sorted list of Pinnacle Club." << endl;
		cout << "11. Exit" << endl;
		cin >> c;
		switch(c) {
			case 1:
				l2.InsertPresident();
				break;
			case 2:
				l2.InsertSecretary();
				break;
			case 3:
				l2.InsertMembers();
				break;
			case 4:
				l2.DeletePresident();
				break;
			case 5:
				l2.DeleteSecretary();
				break;
			case 6:
				l2.DeleteMembers();
				break;
			case 7:
				l2.NoOfMembers();
				break;
			case 8:
				cout << "***************** WELCOME TO PINNACLE CLUB *****************" << endl;
				l2.display();
				break;
			case 9:
				cout << "Pinnacle Club List in Reverse Order :" << endl; 
				l2.rev_display(l2.start);
				break;
			case 10:
				cout << "Sorted List : " << endl;
				l2.sort_list();
				break;
		}
	}
	cout << "Concatenated Pinnacle Club List of division 1 & 2 : " << endl;
	l3.count = l1.count + l2.count;
	l.count = l3.count;
	l3.concat_list(l1 , l2);
	l3.display();
	cout << "Merged Sorted Pinnacle Club List of division 1 & 2 : " << endl;
	l.merged_list(l1 , l2);
	l.display();
	return 0;
}
