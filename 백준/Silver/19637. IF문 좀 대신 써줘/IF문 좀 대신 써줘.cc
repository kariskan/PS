#include <iostream>
#include <map>
using namespace std;

int n, m, a[100000];
string ma[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s; int k;
		cin >> s >> k;
		a[i] = k;
		ma[i] = s;
	}

	for (int i = 0; i < m; i++) {
		int c; cin >> c;

		int left = 0, right = n - 1;
		int mid = (left + right) / 2;
		int ans;
		while (left <= right) {
			mid = (left + right) / 2;

			if (a[mid] >= c) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}

			ans = left;
		}

		cout << ma[ans] << '\n';
	}
}