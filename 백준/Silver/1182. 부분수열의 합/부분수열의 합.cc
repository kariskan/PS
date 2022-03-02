#include <iostream>
using namespace std;
int n, s;
int a[20] = { 0, };
int visit[20];
int ans;
void sol(int res, int count, int k) {
	if (res == s && count != 0) ans++;
	if (count == n) {
		return;
	}
	for (int i = k; i < n; i++) {
		if (visit[i])continue;
		visit[i] = 1;
		sol(res + a[i], count + 1, i);
		visit[i] = 0;
	}
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sol(0, 0, 0);
	cout << ans;
}