#include <iostream>
using namespace std;
int a[51];

double getLean(int i, int j) {
	return ((double)(a[i] - a[j]) / (double)(i - j));
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			int left = min(i, j);
			int right = max(i, j);
			int ok = 1;
			for (int k = left + 1; k <= right - 1; k++) {
				
				if (i < j) { //기준이 왼쪽
					double l = getLean(i, j);
					double r = getLean(i, k);
					if (l <= r) {
						ok = 0;
						break;
					}
				}
				else { //기준이 오른쪽
					double l = getLean(j, i);
					double r = getLean(k, i);
					if (l >= r) {
						ok = 0;
						break;
					}
				}
			}
			if (ok)cnt++;
		}
		ans = max(ans, cnt);
	}

	cout << ans;
}