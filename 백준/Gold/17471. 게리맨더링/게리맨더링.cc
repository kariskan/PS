#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, pop[11];
vector<vector<int>> v;
int selectVisit[11];
int totalSum;
int ans = -1;
bool can() {
	int tempVisit[11] = { 0, };
	for (int k = 1; k <= n; k++) {
		if (selectVisit[k] == 1) {
			int role = selectVisit[k];
			queue<int> q;
			q.push(k);
			tempVisit[k] = 1;
			while (!q.empty()) {
				int a = q.front(); q.pop();

				for (int i = 0; i < v[a].size(); i++) {
					int next = v[a][i];
					if (!tempVisit[next] && role == selectVisit[next]) {
						tempVisit[next] = 1;
						q.push(next);
					}
				}
			}
			break;
		}
	}
	for (int k = 1; k <= n; k++) {
		if (selectVisit[k] == 0) {
			int role = selectVisit[k];
			queue<int> q;
			q.push(k);
			tempVisit[k] = 1;
			while (!q.empty()) {
				int a = q.front(); q.pop();

				for (int i = 0; i < v[a].size(); i++) {
					int next = v[a][i];
					if (!tempVisit[next] && role == selectVisit[next]) {
						tempVisit[next] = 1;
						q.push(next);
					}
				}
			}
			break;
		}
	}
	for (int k = 1; k <= n; k++) {
		if (!tempVisit[k])return false;
	}
	return true;
}

void selectPeople(int idx, int cnt) {
	if (cnt == n)return;
	if (cnt != 0 && can()) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (selectVisit[i]) {
				sum += pop[i];
			}
		}
		if (ans == -1 || ans > abs(2 * sum - totalSum)) {
			ans = abs(2 * sum - totalSum);
		}
	}
	for (int i = idx; i <= n; i++) {
		if (!selectVisit[i]) {
			selectVisit[i] = 1;
			selectPeople(i + 1, cnt + 1);
			selectVisit[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> pop[i];
		totalSum += pop[i];
	}
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			v[i].push_back(b);
		}
	}
	selectPeople(1, 0);
	cout << ans;
}