/*
Queues are frequently used in computer programming, and a typical example is the creation
of a job queue by an operating system. If the operating system uses priorities, then the jobs
are processed based on priority order. Write C++ program for simulating job queue. Write functions
to add job and delete job from queue.
*/

#include <bits/stdc++.h>
using namespace std;
class Queue;
class Node {
	char jobId;
	int pri;
	Node *next;
public:
	Node(char id , int p) {
		pri = p;
		jobId = id;
		next = NULL;
	}
	friend class Queue;
};

class Queue {
	Node *front , *rear;
public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	void getData();
	void jobList(char id , int p);
	void deleteJob();
	void display();
};
void Queue :: getData() {
	char id;
	int p;
	cout << "Enter Job Id & Job Priority : ";
	cin >> id >> p;
	this->jobList(id , p);
}
void Queue :: jobList(char id , int p) {
	Node *t = new Node(id , p);
	if(front == NULL) {
		front = t;
		rear = t;
	}
	else {
		Node *temp = front;
		while(temp) {
			if(t->pri > temp->pri) {
				t->next = front;
				front = t;
				break;
			}
			if(temp->next == NULL){
				rear->next = t;
				rear = rear->next;
				break;
			}
			if(t->pri < temp->pri && t->pri > temp->next->pri){
				t->next = temp->next;
				temp->next = t;
				break;
			}
			temp = temp->next;
		}
	}
}
void Queue :: deleteJob() {
	if(front == NULL) {
		cout << "List is Empty." << endl;
	}
	else if(front->next == NULL) {
		Node *t = front;
		delete(t);
		front = NULL;
		rear = NULL;
		cout << "Deletion Successful!" << endl;
	}
	else {
		Node *t = front;
		front = front->next;
		t->next = NULL;
		delete(t);
		cout << "Deletion Successful!" << endl;
	}
}
void Queue :: display() {
	if(front == NULL) {
		cout << "List is Empty." << endl;
	}
	else {
		Node *temp = front;
		cout << "List of Jobs : " << endl;
		cout << "Job Id\t Priority" << endl; 
		while(temp) {
			cout << setw(3) << temp->jobId << setw(10) << temp->pri << endl;
			temp = temp->next;
		}
	}
}

int main() {
	Queue j;
	int ch;
	while(ch != 4) {
		cout << "Enter your choice : " << endl;
		cout << "1. Enter Job" << endl;
        cout << "2. Display Job List" << endl;
        cout << "3. Delete Job" << endl;
        cout << "4. Exit" << endl;
		cin >> ch;
		switch(ch) {
			case 1:
				j.getData();
				break;
			case 2:
				j.display();
				break;
			case 3:
				j.deleteJob();
				break;
		}
		cout << endl;
	}
	return 0;
}

