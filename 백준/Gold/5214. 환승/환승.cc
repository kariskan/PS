#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m;
vector<vector<int>> v;
int visit[110001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> m;
	v.resize(n + 10000);

	int t = n + 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int num; cin >> num;
			v[num].push_back(t);
			v[t].push_back(num);
		}
		t++;
	}

	queue<int> q;
	q.push(1);
	visit[1] = 1;

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (auto& i : v[a]) {
			if (!visit[i]) {
				if (i > n)visit[i] = visit[a];
				else visit[i] = visit[a] + 1;
				q.push(i);
			}
		}
	}

	if (visit[n])cout << visit[n];
	else cout << -1;
}