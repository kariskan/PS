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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, l;
	cin >> n >> m >> l;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	vector<pair<int, int>> coor;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		coor.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	int answer = 0;
	for (pair<int, int>& c : coor) {
		int left = 0, right = v.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (c.second + abs(c.first - v[mid]) <= l) {
				answer++;
				break;
			}

			if (c.first < v[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	cout << answer;
}