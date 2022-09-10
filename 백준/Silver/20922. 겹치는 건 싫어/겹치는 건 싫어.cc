#include <iostream>
using namespace std;

int cnt[100001], a[200001], n, k;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0, left = 0, right = 0;

	while (left <= right && right < n) {
		cnt[a[right]]++;

		while (cnt[a[right]] > k) {
			cnt[a[left]]--;
			left++;
		}

		right++;
		ans = max(ans, right - left);
	}

	cout << ans;
}