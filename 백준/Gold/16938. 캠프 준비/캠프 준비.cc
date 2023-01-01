#include <iostream>
using namespace std;
int n, l, r, x;
int a[15];
int visit[15];
int ans;
void run(int cnt, int sum, int m1, int m2, int index) {
	if (sum > r)return;
	if (!(sum<l || m2 - m1 < x)) {
		ans++;
	}
	for (int i = index; i < n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			run(cnt + 1, sum + a[i], min(m1, a[i]), max(m2, a[i]), i + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	run(0, 0, 1000000000, 0, 0);
	cout << ans;
}