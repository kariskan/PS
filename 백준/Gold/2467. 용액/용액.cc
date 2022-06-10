#include <iostream>
using namespace std;
int arr[100000];
int ans = 2000000001, ansl, ansr;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = n - 1;
		int mid = (start + end) / 2;
		while (start <= end) {
			mid = (start + end) / 2;
			if (arr[i] + arr[mid] > 0) {
				end = mid - 1;
			}
			else if (arr[i] + arr[mid] < 0) {
				start = mid + 1;
			}
			else {
				break;
			}
		}

		for (int j = mid - 1; j <= mid + 1; j++) {
			if (j < 0 || j >= n || i == j)continue;
			if (ans > abs(arr[i] + arr[j])) {
				ans = abs(arr[i] + arr[j]);
				ansl = i;
				ansr = j;
			}
		}
	}
	if (arr[ansl] > arr[ansr])swap(ansl, ansr);
	cout << arr[ansl] << " " << arr[ansr];
}