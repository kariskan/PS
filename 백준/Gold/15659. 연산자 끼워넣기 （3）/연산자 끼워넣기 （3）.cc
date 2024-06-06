#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int n, a[11], op[4];
int ma = INT_MIN, mi = INT_MAX;
void go(vector<int> seq) {
	if (seq.size() == n - 1) {
		vector<int> v;
		v.push_back(a[0]);
		for (int i = 0; i < n - 1; i++) {
			if (seq[i] == 2 || seq[i] == 3) {
				int pre = v.back();
				v.pop_back();
				if (seq[i] == 2) {
					v.push_back(pre * a[i + 1]);
				}
				else {
					v.push_back(pre / a[i + 1]);
				}
			}
			else {
				v.push_back(a[i + 1]);
			}
		}
		int res = v[0], idx = 1;
		for (int i = 0; i < seq.size(); i++) {
			if (seq[i] == 0 || seq[i] == 1) {
				if (seq[i] == 0) {
					res += v[idx++];
				}
				else {
					res -= v[idx++];
				}
			}
		}
		mi = min(mi, res);
		ma = max(ma, res);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			seq.push_back(i);
			go(seq);
			op[i]++;
			seq.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	go({});

	cout << ma << '\n' << mi;
}