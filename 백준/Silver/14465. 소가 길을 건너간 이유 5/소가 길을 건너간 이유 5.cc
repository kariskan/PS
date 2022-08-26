#include <iostream>
using namespace std;

int n, k, b, a[100001];

int main() {
	cin >> n >> k >> b;

	for (int i = 0; i < b; i++) {
		int num; cin >> num;
		a[num] = 1;
	}

	int c = 0, ans = 100001;

	for (int i = 1; i <= k; i++) {
		if (a[i])c++;
	}

	for (int i = 2; i <= n - k + 1; i++) {
		if (a[i - 1])c--;
		if (a[i - 1 + k])c++;

		ans = min(ans, c);
	}

	cout << ans;
}