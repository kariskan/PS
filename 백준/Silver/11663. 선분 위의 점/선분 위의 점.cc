#include <iostream>
#include <algorithm>
using namespace std;

int n, m, point[100000];

int lo(int a) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (point[mid] >= a) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

int up(int a) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (point[mid] <= a) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return right + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> point[i];
	}

	sort(point, point + n);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		cout << up(b) - lo(a) << '\n';
	}
}