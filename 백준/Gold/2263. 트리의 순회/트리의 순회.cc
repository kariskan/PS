#include <iostream>
using namespace std;
int in[100001];
int post[100001];
int visit[100001];

void root(int inLeft, int inRight, int postLeft, int postRight) {
	if (inLeft > inRight || postLeft > postRight) return;
	int rootIdx = visit[post[postRight]];
	int leftSize = rootIdx - inLeft;
	int rightSize = inRight - rootIdx;
	cout << in[rootIdx] << " ";
	root(inLeft, rootIdx - 1, postLeft, postLeft + leftSize - 1);
	root(rootIdx + 1, inRight, postLeft + leftSize, postRight - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> in[i];
		visit[in[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> post[i];
	}
	root(1, n, 1, n);
}