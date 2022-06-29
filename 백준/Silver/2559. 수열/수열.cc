#include <iostream>
using namespace std;
int n, k;
int ar[100000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		if (i < k)sum += ar[i];
	}
	int ans = sum;
	for (int i = k; i < n; i++) {
		sum = sum - ar[i - k] + ar[i];
		if (ans < sum) {
			ans = sum;
		}
	}
	cout << ans;
}