#include <iostream>
using namespace std;

int n;
int a[100][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || j == k || i == k)continue;
				int num = i * 100 + j * 10 + k;
				int cnt[10] = { 0, };
				cnt[i] = cnt[j] = cnt[k] = 1;
				bool ok = true;
				for (int l = 0; l < n; l++) {
					int t = num, t2 = a[l][0];
					int st = 0, b = 0;
					while (t2) {
						if (t % 10 == t2 % 10)st++;
						else if (cnt[t2 % 10])b++;
						t2 /= 10;
						t /= 10;
					}
					if (st == a[l][1] && b == a[l][2])continue;
					ok = false;
					break;
				}
				if (ok) {
					ans++;
				}
			}
		}
	}
	cout << ans;
}