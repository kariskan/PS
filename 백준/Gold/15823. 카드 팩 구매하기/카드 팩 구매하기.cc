#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int a[100001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = m;
	int left = 1, right = n / m;
	while (left <= right) {
		int mid = (left + right) / 2;

		map<int, int> ma;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (ma.find(a[i]) != ma.end()) {
				i = ma[a[i]];
				ma.clear();
				continue;
			}
			ma[a[i]] = i;
			if (ma.size() >= mid) {
				cnt++;
				ma.clear();
			}
		}

		if (cnt >= m) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;
}