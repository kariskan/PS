#include <iostream>
using namespace std;
int a[250001];
int main() {
	int n, m, b;
	cin >> n >> m >> b;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i * m + j];
			if (max < a[i * m + j])max = a[i * m + j];
		}
	}
	int ans = 2000000000, height = 0;
	for (int i = 0; i <= max; i++) {
		int sum = 0, tb = b;
		
		for (int j = 0; j < n * m; j++) {
			if (i <= a[j]) {
				sum += 2 * (a[j] - i);
				tb += a[j] - i;
			}
			else {
				sum += i - a[j];
				tb -= i - a[j];
			}
		}
		if (tb < 0)continue;
		if (ans >= sum) {
			ans = sum;
			height = i;
		}
	}
	cout << ans << " " << height;
}