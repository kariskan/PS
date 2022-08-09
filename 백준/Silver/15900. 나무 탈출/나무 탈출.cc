#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int n, ans;

void go(int node, int pre, int depth) {

	bool ok = false;
	for (auto& i : v[node]) {
		if (i != pre) {
			ok = true;
			go(i, node, depth + 1);
		}
	}

	if (!ok) {
		ans += depth;
	}
}

int main() {

	cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	go(1, 0, 0);

	if (ans % 2 == 0)cout << "No";
	else cout << "Yes";
}