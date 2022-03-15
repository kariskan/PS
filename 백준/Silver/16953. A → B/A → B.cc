#include <iostream>
using namespace std;
long long a, b;
int ans = -1;
void dfs(long long n, int cnt) {
	if (n > b) return;
	if (n == b) {
		if (ans == -1 || ans > cnt) {
			ans = cnt;
		}
	}
	dfs(n * 2, cnt + 1);
	dfs(n * 10 + 1, cnt + 1);
}
int main() {
	cin >> a >> b;
	dfs(a, 1);
	cout << ans;
}