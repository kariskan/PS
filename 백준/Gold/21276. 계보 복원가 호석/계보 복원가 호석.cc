#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
map<string, vector<string>> v, inv;
map<string, int> ind;
vector<string> inp;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		inp.push_back(s);
	}

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		string s1, s2; cin >> s1 >> s2;
		inv[s2].push_back(s1);
		ind[s1]++;
	}

	vector<string> start;
	queue<string> q;

	for (auto& i : inp) {
		if (ind.count(i) == 0) {
			q.push(i);
			start.push_back(i);
		}
	}

	cout << start.size() << '\n';
	sort(start.begin(), start.end());
	for (auto& i : start) {
		cout << i << ' ';
	}
	cout << '\n';

	while (!q.empty()) {
		string s = q.front();
		q.pop();

		for (auto& i : inv[s]) {
			ind[i]--;
			if (ind[i] == 0) {
				q.push(i);
				v[s].push_back(i);
			}
		}
	}

	sort(inp.begin(), inp.end());

	for (auto& i : inp) {
		cout << i << ' ' << v[i].size() << ' ';
		for (auto& j : v[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}