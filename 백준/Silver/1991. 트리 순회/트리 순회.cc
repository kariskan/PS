#include <iostream>
using namespace std;
int n;
typedef struct tree {
	char left;
	char right;
}tree;
tree t[27];
char roo[27];
char findRoot(char c) {
	if (roo[c])return findRoot(roo[c]);
	return c;
}
void pre(char c) {
	cout << c;
	if(t[c-'a'].left!='.') pre(t[c - 'a'].left);
	if (t[c - 'a'].right != '.') pre(t[c - 'a'].right);
}
void mid(char c) {
	if (t[c - 'a'].left != '.') mid(t[c - 'a'].left);
	cout << c;
	if (t[c - 'a'].right != '.') mid(t[c - 'a'].right);
}
void post(char c) {
	if (t[c - 'a'].left != '.') post(t[c - 'a'].left);
	if (t[c - 'a'].right != '.') post(t[c - 'a'].right);
	cout << c;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') {
			roo[b] = a;
		}
		if (c != '.') {
			roo[c] = a;
		}
		t[a - 'a'].left = b;
		t[a - 'a'].right = c;
	}
	char root = findRoot('A');
	pre(root);
	cout << "\n";
	mid(root);
	cout << "\n";
	post(root);
	cout << "\n";
}