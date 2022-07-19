#include <iostream>
using namespace std;

int n, m, k;
int main() {
	cin >> n >> m >> k;
	int ans = abs(n - m);
	for (int i = 0; i < k; i++) {
		int num; cin >> num;
		ans = min(ans, 1 + abs(num - m));
	}
	cout << ans;
}