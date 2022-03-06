#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int noPrime[10001];
void init() {
	for (int i = 2; i <= 100; i++) {
		if (noPrime[i])continue;
		for (int j = i * 2; j <= 10000; j += i) {
			noPrime[j] = 1;
		}
	}
}
int t, n, m;

int calc(int k, int i, int j) {
	int a[4] = { 0, };
	a[0] = k / 1000;
	k %= 1000;
	a[1] = k / 100;
	k %= 100;
	a[2] = k / 10;
	k %= 10;
	a[3] = k;
	a[i] = j;
	int res = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
	return res;
}

int main() {
	init();
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int visit[10000] = { 0, };
		queue<int> q;
		q.push(n);
		visit[n] = 1;
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0)continue;
					int temp = calc(a, i, j);
					if (visit[temp] || noPrime[temp])continue;
					visit[temp] = visit[a] + 1;
					q.push(temp);
				}
			}
		}
		if (n == m)cout << 0 << "\n";
		else if (!visit[m])cout << "Impossible\n";
		else cout << visit[m] - 1 << "\n";
	}
}