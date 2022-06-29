#include <iostream>
#include <algorithm>
using namespace std;
int ar[2000000];
int n, m;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + n + m);
	for (int i = 0; i < n + m; i++) {
		cout << ar[i] << ' ';
	}
}