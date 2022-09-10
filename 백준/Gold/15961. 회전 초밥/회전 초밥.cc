#include <iostream>
using namespace std;

int n, d, k, c, a[3000000], cnt[3001], ate[3001];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie();

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		if (!cnt[a[i]]) ans++;
		cnt[a[i]]++;
	}

	
	int left = 0, right = k - 1, temp = ans;

	if (!cnt[c])ans++;

	while (1) {

		cnt[a[left]]--;
		if (cnt[a[left]] == 0) temp--;
		left = (left + 1) % n;

		if (!cnt[a[(right + 1) % n]]) temp++;
		right = (right + 1) % n;
		cnt[a[right]]++;

		ans = max(ans, temp + (!cnt[c] ? 1 : 0));
		if (right == k - 2) break;
	}

	cout << ans;
}