#include <iostream>
using namespace std;
int ar[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
		ar[i] += ar[i - 1];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << ar[b] - ar[a - 1] << "\n";
	}
}