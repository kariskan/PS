#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n, root;
vector<vector<pair<int, int>>> v;
vector<tuple<int, int, int>> inp;
long long s;
void go(int node, int pre, long long sum, int no) {
	if (s < sum) {
		s = sum;
		root = node;
	}
	for (auto& i : v[node]) {
		if (i.first != pre && i.first != no) {
			go(i.first, node, sum + i.second, no);
		}
	}
}

long long getdis(int r, int c) {
	root = r;
	s = 0;
	go(r, -1, 0, c);
	s = 0;
	go(root, -1, 0, c);
	return s;
}

int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		inp.push_back({ a,b,c });
	}

	long long ans = 0;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		tie(a, b, c) = inp[i];
		ans = max(ans, getdis(a, b) + getdis(b, a) + c);
	}

	cout << ans;
}