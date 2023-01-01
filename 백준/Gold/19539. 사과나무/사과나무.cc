#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100000];

int main() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 3 != 0)cout << "NO";
	else {
		sort(a, a + n);
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < 3) {
				if (a[i] == 1)cnt2++;
				else if (a[i] == 2)cnt1++;
			}
			else {
				int t = min(cnt2, a[i] / 2);
				cnt2 -= t;
				a[i] -= t * 2;
				t = min(cnt1, a[i]);
				cnt1 -= t;
				a[i] -= t;
				if (a[i] % 3 == 1) {
					cnt2++;
				}
				else if (a[i] % 3 == 2) {
					cnt1++;
				}
			}
		}
		if (cnt1 != cnt2)cout << "NO";
		else cout << "YES";
	}
}