#include <iostream>
using namespace std;
int n;
int k[10];
int visit[10];
bool next(int* a, int n) {
	return true;
}

void sol(int index, int n) {
	if (index == n) {
		for (int i = 0; i < n; i++) {
			cout << k[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i])continue;
		visit[i] = 1;
		k[index] = i;
		sol(index + 1, n);
		visit[i] = 0;
		k[index] = 0;
	}
}

int main() {
	cin >> n;
	sol(0, n);
}