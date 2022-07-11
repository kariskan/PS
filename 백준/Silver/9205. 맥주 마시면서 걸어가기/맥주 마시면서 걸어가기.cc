#include <iostream>
#include <queue>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pair<int, int> map[102];
		cin >> map[0].first >> map[0].second;
		for (int i = 1; i <= n; i++) {
			cin >> map[i].first >> map[i].second;
		}
		cin >> map[n + 1].first >> map[n + 1].second;
		queue<pair<int, int>> q;
		int visit[102] = { 0, };
		q.push(map[0]);
		int ok = 0;
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			if (a == map[n + 1].first && b == map[n + 1].second) {
				ok = 1;
				break;
			}
			for (int i = 0; i <= n + 1; i++) {
				if (!visit[i] && abs(map[i].first - a) + abs(map[i].second - b) <= 1000) {
					q.push(map[i]);
					visit[i] = 1;
				}
			}
		}
		if (ok)cout << "happy\n";
		else cout << "sad\n";
	}
}