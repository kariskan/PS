#include <iostream>
using namespace std;
int a[100000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 100001;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int a1 = a[0] + i;
			int a2 = a[1] + j;
			int cnt = 0;
			if (i != 0)cnt++;
			if (j != 0)cnt++;
			int brk = 0;
			for (int k = 2; k < n; k++) {
				int t = a1 + (a2 - a1) * k;
				if (abs(t - a[k]) == 1) {
					cnt++;
				}
				else if (t - a[k] == 0)continue;
				else {
					brk = 1;
					break;
				}
			}
			if(!brk) ans = min(cnt, ans);
		}
	}
	if (ans == 100001)cout << -1;
	else cout << ans;
}