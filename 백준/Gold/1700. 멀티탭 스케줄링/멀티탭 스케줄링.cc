#include <iostream>
using namespace std;
int a[101], p[101], visit[101];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	int ans = 0;
	int cnt = 1;
	for (int i = 1; i <= k; i++) {
		if (visit[a[i]])continue;
		if (cnt <= n) {
			p[cnt] = a[i];
			visit[a[i]] = 1;
			cnt++;
		}
		else {
			ans++;
			int far = 0;
			int idx = 0;
			for (int j = 1; j <= n; j++) {
				int ok = 0;
				for (int l = i + 1; l <= k; l++) {
					if (p[j] == a[l]) {
						if (far < l) {
							far = l;
							idx = j;
						}
						ok = 1;
						break;
					}
				}
				if (!ok) {
					idx = j;
					break;
				}
			}
			visit[p[idx]] = 0;
			p[idx] = a[i];
			visit[a[i]] = 1;
		}
	}
	cout << ans;
}