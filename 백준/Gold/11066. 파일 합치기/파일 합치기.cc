#include <iostream>
#include <cstring>
using namespace std;
int d[500][500];
int a[500];
int file(int i, int j) {
	if (i == j)return 0;
	if (d[i][j] != -1) return d[i][j];
	int s = 0;
	for (int k = i; k <= j; k++) {
		s += a[k];
	}
	int &ans = d[i][j];
	for (int k = i; k < j; k++) {
		int temp = file(i, k) + file(k + 1, j) + s;
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(d, -1, sizeof(d));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << file(0, n - 1) << "\n";
	}
}