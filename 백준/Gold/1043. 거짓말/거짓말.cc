#include <iostream>
#include <vector>
using namespace std;

int n, m, t;
bool truth[51];
int map[51][51];
int visit[51];
bool ans[51];
vector<vector<int>> party;
void run(int idx) {
	ans[idx] = true;
	for (int i = 1; i <= n; i++) {
		if (!visit[i] && (map[idx][i] || map[i][idx])) {
			visit[i] = 1;
			run(i);
		}
	}
}

int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		truth[a] = true;
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		vector<int> v;
		for (int j = 0; j < a; j++) {
			int k; cin >> k;
			v.push_back(k);
		}
		party.push_back(v);
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < a; k++) {
				map[v[j]][v[k]] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (truth[i]) {
			visit[i] = 1;
			run(i);
		}
	}
	int answer = 0;
	int ok = 1;
	for (int i = 0; i < party.size(); i++) {
		ok = 1;
		for (int j = 0; j < party[i].size(); j++) {
			if (ans[party[i][j]]) {
				ok = 0;
				break;
			}
		}
		if (ok)answer++;
	}
	cout << answer;
}