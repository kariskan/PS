#include <iostream>
#include <algorithm>
using namespace std;

int n, a[2000];

bool can(int c) {
	return c >= 0 && c < n;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int num = a[i];

		int left = 0;
		int right = n - 1;
		while (left < right) {
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			if (a[left] + a[right] == num) {
				break;
			}
			if (a[left] + a[right] < num) {
				left++;
			}
			else { //>
				right--;
			}
		}
		if (a[left] + a[right] == num && can(left) && can(right) && left != right) {
			ans++;
		}
	}
	cout << ans;
}