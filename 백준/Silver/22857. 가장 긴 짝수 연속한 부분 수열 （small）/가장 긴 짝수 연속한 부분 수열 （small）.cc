#include <iostream>
using namespace std;

int a[50001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int left = 1, right = 1;
	int cnt = 0, answer = 0;
	if (a[1] % 2 == 1) {
		cnt++;
	}
	while (right <= n) {
		while (cnt > k) {
			if (a[left] % 2 == 1) {
				cnt--;
			}
			left++;
		}

		answer = max(answer, right - left + 1 - cnt);
		right++;
		if (a[right] % 2 == 1) {
			cnt++;
		}
	}

	cout << answer;
}