#include <iostream>
#include <set>
using namespace std;
int n, m;
set<string> ans;
int tree[5000000];
void insert(int idx, int num) {
	while (tree[idx]) {
		tree[idx] < num ? idx = idx * 2 + 1 : idx *= 2;
	}
	tree[idx] = num;
}

void del(int idx) {
	if (!tree[idx])return;
	tree[idx] = 0;
	del(idx * 2);
	del(idx * 2 + 1);
}

string pre(int idx) {
	string t = "V";
	if (tree[idx * 2]) {
		t += "l" + pre(idx * 2) + "L";
	}
	if (tree[idx * 2 + 1]) {
		t += "r" + pre(idx * 2 + 1) + "R";
	}
	return t;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			insert(1, a);
		}
		ans.insert(pre(1));
		del(1);
	}
	cout << ans.size();
}