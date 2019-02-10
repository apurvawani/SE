/*
Given binary tree with n nodes, perform following operations on it:
1.Perform preorder , inorder , postorder traversal
2.Create a mirror image of it
3. Find the height of tree
4. Copy this tree to another [operator=]
5. Count number of leaves, number of internal nodes.
6.Erase all nodes in a binary tree. 
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
	int data;
	Node *lchild;
	Node *rchild;
public :
	Node(int d) {
		data = d;
		lchild = rchild = NULL;
	}
	friend class tree;
};

class tree {
	Node *root;
public :
	tree() {
		root = NULL;
	}
	void createRoot();
	void makeTree(Node *x);
	void display();
	void preOrder(Node *t);
	void inOrder(Node *t);
	void postOrder(Node *t);
	void start_mI();
	void mirrorImage(Node *x);
	void start_h();
	int height(Node *x);
	void start_Lcount();
	int noOfLeaves(Node *x);
	void start_INcount();
	int noOfInt_nodes(Node *x);
	void operator = (tree T);
	void copy(Node *x , Node *y);
	void start_erase();
	void erase(Node *x);
};

void tree :: createRoot() {
	int d;
	cout << "Enter Root : ";
	cin >> d;
	root = new Node(d);
	makeTree(root);
}
void tree :: makeTree(Node *x) {
	char ch;
	int d;
	cout << "Do you want to insert left child of " << x->data << " ?(y/n)" << endl;
	cin >> ch;
	if(ch == 'y') {
		cout << "Enter data : " << endl;
		cin >> d;
		Node *l = new Node(d);
		x->lchild = l;
		makeTree(l);
	}
	cout << "Do you want to insert right child of " << x->data << " ?(y/n)" << endl;
	cin >> ch;
	if(ch == 'y') {
		cout << "Enter data : " << endl;
		cin >> d;
		Node *r = new Node(d);
		x->rchild = r;
		makeTree(r);
	}
}

void tree :: display() {
	if(root == NULL) {
		cout << "Tree does not exist!" << endl;
	}
	else {
		int c;
		cout << "Enter your choice : " << endl;
		cout << "1. PreOrder" << endl << "2. PostOrder" << endl << "3. InOrder" << endl;
		cin >> c;
		switch(c) {
		case 1:
			preOrder(root);
			break;
		case 2:
			postOrder(root);
			break;
		case 3:
			inOrder(root);
		}
	}
}

void tree :: preOrder(Node *t) {
	if(t == NULL) {
		return;
	}
	cout << t->data << " ";
	preOrder(t->lchild);
	preOrder(t->rchild);
}

void tree :: inOrder(Node *t) {
	if(t != NULL) {
		inOrder(t->lchild);
		cout << t->data << " ";
		inOrder(t->rchild);
	}
}

void tree :: postOrder(Node *t) {
	if(t == NULL) {
		return;
	}
	postOrder(t->lchild);
	postOrder(t->rchild);
	cout << t->data << " ";
}

void tree :: start_mI() {
	int c;
	mirrorImage(root);
	cout << "How do you want to display image?" << endl;
	cout << "1. PreOrder" << endl << "2.PostOrder" << endl << "3.InOrder" << endl;
	cin >> c;
	switch(c) {
	case 1:
		preOrder(root);
		break;
	case 2:
		postOrder(root);
		break;
	case 3:
		inOrder(root);
	}
}

void tree :: mirrorImage(Node *x) {
	if(x == NULL) {
		return;
	}
	if(x->lchild == NULL && x->rchild == NULL) {
		return;
	}
	else {
		Node *temp;
		temp = x->lchild;
		x->lchild = x->rchild;
		x->rchild = temp;
	}
	mirrorImage(x->lchild);
	mirrorImage(x->rchild);
}

void tree :: start_h(){
	cout << "Height Of the Tree : " << height(root) << endl;
}

int tree :: height(Node *x) {
	int h1 = 1 , h2 = 1;
	if(x == NULL) {
		return 0;
	}
	if(x->lchild != NULL || x->rchild != NULL) {
		h1 += height(x->lchild);
	}
	if(x->lchild != NULL || x->rchild != NULL) {
		h2 += height(x->rchild);
	}
	return (h1 > h2) ? h1 : h2;
}

void tree :: start_Lcount(){
	cout << "Number Of Leaves : " << noOfLeaves(root) << endl;
}

int tree :: noOfLeaves(Node *x) {
	int l = 0;
	if(x == NULL) {
		return l;
	}
	else if(x->lchild == NULL && x->rchild == NULL) {
		l += 1;
	}
	else {
		l += noOfLeaves(x->lchild);
		l += noOfLeaves(x->rchild);
	}
	return l;
}

void tree :: start_INcount(){
	cout << "Number Of Internal Nodes : " << noOfInt_nodes(root) << endl;
}

int tree :: noOfInt_nodes(Node *x) {
	int l = 0;
	if(x == NULL) {
		return l;
	}
	else if(x->lchild != NULL || x->rchild != NULL) {
		l += 1;
	}
	l += noOfInt_nodes(x->lchild);
	l += noOfInt_nodes(x->rchild);
	return l;
}

void tree :: operator = (tree T) {
	if(T.root == NULL) {
		cout << "Tree does not exist!" << endl;
	}
	else {
		root = new Node(T.root->data);
		copy(T.root , root);
	}
	cout << "Tree copying finished." << endl;
}

void tree :: copy(Node *x , Node *y) {
	if(x == NULL) {
		return;
	}
	if(x->lchild == NULL && x->rchild  == NULL) {
		return;
	}
	else {
		if(x->lchild != NULL) {
			Node *l = new Node(x->lchild->data);
			y->lchild = l;
		}
		if(x->rchild != NULL) {
			Node *r = new Node(x->rchild->data);
			y->rchild = r;
		}
	}
	copy(x->lchild , y->lchild);
	copy(x->rchild , y->rchild);
}

void tree :: start_erase() {
	char c;
	cout << "Do you want completely remove the tree?(Y/N)" << endl;
	cin >> c;
	if(c == 'Y') {
		erase(root);
		root = NULL;
	}
	else {
		return;
	}
}

void tree :: erase(Node *x) {
	if(x == NULL) {
		return;
	}
	else {
		erase(x->lchild);
		erase(x->rchild);
		delete(x);
	}
}

int main() {
	tree T , T1;
	int choice = 0;
	while(choice < 9) {
		cout << endl;
		cout << "Choose the Operation : " << endl;
		cout << "1. Create Tree" << endl;
		cout << "2. Display Tree" << endl;
		cout << "3. Mirror Image Of Tree" << endl;
		cout << "4. Height Of Tree" << endl;
		cout << "5. No Of Leaves" << endl;
		cout << "6. No Of Internal Nodes" << endl;
		cout << "7. Copy tree to another tree" << endl;
		cout << "8. Erase Tree" << endl;
		cout << "9. Exit" << endl;
		cin >> choice;
		switch(choice) {
		case 1 :
			T.createRoot();
			break;
		case 2:
			T.display();
			break;
		case 3:
			T.start_mI();
			break;
		case 4:
			T.start_h();
			break;
		case 5:
			T.start_Lcount();
			break;
		case 6:
			T.start_INcount();
			break;
		case 7:
			T1 = T;
			T1.display();
			break;
		case 8:
			T.start_erase();
			cout << "Tree deleted successfully!" << endl;
			break;
		}
	}
	return 0;
}

