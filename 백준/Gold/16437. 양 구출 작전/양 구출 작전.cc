#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v;
long long w[123457], s[123457];

long long go(int node, int pre) {

	long long ret = s[node];
	long long k = w[node];

	for (auto& i : v[node]) {
		if (i != pre) {
			ret += go(i, node);
		}
	}

	if (ret > k) {
		return ret - k;
	}
	return 0;
}

int main() {

	cin >> n;
	v.resize(n + 1);

	for (int i = 2; i <= n; i++) {
		char c; int a, b;
		cin >> c >> a >> b;

		if (c == 'S') {
			s[i] = a;
		}
		else {
			w[i] = a;
		}

		v[i].push_back(b);
		v[b].push_back(i);
	}

	cout << go(1, 0);
}