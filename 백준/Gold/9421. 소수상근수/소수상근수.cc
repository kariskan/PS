#include <iostream>
#include <cstring>
using namespace std;

bool arr[1000001], prime[1000001];

void go() {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i * i <= 1000000; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= 1000000; j += i) {
				prime[j] = false;
			}
		}
	}
}

bool a(int n) {
	bool visit[500] = { 0, };

	while (1) {
		if (arr[n])return true;
		if (n == 1)return true;
		int t = 0;
		while (n) {
			t += (n % 10) * (n % 10);
			n /= 10;
		}
		if (visit[t])return false;
		visit[t] = 1;
		n = t;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	go();
	for (int i = 1; i <= 1000000; i++) {
		if (a(i))arr[i] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i] && prime[i])cout << i << '\n';
	}
}