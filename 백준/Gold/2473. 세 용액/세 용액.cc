#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long n, a[5000], an[3];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);

	long long ans = LLONG_MAX;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {

			int left = j + 1;
			int right = n - 1;
			int mid = (left + right) / 2;

			while (left <= right) {
				mid = (left + right) / 2;
				if (a[i] + a[j] + a[mid] > 0) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}

				if (ans > abs(a[i] + a[j] + a[mid])) {
					ans = abs(a[i] + a[j] + a[mid]);
					an[0] = a[i];
					an[1] = a[j];
					an[2] = a[mid];
				}
			}
		}
		
	}

	sort(an, an + 3);

	cout << an[0] << ' ' << an[1] << ' ' << an[2];
}