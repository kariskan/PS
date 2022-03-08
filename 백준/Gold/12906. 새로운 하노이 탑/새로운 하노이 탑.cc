#include <iostream>
#include <queue>
#include <tuple>
#include <map>
#include <array>
using namespace std;
array<string, 3> tower;
int main() {
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		if(a) cin >> tower[i];
	}
	int cnt[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tower[i].length(); j++) {
			cnt[tower[i][j] - 'A']++;
		}
	}
	map<array<string, 3>, int> m;
	queue<array<string, 3>> q;
	q.push(tower);
	m[tower] = 0;
	while (!q.empty()) {
		array<string, 3> a = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j)continue;
				if (a[i].length() == 0)continue;
				array<string, 3> n(a);
				n[j].push_back(n[i].back());
				n[i].pop_back();
				if (!m.count(n)) {
					m[n] = m[a] + 1;
					q.push(n);
				}
			}
		}
	}
	array<string, 3>ans;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			ans[i] += (char)('A' + i);
		}
	}
	cout << m[ans];
}