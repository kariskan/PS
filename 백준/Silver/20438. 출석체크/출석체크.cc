#include <iostream>
using namespace std;

int n, k, q, m, sleep[50001], s, e, inp[50001], sum[50001];

void go(int c) {

	if (c > 50000 || sleep[c] || inp[c]) {
		return;
	}

	inp[c] = 1;

	for (int i = 2; c * i < 50000; i++) {
		go(c * i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> q >> m;
	
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		sleep[a] = 1;
	}

	for (int i = 0; i < q; i++) {
		int a; cin >> a;
		go(a);
	}

	for (int i = 1; i <= 50000; i++) {
		if (!inp[i])sum[i]++;
		sum[i] += sum[i - 1];
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << sum[e] - sum[s - 1] << '\n';
	}
}