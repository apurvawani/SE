//============================================================================
// Name        : GroupA_03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
Create an inordered threaded binary tree and perform inorder and
preorder traversals. Analyze time and space complexity of the
algorithm.
*/
#include <bits/stdc++.h>
using namespace std;
#define n 100

class Node {
	int data;
	bool l_bit , r_bit;
	Node *l_child , *r_child;
public:
	Node(int d) {
		l_child = r_child = NULL;
		data = d;
		l_bit = r_bit = false;
	}
	friend class TBT;
};

class Queue {
	Node* arr[n];
	int front , rear;
public:
	Queue() {
		front = rear = -1;
	}
	void enqueue(Node *t) {
		rear = (rear + 1 + n) % n;
		arr[rear] = t;
	}
	Node *dequeue() {
		front = (front + 1 + n) %n;
		return arr[front];
	}
	bool isfull() {
		if(front > rear || (rear == n-1 && front == 0)) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isempty() {
		if((rear == -1 && front == -1) || rear == front) {
			return true;
		}
		else {
			return false;
		}
	}
};

class TBT {
	Node *head;
public:
	TBT() {
		head = new Node(0);
		head->r_bit = false;
		head->r_child = head;
		head->l_child = head;
	}
	void l_insert(Node *x , Node *y);
	void r_insert(Node *x , Node *y);
	void insert();
	void display();
	Node *leftmost(Node *p);
	void inorder(Node *x);
	void preorder(Node *x);
};

void TBT :: l_insert(Node *x , Node *y) {
	y->l_bit = x->l_bit;
	y->l_child = x->l_child;
	y->r_child = x;
	x->l_child = y;
	x->l_bit = true;
}

void TBT :: r_insert(Node *x , Node *y) {
	y->r_bit = x->r_bit;
	y->r_child = x->r_child;
	y->l_child = x;
	x->r_child = y;
	x->r_bit = true;
}

void TBT :: insert() {
	int d;
	char c;
	Queue q;
	Node *temp;
	cout << "Enter first node : ";
	cin >> d;
	temp = new Node(d);
	head->l_bit = true;
	head->l_child = temp;
	temp->l_child = head;
	temp->r_child = head;
	q.enqueue(temp);
	while(!q.isempty()) {
		temp = q.dequeue();
		cout << "Do you want to add a left child of " << temp->data << "?(Y/N)" << endl;
		cin >> c;
		if(c == 'Y') {
			cout << "Enter data : ";
			cin >> d;
			Node *cur = new Node(d);
			l_insert(temp , cur);
			q.enqueue(temp->l_child);
		}
		cout << "Do you want to add a right child of " << temp->data << "?(Y/N)" << endl;
		cin >> c;
		if(c == 'Y') {
			cout << "Enter data : ";
			cin >> d;
			Node *cur = new Node(d);
			r_insert(temp , cur);
			q.enqueue(temp->r_child);
		}
	}
}

void TBT :: display() {
	int ch;
	cout << "Select display order : " << endl;
	cout << "1. Inorder" << endl;
	cout << "2. Preorder" << endl;
	cin >> ch;
	switch(ch) {
	case 1 :
		inorder(head);
		break;
	case 2:
		preorder(head);
		break;
	}
}

Node* TBT :: leftmost(Node *p) {
	if(p == NULL) {
		return p;
	}
	else {
		while(p->l_bit != 0) {
			p = p->l_child;
		}
		return p;
	}
}

void TBT :: inorder(Node *x) {
	Node *temp = leftmost(x);
	while(temp != head) {
		cout << temp->data << " ";
		if(!temp->r_bit) {
			temp = temp->r_child;
		}
		else {
			temp = leftmost(temp->r_child);
		}
	}
	cout << endl;
}

void TBT :: preorder(Node *x) {
	x = x->l_child;
	while(x != head) {
		cout << x->data << " ";
		if(x->l_bit != 0) {
			x = x->l_child;
		}
		else {
			while(x->r_bit == 0 && x->r_child != head) {
				x = x->r_child;
			}
			x = x->r_child;
		}
	}
	cout << endl;
}

int main() {
	TBT t;
	int ch = 0;
	while(ch < 3) {
		cout << "Enter Choice : " << endl;
		cout << "1. Add Element" << endl;
		cout << "2. Display" << endl;
		cout << "3. Exit" << endl;
		cin >> ch;
		switch(ch) {
		case 1:
			t.insert();
			break;
		case 2:
			t.display();
			break;
		}
	}
	return 0;
}

