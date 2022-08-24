#include <iostream>
#include <vector>
using namespace std;

int n, map[20][20], ans = 1000000000;

void go(int a[20], int idx) {

	if (idx == n)return;

	vector<int> first, second;
	for (int i = 0; i < n; i++) {
		if (a[i])first.push_back(i);
		else second.push_back(i);
	}

	int m1 = 0, m2 = 0;
	for (int i = 0; i < first.size(); i++) {
		for (int j = i + 1; j < first.size(); j++) {
			m1 += map[first[i]][first[j]] + map[first[j]][first[i]];
		}
	}

	for (int i = 0; i < second.size(); i++) {
		for (int j = i + 1; j < second.size(); j++) {
			m2 += map[second[i]][second[j]] + map[second[j]][second[i]];
		}
	}

	ans = min(ans, abs(m1 - m2));

	for (int i = idx; i < n; i++) {
		a[i] = 1;
		go(a, i + 1);
		a[i] = 0;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int a[20] = { 0, };
	go(a, 0);

	cout << ans;
}