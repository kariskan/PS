#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> v;
int visit[10001], n, source, m;
void run(int idx, int sum) {
	if (m < sum) {
		m = sum;
		source = idx;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[v[idx][i].first]) {
			visit[v[idx][i].first] = 1;
			run(v[idx][i].first, sum + v[idx][i].second);
			visit[v[idx][i].first] = 0;
		}
	}
}
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	visit[1] = 1;
	run(1, 0);
	visit[1] = 0;
	visit[source] = 1;
	run(source, 0);
	cout << m;
}