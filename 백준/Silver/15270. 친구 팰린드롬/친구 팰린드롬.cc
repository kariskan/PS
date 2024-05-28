#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int n, m, ma;
int a[50][2], vis[50];

void go(int idx, int cnt) {
	if (idx >= m) {
		ma = max(ma, cnt);
		return;
	}

	go(idx + 1, cnt);

	if (!vis[a[idx][0]] && !vis[a[idx][1]]) {
		vis[a[idx][0]] = 1;
		vis[a[idx][1]] = 1;
		go(idx + 1, cnt + 1);
		vis[a[idx][0]] = 0;
		vis[a[idx][1]] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	go(0, 0);

	ma *= 2;
	if (ma < n) {
		ma++;
	}

	cout << ma;
}