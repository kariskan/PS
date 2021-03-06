#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 2000000000;
	int ansx = 0, ansy = n - 1;
	/*for (int i = 0; i < n - 1; i++) {
		int start = a[i];

		int left = i + 1;
		int right = n - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			mid = (left + right) / 2;

			if (a[mid] + start < 0) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
			if (ans > abs(start + a[mid])) {
				ans = abs(start + a[mid]);
				ansx = start;
				ansy = a[mid];
			}
		}
	}*/
	int left = 0, right = n - 1;

	while (left < right) {
		if (ans > abs(a[left] + a[right])) {
			ans = abs(a[left] + a[right]);
			ansx = a[left];
			ansy = a[right];
		}
		if (left<right - 1 && abs(a[left + 1] + a[right])>abs(a[left] + a[right - 1])) {
			right--;
		}
		else {
			left++;
		}
	}
	cout << ansx << ' ' << ansy;
}