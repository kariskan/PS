#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[500001];
int b[500001];
long long ans;
void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int idx = left;
	long long cnt = 0;
	while (i <= mid && j <= right) {
		if (a[i] > a[j]) {
			b[idx++] = a[j++];
			cnt++;
		}
		else {
			b[idx++] = a[i++];
			ans += cnt;
		}
	}

	for (int k = i; k <= mid; k++) {
		b[idx++] = a[k];
		ans += cnt;
	}
	for (int k = j; k <= right; k++) {
		b[idx++] = a[k];
	}
	for (int k = left; k <= right; k++) {
		a[k] = b[k];
	}
}
void mergeS(int left, int right) {
	if (left < right) {
		mergeS(left, (left + right) / 2);
		mergeS((left + right) / 2 + 1, right);
		merge(left, (left + right) / 2, right);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	mergeS(0, n - 1);
	cout << ans;
}
