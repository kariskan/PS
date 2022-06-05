#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int visit[1000000] = { 0, };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		priority_queue<pair<int, int>> dcq;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> acq;
		memset(visit, 0, sizeof(visit));
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			char c; int q;
			cin >> c >> q;
			if (c == 'I') {
				acq.push({ q,cnt });
				dcq.push({ q,cnt });
				cnt++;
			}
			else {
				if (q == 1) {
					while (!dcq.empty() && visit[dcq.top().second]) {
						dcq.pop();
					}
					if (!dcq.empty()) {
						visit[dcq.top().second] = 1;
						dcq.pop();
					}
				}
				else {
					while (!acq.empty() && visit[acq.top().second]) {
						acq.pop();
					}
					if (!acq.empty()) {
						visit[acq.top().second] = 1;
						acq.pop();
					}
				}
			}
		}
		while (!dcq.empty() && visit[dcq.top().second]) {
			dcq.pop();
		}
		while (!acq.empty() && visit[acq.top().second]) {
			acq.pop();
		}
		if (dcq.empty() && acq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << dcq.top().first << " " << acq.top().first << "\n";
		}
	}
}