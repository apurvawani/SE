/*
There are flight paths between cities. If there is a flight between city A and city B then there is an edge between
the cities. The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used
for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use
adjacency list representation of the graph or use adjacency matrix representation of the graph. Justify the storage
representation used.(Operation to be performed adding and deleting edge, adding and deleting vertices, calculated
in-degree and out-degree for directed graph and and degree of a node for undirected graph. Use any traversal to
traverse graph).
*/

#include <bits/stdc++.h>
using namespace std;
#define n 20

class Node {
	string city;
	int time;
	Node *next;
public :
	Node(string s) {
		city = s;
		time = 0;
		next = NULL;
	}
	friend class graph;
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


class graph {
	Node* head[20];
public:
	graph() {
		for(int i = 0 ; i < 20 ; i++) {
			head[i] = NULL;
		}
	}
	void addNode();
	void addEdge();
	void display();
	void connection(string q);
	void inDegree(string q);
	void outDegree(string q);
	void bfs_start();
	void bfs(Node *p , bool v[]);
	void dfs_start();
	int search(string k);
	void dfs(Node *p , bool v[]);
};

void graph :: addNode() {
	string s;
	cout << "Enter city name : " << endl;
	cin >> s;
	Node *x = new Node(s);
	int i;
	for(i = 0 ; i < 20 ; i++) {
		if(head[i] == NULL) {
			break;
		}
	}
	head[i] = x;
	cout << "City " << s << " added in the network." << endl;
}

void graph :: addEdge() {
	string c1 ,c2;
	cout << "Enter connection path"<< endl;
	cout << "Source : " << endl;
	cin >> c1;
	int i;
	for(i = 0 ; i < 20 ; i++) {
		if(head[i] != NULL) {
			if(head[i]->city == c1) {
				break;
			}
		}
		else {
			cout << "Source city is not present in the network." << endl;
			return;
		}
	}
	cout << "Destination : " << endl;
	cin >> c2;
	for(int d = 0 ; d < 20 ; d++) {
		if(head[d] != NULL) {
			if(head[d]->city == c2) {
				break;
			}
		}
		else {
			cout << "Destination city is not present in the network." << endl;
			return;
		}
	}
	Node *temp = head[i];
	while(temp->next != NULL) {
		temp = temp->next;
	}
	Node *x = new Node(c2);
	temp->next = x;
	cout << "Enter time required to travel from " << c1 << " to " << c2 << " : ";
	cin >> x->time;
}

void graph :: display() {
	cout << "Network of Cities :" << endl;
	for(int i = 0 ; i < 20 ; i++) {
		if(head[i] == NULL) {
			break;
		}
		else {
			Node *temp = head[i];
			cout << temp->city;
			temp = temp->next;
			while(temp != NULL) {
				cout << "->" << temp->city;
				temp = temp->next;
			}
			cout << endl;
		}
	}
}

void graph :: connection(string q) {
	for(int i = 0 ; i < 20 ; i++) {
		if(head[i] != NULL) {
			if(head[i]->city == q) {
				break;
			}
		}
		else {
			cout << "City " << q << " is not present in the network." << endl;
			return;
		}
	}
	int c = 0;
	while(c < 3) {
		cout << "Enter choice : " << endl;
		cout << "1. Connections from city " << q << endl;
		cout << "2. Connections to city " << q << endl;
		cout << "3. Exit" << endl;
		cin >> c;
		switch(c) {
		case 1:
			outDegree(q);
			break;
		case 2:
			inDegree(q);
			break;
		}
	}
}

void graph :: outDegree(string q) {
	int count = 0 , i;
	for(i = 0 ; i < 20 ; i++) {
		if(head[i]->city == q) {
			break;
		}
	}
	if(i < 20) {
		Node *temp = head[i];
		temp = temp->next;
		while(temp != NULL) {
			count++;
			temp = temp->next;
		}
		cout << count << endl;
	}
}

void graph :: inDegree(string q) {
	int count = 0;
	for(int i = 0 ; i < 20 ; i++) {
		if(head[i] == NULL) {
			break;
		}
		else {
			Node *temp = head[i];
			if(temp->city != q) {
				while(temp != NULL) {
					if(temp->city == q) {
						count++;
					}
					temp = temp->next;
				}
			}
		}
	}
	cout << count << endl;
}

int graph :: search(string k) {
	int i;
	for(i = 0 ; i < 20 ; i++) {
		if(head[i]->city == k) {
			break;
		}
	}
	return i;
}

void graph :: bfs_start() {
	bool visited[20];
	for(int i = 0 ; i < 20 ; i++) {
		visited[i] = false;
	}
	bfs(head[0] , visited);
	cout << endl;
}

void graph :: bfs(Node *p , bool v[]) {
	Queue q;
	q.enqueue(p);
	int index = search(p->city);
	v[index] = true;
	cout << p->city << " ";
	while(!q.isempty()) {
		Node *temp = q.dequeue();
		index = search(temp->city);
		temp = head[index];
		while(temp != NULL) {
			int j = search(temp->city);
			if(v[j] == false) {
				cout << temp->city << " ";
				q.enqueue(temp);
				v[j] = true;
			}
			temp = temp->next;
		}
	}
}

void graph :: dfs_start() {
	bool visited[20];
	for(int i = 0 ; i < 20 ; i++) {
		visited[i] = false;
	}
	dfs(head[0] , visited);
}

void graph :: dfs(Node *p , bool v[]) {
	int index = search(p->city);
	cout << p->city << " ";
	v[index] = true;
	Node *temp = head[index]->next;
	while(temp != NULL) {
		int j = search(temp->city);
		if(v[j] == false) {
			dfs(temp , v);
		}
		temp = temp->next;
	}
}

int main() {
	graph G;
	int ch = 0;
	string q;
	while(ch < 7) {
		cout << "Enter choice : " << endl;
		cout << "1. Add new city in the network" << endl;
		cout << "2. Add new connection between two cities" << endl;
		cout << "3. Find number of connections of a city" << endl;
		cout << "4. Display" << endl;
		cout << "5. BFS Traversal" << endl;
		cout << "6. DFS Traversal" << endl;
		cout << "7. Exit" << endl;
		cin >> ch;
		switch(ch) {
		case 1:
			G.addNode();
			break;
		case 2:
			G.addEdge();
			break;
		case 3:
			cout << "Enter city : ";
			cin >> q;
			G.connection(q);
			break;
		case 4 :
			G.display();
			break;
		case 5:
			G.bfs_start();
			break;
		case 6 :
			G.dfs_start();
			cout << endl;
			break;
		}
	}
	return 0;
}
