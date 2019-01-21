#include <iostream>
#include <string>
using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;
	Node *parent;
};

class BST{
public:
enum order{inorder, preorder, postorder};
	
BST (){root = NULL;};
//p.294
void treeInsert(int key){
	Node *x;
	x = root;
	Node *y = NULL;
	Node *z = new Node();
	
	while(x != NULL) {
		y = x;
		if(key < x->value) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	
	z->parent = y;
	z->value = key;
	z->left = NULL;
	z->right = NULL;
	
	if(y == NULL)
		root = z;
	else if (z->value < y->value)
		y->left = z;
	else
		y->right = z;	
}

//p.298
void treeDelete(int key) {
	Node *z = new Node();
	Node *y = new Node();
	z = treeSearch(key);
	
	if(z == NULL)
		return;
	if(z->left == NULL)
		transplant(z,z->right);
	else if(z->right == NULL)
		transplant(z,z->left);
	else {
		y = treeMin(z->right);
		
		if(y->parent != z) {
			transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		
		transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}		

}

Node* treeSearch(int key) {
	Node *x = root;
	while(x!= NULL && key != x->value) {
		if(key < x->value)
			x = x->left;
		else
			x = x->right;
	}
	if(x == NULL || key != x->value)
		return x;
		
	return x;
}		

//P.296
void transplant(Node *u, Node *v) {
	if(u->parent == NULL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;

}

//p.288
void inOrder(Node *x) {
	if (x != NULL) {
		inOrder(x->left);
		cout << x->value << endl;
		inOrder(x->right);
	}
}

//P.291
Node* treeMin(Node *x) {
	while(x->left != NULL)
		x = x->left;
	return x;
}

void preOrder(Node *x) {
	if(x!= NULL) {
		cout << x->value << endl;
		preOrder(x->left);
		preOrder(x->right);
	}
}

void postOrder(Node *x) {
	if(x != NULL) {
		postOrder(x->left);
		postOrder(x->right);
		cout << x->value << endl;
	}
}


void print(order travorder){
	if(travorder == inorder)
		inOrder(root);
	if(travorder == preorder)
		preOrder(root);
	if(travorder == postorder)
		postOrder(root);
}

private:

Node *root;
};


int main(){

BST tree;

int key;
string str;


do {
	
	cin >> str;	
	if(str[0] == 'p' && str[1] == 'r' && str[2] == 'e') {
		tree.print(BST::preorder);
		cout << "++++++++++++++++++++" << endl;
		
		
	}
	else {
		if(str[0] == 'p' && str[1] == 'o' && str[2] == 's' &&  str[3] == 't') {
			tree.print(BST::postorder);
			cout << "++++++++++++++++++++" << endl;
			
		}
	
	
	else {
		if(str[0] == 'i' && str[1] == 'n') {
			tree.print(BST::inorder);
			cout << "++++++++++++++++++++" << endl;
				
		}
	else{
		if(str[0] == 'i') {
			cin >> key;
			tree.treeInsert(key);
		}
		if(str[0] == 'd') {
			cin >> key;
			tree.treeDelete(key);
		}
	}
	}
}
}while(str[0] != 'e');


return 0;
}
