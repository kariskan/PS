#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
void run(int cnt, vector<int> temp, int idx) {
	if (cnt == m) {
		for (int i = 0; i < temp.size(); i++) {
			cout << temp[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		temp.push_back(v[i]);
		run(cnt + 1, temp, i);
		temp.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	run(0, {}, 0);
}