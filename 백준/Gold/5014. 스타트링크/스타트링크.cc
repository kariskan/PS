#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int visit[1000001];
queue<int> q;

int main() {
	cin >> f >> s >> g >> u >> d;
	q.push(s);
	visit[s] = 1;
	if (s == g)cout << 0;
	else {
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			if (a == g)break;
			if (a + u <= f && !visit[a + u]) {
				visit[a + u] = visit[a] + 1;
				q.push(a + u);
			}
			if (a - d > 0 && !visit[a - d]) {
				visit[a - d] = visit[a] + 1;
				q.push(a - d);
			}
		}
		if (visit[g] == 0)cout << "use the stairs";
		else cout << visit[g] - 1;
	}
}