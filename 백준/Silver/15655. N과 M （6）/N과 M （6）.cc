#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a[8];
void go(vector<int> v, int idx) {
	if (v.size() == m) {
		for (auto& i : v)cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++) {
		v.push_back(a[i]);
		go(v, i + 1);
		v.pop_back();
	}
	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	go({}, 0);
}