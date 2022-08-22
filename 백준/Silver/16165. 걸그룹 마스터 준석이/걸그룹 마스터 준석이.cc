#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<string, vector<string>> g;
	map<string, string> p;

	for (int i = 0; i < n; i++) {
		string group; cin >> group;
		int num; cin >> num;

		for (int j = 0; j < num; j++) {
			string s; cin >> s;
			p[s] = group;
			g[group].push_back(s);
		}
		sort(g[group].begin(), g[group].end());
	}

	for (int i = 0; i < m; i++) {
		string s; int num;
		cin >> s >> num;
		if (num == 1) {
			cout << p[s] << '\n';
		}
		else {
			for (int j = 0; j < g[s].size(); j++) {
				cout << g[s][j] << '\n';
			}
		}
	}
}