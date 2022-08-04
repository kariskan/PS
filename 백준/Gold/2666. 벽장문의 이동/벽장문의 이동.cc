#include <iostream>
using namespace std;

int a[20], n, m, op1, op2;
int ans = 1000000000;
void go(int seq, int f, int s, int sum) {
	if (seq == m) {
		ans = min(ans, sum);
		return;
	}
	go(seq + 1, a[seq], s, sum + abs(f - a[seq]));
	go(seq + 1, f, a[seq], sum + abs(s - a[seq]));
}

int main() {
	cin >> n >> op1 >> op2 >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	go(0, op1, op2, 0);
	cout << ans;
}