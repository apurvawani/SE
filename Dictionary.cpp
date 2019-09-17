/*
A Dictionary stores keywords & its meanings. Provide facility for
adding new keywords, deleting keywords, updating values of any
entry, assign a given tree into another tree (=). Provide facility to
display whole data sorted in ascending/ Descending order. Also
find how many maximum comparisons may require for finding
any keyword. Use Binary Search Tree for implementation.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
	string keyword;
	string meaning[10];
	int count;
	Node *l;
	Node *r;
public :
	Node() {
		count = 0;
		l = r = NULL;
		keyword = " ";
		meaning[10] = {" "};
	}
	Node(string s) {
		count = 0;
		keyword = s;
		cout << "How many meanings you want to add?(max 10)" << endl;
		cin >> count;
		cout << "Enter meanings : " << endl;
		for(int k = 0 ; k < count ; k++) {
			cin.ignore();
			getline(cin , meaning[k]);
		}
		l = r = NULL;
	}
	friend class Dictionary;
};

class Dictionary {
	Node *root;
public:
	Dictionary() {
		root = NULL;
	}
	void Add_root();
	Node *Add_Word(Node *x , string s);
	void display();
	void ascending(Node *x);
	void descending(Node *x);
	Node *max_node(Node *x);
	void start_remove(string p);
	Node *remove(Node *x , string p);
	void start_update(string p);
	void update(Node *x , string p);
	void operator=(Dictionary d);
	void copy(Node *x , Node *y);
};

void Dictionary :: Add_root() {
	string s;
	cout << "Enter keyword : ";
	cin.ignore();
	getline(cin , s);
	if(root == NULL) {
		root = new Node(s);
	}
	else {
		root = Add_Word(root , s);
	}
	cout << "Word added to dictionary." << endl;
}

Node* Dictionary :: Add_Word(Node *x , string s) {
	if(x == NULL) {
		x = new Node(s);
	}
	else {
		if(x->keyword < s) {
			x->r = Add_Word(x->r , s);
		}
		else if(x->keyword > s){
			x->l = Add_Word(x->l , s);
		}
	}
	return x;
}

void Dictionary :: display() {
	if(root == NULL) {
		cout << "Dictionary does not exist!" << endl;
	}
	else {
		int c;
		cout << "Enter your choice : " << endl;
		cout << "1. Ascending Order" << endl << "2. Descending Order" << endl;
		cin >> c;
		switch(c) {
		case 1:
			ascending(root);
			break;
		case 2:
			descending(root);
			break;
		}
	}
}

void Dictionary :: ascending(Node *x) {
	if(x != NULL) {
		ascending(x->l);
		cout << x->keyword << " : " << endl;
		for(int k = 0 ; k < x->count ; k++) {
			cout << k+1 << ". " << x->meaning[k] << endl;
		}
		cout << endl;
		ascending(x->r);
	}
}

void Dictionary :: descending(Node *x) {
	if(x != NULL) {
		descending(x->r);
		cout << x->keyword << " : " << endl;
		for(int k = 0 ; k < x->count ; k++) {
			cout << k+1 << ". " << x->meaning[k] << endl;
		}
		cout << endl;
		descending(x->l);
	}
}

void Dictionary :: start_update(string p) {
	update(root , p);
	cout << "Meaning of keyword " << p << " successfully updated." << endl;
}

void Dictionary :: update(Node *x , string p) {
	if(x->keyword == p) {
		string m;
		cout << "Want to add new meaning? Enter meaning : ";
		cin.ignore();
		getline(cin , m);
		x->meaning[x->count] = m;
		x->count++;
		return;
	}
	else if(x->keyword < p) {
		update(x->r , p);
	}
	else {
		update(x->l , p);
	}
}

Node *Dictionary :: max_node(Node *x) {
	while(x->r != NULL) {
		x = x->r;
	}
	return x;
}

void Dictionary :: start_remove(string p) {
	if(root == NULL) {
		cout << "Nothing to delete!" << endl;
	}
	else {
		root = remove(root , p);
		cout << "Keyword " << p << " successfully deleted." << endl;
	}
}

Node *Dictionary :: remove(Node *x , string p) {
	if(x == NULL)
		return x;
	if(x->keyword > p) {
		x->l = remove(x->l , p);
	}
	else if(x->keyword < p) {
		x->r = remove(x->r , p);
	}
	else {
		if(x->l == NULL) {
			Node *temp = x->r;
			delete x;
			return temp;
		}
		if(x->r == NULL) {
			Node *temp = x->l;
			delete x;
			return temp;
		}
		else {
			Node *temp = max_node(x->l);
			x->keyword = temp->keyword;
			int j = 0 , i = 0;
			while(i < x->count) {
				x->meaning[i] = " ";
				i++;
			}
			while(j < temp->count) {
				x->meaning[j] = temp->meaning[j];
				j++;
			}
			x->l = remove(x->l , temp->keyword);
		}
	}
	return x;
}

void Dictionary :: operator=(Dictionary d) {
	if(d.root == NULL) {
		cout << "Dictionary Does not exist." << endl;
	}
	else {
		root = new Node();
		root->keyword = d.root->keyword;
		for(int i = 0 ; i < d.root->count ; i++) {
			root->meaning[i] = d.root->meaning[i];
		}
		copy(d.root , root);
	}
	cout << "Tree copying finished." << endl;
}

void Dictionary :: copy(Node *x , Node *y) {
	cout << "Copying process initiated." << endl;
	if(x == NULL) {
		return;
	}
	if(x->l == NULL && x->r == NULL) {
		return;
	}
	else {
		if(x->l != NULL) {
			Node *p = new Node();
			p->keyword = x->l->keyword;
			for(int i = 0 ; i < x->l->count ; i++) {
				p->meaning[i] = x->l->meaning[i];
			}
			y->l = p;
			cout << "y-l : " << y->l->keyword << endl;
		}
		if(x->r != NULL) {
			Node *q = new Node();
			q->keyword = x->r->keyword;
			for(int i = 0 ; i < x->r->count ; i++) {
				q->meaning[i] = x->r->meaning[i];
			}
			y->r = q;
			cout << "y-r : " << y->r->keyword << endl;
		}
	}
	copy(x->l , y->l);
	copy(x->r , y->r);
}

int main() {
	Dictionary d , d1;
	string p;
	int ch = 0;
	while(ch < 6) {
		cout << endl;
		cout << "Enter choice : " << endl;
		cout << "1. Add keywords" << endl;
		cout << "2. Display" << endl;
		cout << "3. Update Keyword" << endl;
		cout << "4. Delete Keyword" << endl;
		cout << "5. Copy Dictionary" << endl;
		cout << "6. Exit" << endl;
		cin >> ch;
		switch(ch) {
		case 1:
			d.Add_root();
			break;
		case 2:
			d.display();
			break;
		case 3:
			cout << "Enter Keyword to be updated : ";
			cin >> p;
			d.start_update(p);
			break;
		case 4:
			cout << "Enter Keyword to be deleted : ";
			cin >> p;
			d.start_remove(p);
			break;
		case 5:
			d1 = d;
			d1.display();
			break;
		}
	}
	return 0;
}
