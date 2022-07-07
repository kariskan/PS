#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[600001] = { 0, };
typedef struct list {
	char value;
	struct list* left;
	struct list* right;
}listnode;
listnode* root;

int main() {
	scanf("%s", &a);
	int lena = strlen(a);
	listnode* cursor = (listnode*)malloc(sizeof(listnode));
	root = (listnode*)malloc(sizeof(listnode));
	root->right = NULL;
	root->left = NULL;
	cursor->left = NULL;
	cursor->right = NULL;
	cursor = root;
	for (int i = 0; i < lena; i++) {
		listnode* newnode = (listnode*)malloc(sizeof(listnode));
		newnode->value = a[i];
		cursor->right = newnode;
		newnode->left = cursor;
		cursor = cursor->right;
	}
	int n;
	cursor->right = NULL;
	scanf("%d", &n); getchar();
	for (int i = 0; i < n; i++) {
		char k;
		scanf("%c", &k);
		getchar();
		if (k == 'P') {
			char b;
			scanf("%c", &b);
			getchar();
			listnode* newnode = (listnode*)malloc(sizeof(listnode));
			newnode->value = b;
			newnode->left = NULL;
			newnode->right = NULL;
			newnode->right = cursor->right;
			if (newnode->right)
				newnode->right->left = newnode;
			cursor->right = newnode;
			newnode->left = cursor;
			cursor = newnode;
		}
		else {
			if (k == 'L') {
				if (cursor == root)continue;
				cursor = cursor->left;
			}
			else if (k == 'D') {
				if (cursor->right)
					cursor = cursor->right;
			}
			else {
				if (cursor == root) {
					continue;
				}
				else {
					cursor->left->right = cursor->right;
					if (cursor->right)
						cursor->right->left = cursor->left;
					cursor = cursor->left;
				}
			}
		}
	}
	listnode* t = root->right;
	while (t) {
		printf("%c", t->value);
		t = t->right;
	}
}