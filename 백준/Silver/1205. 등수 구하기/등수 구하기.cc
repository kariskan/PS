#include <iostream>
using namespace std;

int n, ne, p;
int a[51];
int ran[51];
int main() {
	cin >> n >> ne >> p;
	int ans = -1;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	ran[1] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			ran[i] = ran[i - 1];
		}
		else {
			ran[i] = i;
		}
	}
	for (int i = 1; i <= p; i++) {
		if (i > n) {
			if (ne == a[i - 1]) {
				ans = ran[i - 1];
			}
			else ans = i;
			break;
		}
		if (ne > a[i]) {
			if (ne == a[i - 1] && i > 1) {
				ans = ran[i - 1];
			}
			else {
				ans = ran[i];
			}
			break;
		}
	}
	cout << ans;
}