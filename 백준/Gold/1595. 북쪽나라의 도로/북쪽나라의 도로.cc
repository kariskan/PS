#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> v(10001);

int maxlen, maxi;

void go(int node, int pre, int sum) {

	if (maxlen < sum) {
		maxlen = sum;
		maxi = node;
	}

	for (auto& i : v[node]) {
		if (i.first != pre) {
			go(i.first, node, sum + i.second);
		}
	}
}

int main() {
	int a, b, c, r = 0;
	while (cin >> a >> b >> c) {
		r = a;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	if (r != 0) {
		go(r, 0, 0);
		go(maxi, 0, 0);
	}

	cout << maxlen;
}