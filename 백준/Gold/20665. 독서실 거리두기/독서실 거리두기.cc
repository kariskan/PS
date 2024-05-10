#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int n, t, p;
pair<int, int> a[500];
int info[101][21 * 60 + 1];

bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first > p2.first;
}

int main() {
	cin >> n >> t >> p;
	for (int i = 0; i < t; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + t);

	for (int i = 0; i < t; i++) {
		int start = (a[i].first / 100) * 60 + a[i].first % 100;
		int end = (a[i].second / 100) * 60 + a[i].second % 100;

		int idx = -1;
		vector<int> v;
		for (int j = 1; j <= n; j++) {
			if (info[j][start]) {
				v.push_back(j);
			}
		}
		if (v.empty()) {
			idx = 1;
		}
		else {
			vector<pair<int, int>> insert; // len, num
			insert.push_back({ v[0] - 1,1 });
			insert.push_back({ n - v.back(), n });
			for (int i = 1; i < v.size(); i++) {
				int len = min(v[i] - (v[i] + v[i - 1]) / 2, (v[i] + v[i - 1]) / 2 - v[i - 1]);
				insert.push_back({ len,v[i - 1] + len });
			}
			sort(insert.begin(), insert.end(), compare);
			idx = insert[0].second;
		}
		for (int j = start; j < end; j++) {
			info[idx][j] = 1;
		}
	}

	int answer = 0;
	for (int i = 9 * 60; i < 21 * 60; i++) {
		if (!info[p][i]) {
			answer++;
		}
	}
	cout << answer;
}