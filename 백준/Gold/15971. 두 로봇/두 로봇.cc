#include <iostream>
#include <vector>
using namespace std;

int n, s, d;
vector<vector<pair<int, int>>> v;
bool ok = false;
vector<int> route;

void getRoute(int node, int pre) {
	if (node == d) {
		ok = true;
		return;
	}

	for (auto& i : v[node]) {
		if (i.first != pre) {
			route.push_back(i.first);
			getRoute(i.first, node);
			if (ok)return;
			route.pop_back();
		}
	}
}

int main() {

	cin >> n >> s >> d;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	if (s > d)swap(s, d);
	
	getRoute(s, 0);

	int total = 0, m = 0;

	for (int i = 0; i < route.size(); i++) {
		for (int j = 0; j < v[s].size(); j++) {
			if (v[s][j].first == route[i]) {
				total += v[s][j].second;
				m = max(m, v[s][j].second);
				s = v[s][j].first;
				break;
			}
		}
	}

	cout << total - m;
}