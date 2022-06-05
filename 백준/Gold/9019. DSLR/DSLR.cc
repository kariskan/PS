#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int D(int s) {
	return (s * 2) % 10000;
}
int S(int s) {
	return s == 0 ? 9999 : s - 1;
}
int L(int s) {
	return (s % 1000) * 10 + s / 1000;
}
int R(int s) {
	return (s % 10) * 1000 + s / 10;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		queue<pair<int, string>> q;
		int visit[10000] = { 0, };
		q.push({ a,"" });
		visit[a] = 1;
		while (!q.empty()) {
			int k = q.front().first;
			string k1 = q.front().second;

			q.pop();
			if (k == b) {
				cout << k1 << "\n";
				break;
			}
			int t = D(k);
			if (!visit[t]) {
				visit[t] = 1;
				q.push({ t, k1 + "D" });
			}
			t = S(k);
			if (!visit[t]) {
				visit[t] = 1;
				q.push({ t, k1 + "S" });
			}
			t = L(k);
			if (!visit[t]) {
				visit[t] = 1;
				q.push({ t, k1 + "L" });
			}
			t = R(k);
			if (!visit[t]) {
				visit[t] = 1;
				q.push({ t, k1 + "R" });
			}
		}
	}
}