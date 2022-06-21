#include <iostream>
using namespace std;

int pre[1000], in[1000], rootIdx[1000];
int n;

int findRoot(int v) {
	for (int i = 0; i < n; i++) {
		if (in[i] == v)return i;
	}
}

void go(int preLeft, int preRight, int inLeft, int inRight) {
	
	if (preLeft > preRight || inLeft > inRight)return;

	int root = findRoot(pre[preLeft]);
	go(preLeft + 1, preLeft + root - inLeft, inLeft, root - 1); //왼쪽 서브트리
	go(preLeft + root - inLeft + 1, preRight, root + 1, inRight); //오른쪽 서브트리
	cout << in[root] << " ";
	
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> pre[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> in[i];
		}
		go(0, n - 1, 0, n - 1);
		cout << '\n';
	}

}