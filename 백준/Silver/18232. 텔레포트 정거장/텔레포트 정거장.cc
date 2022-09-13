#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, s, e, visit[300001];
vector<int> tp[300001];

int main() {
	cin >> n >> m >> s >> e;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		tp[a].push_back(b);
		tp[b].push_back(a);
	}

	queue<int> q;
	q.push(s);
	visit[s] = 1;
	
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		if (a == e) {
			cout << visit[a] - 1;
			break;
		}

		if (a + 1 <= n && !visit[a + 1]) {
			visit[a + 1] = visit[a] + 1;
			q.push(a + 1);
		}
		if (a - 1 >= 1 && !visit[a - 1]) {
			visit[a - 1] = visit[a] + 1;
			q.push(a - 1);
		}
		for (int i = 0; i < tp[a].size(); i++) {
			if (!visit[tp[a][i]]) {
				visit[tp[a][i]] = visit[a] + 1;
				q.push(tp[a][i]);
			}
		}
	}

}