#include <iostream>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	int left = 1;
	int right = k;
	int mid = (left + right) / 2;
	long long ans;
	while (left <= right) {
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += min(n, mid / i);
		}
		if (sum < k) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
}