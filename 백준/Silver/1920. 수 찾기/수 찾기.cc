#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int b[100000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		int start = 0, end = n - 1, mid;
		int ok = 0;
		while (start <= end) {
			mid = (start + end) / 2;
			if (a[mid] < b[i]) start = mid + 1;
			else if (a[mid] == b[i]) {
				cout << 1 << "\n";
				ok = 1;
				break;
			}
			else end = mid - 1;
		}
		if (!ok) {
			cout << 0 << "\n";
		}
	}
}