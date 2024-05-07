#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int n, a, b;
pair<int, pair<int, int>> inp[200001];
int p[200001], vis[200001];

bool compare(pair<int, pair<int, int>>& p1, pair<int, pair<int, int>>& p2) {
	return p1.second.second < p2.second.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	// num, flag, coor
	vector<pair<int, pair<int, int>>> v;
	v.push_back({ 0,{0,INT_MIN} });
	v.push_back({ 0,{0,INT_MAX} });
	for (int i = 1; i <= n; i++) {
		cin >> inp[i].first >> inp[i].second.first >> inp[i].second.second;
		// 0이면 왼쪽 X축, 1이면 오른쪽 X축
		v.push_back({ inp[i].first,{0,inp[i].second.first - inp[i].second.second}});
		v.push_back({ inp[i].first,{1,inp[i].second.first + inp[i].second.second}});
	}
	cin >> a >> b;

	sort(v.begin(), v.end(), compare);

	stack<int> st;
	vector<vector<int>> ad(200001);
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i].second.first == 0) {
			st.push(v[i].first);
		}
		else {
			int now = st.top();
			st.pop();
			p[now] = st.top();

			ad[now].push_back(st.top());
			ad[st.top()].push_back(now);
		}
	}

	queue<pair<int, vector<int>>> q;
	q.push({ a,{a} });
	vis[a] = 1;
	while (!q.empty()) {
		int now = q.front().first;
		vector<int> seq = q.front().second;
		q.pop();

		if (now == b) {
			cout << seq.size() << '\n';
			for (int i = 0; i < seq.size(); i++) {
				cout << seq[i] << ' ';
			}
			return 0;
		}

		for (auto& i : ad[now]) {
			if (!vis[i]) {
				vis[i] = 1;
				vector<int> temp = seq;
				temp.push_back(i);
				q.push({ i,temp });
			}
		}
	}
}