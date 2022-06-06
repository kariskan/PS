#include <iostream>
using namespace std;

typedef struct node {
	int num;
	struct node* left;
	struct node* right;
}node;

node* root = new node();
void insert(node* n, int val) {
	if (val < n->num) {
		if (n->left == NULL) {
			node* newNode = new node();
			newNode->num = val;
			newNode->left = NULL;
			newNode->right = NULL;
			n->left = newNode;
			return;
		}
		else insert(n->left, val);
	}
	else {
		if (n->right == NULL) {
			node* newNode = new node();
			newNode->num = val;
			newNode->left = NULL;
			newNode->right = NULL;
			n->right = newNode;
			return;
		}
		else insert(n->right, val);
	}
}
void search(node* n) {
	if (n->left != NULL) {
		search(n->left);
	}
	if (n->right != NULL) {
		search(n->right);
	}
	cout << n->num << "\n";
}
int main() {
	int a;
	cin >> a;
	root->num = a;
	root->left = NULL;
	root->right = NULL;
	while (cin >> a) {
		insert(root, a);
	}
	search(root);
}