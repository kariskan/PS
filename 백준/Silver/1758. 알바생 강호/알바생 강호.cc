#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100001];
bool compare(int& p1, int& p2) {
	return p1 > p2;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, compare);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += max(0, a[i] - i + 1);
	}
	cout << ans;
}