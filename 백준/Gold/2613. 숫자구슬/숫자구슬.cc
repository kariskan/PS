#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a[300];
int main() {
	cin >> n >> m;
	int left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (left < a[i])left = a[i];
		right += a[i];
	}
	
	while (left <= right) {
		int mid = (left + right) / 2;
		int g = 1, sum = 0;
		for (int i = 0; i < n; i++) {
			if (sum + a[i] > mid) {
				g++;
				sum = a[i];
			}
			else {
				sum += a[i];
			}
		}
		if (g > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << left << '\n';
	int cnt = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + a[i] > left) {
			sum = a[i];
			m--;
			cout << cnt << ' ';
			cnt = 1;
		}
		else {
			cnt++;
			sum += a[i];
		}
		if (n - i == m)break;
	}
	while (m--) {
		cout << cnt << ' ';
		cnt = 1;
	}
}