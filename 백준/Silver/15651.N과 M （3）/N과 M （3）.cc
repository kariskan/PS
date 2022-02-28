#include <iostream>
using namespace std;
int n, m;

int visit[9];
int a[10];
int cnt = 0;
string s = "";
void sol(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		visit[i] = 1; a[index] = i;
		sol(index + 1, n, m);
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	sol(0, n, m);
}