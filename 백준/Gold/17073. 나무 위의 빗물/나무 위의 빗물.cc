#include <iostream>
#include <vector>
using namespace std;

int n, w, cnt;
vector<vector<int>> v;

void go(int node, int pre) {
	int ok = 0;
	for (auto& i : v[node]) {
		if (i != pre) {
			ok = 1;
			go(i, node);
		}
	}
	if (!ok)cnt++;
}

int main() {
	cin >> n >> w;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	go(1, 0);

	cout.precision(6);
	cout << fixed << (double)w / (double)cnt;
}