#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int visit[1001];
pair<int, int> inp[1001];
bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	if (p2.second == p1.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> inp[i].first >> inp[i].second;
		}
		sort(inp + 1, inp + 1 + m, compare);
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = inp[i].first; j <= inp[i].second; j++) {
				if (!visit[j]) {
					visit[j] = 1;
					ans++;
					break;
				}
			}
		}
		cout << ans << '\n';
		memset(visit, 0, sizeof(visit));
	}
}