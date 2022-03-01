#include <iostream>
using namespace std;
int a[15];
int visit[15];
int n;
int k[15];
void sol(int index) {
	if (index == 6) {
		for (int i = 0; i < 6; i++) {
			cout << k[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i])continue;
		if (index > 0 && k[index - 1] > a[i])continue;
		visit[i] = 1;
		k[index] = a[i];
		sol(index + 1);
		visit[i] = 0;
		k[index] = 0;
	}
}
int main() {
	while (1) {
		cin >> n;
		if (!n)break;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sol(0);
		cout << "\n";
		for (int i = 0; i < 15; i++)a[i] = k[i] = visit[i] = 0;
	}
}