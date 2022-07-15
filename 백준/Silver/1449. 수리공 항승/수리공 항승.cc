#include <iostream>
using namespace std;
int visit[1002];
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		visit[a] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= 1000; i++) {
		if (visit[i]) {
			for (int j = i; j <= i + m; j++) {
				visit[i] = 0;
			}
			ans++;
			i += m - 1;
		}
	}
	cout << ans;
}