#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100000];
long long sum;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	long long left = *max_element(a, a + n);
	long long right = 10000000000;
	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long t = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (t + a[i] > mid) {
				cnt++;
				t = 0;
				i--;
				continue;
			}
			t += a[i];
		}
		if (t != 0)cnt++;
		if (cnt > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			ans = mid;
		}
	}
	cout << ans;
}