#include <iostream>
using namespace std;

int a[1000002], visit[1000002];
int n;
int main() {
	cin.sync_with_stdio(0);
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		visit[a[i]]++;
		if (visit[a[i] + 1]) {
			visit[a[i] + 1]--;
		}
		else ans++;
	}
	cout << ans;
}