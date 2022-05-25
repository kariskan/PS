#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, h;
typedef vector<vector<int>> v;
v horEdge, verEdge, visit, water;

struct tank {
	int x, y, high, mx;
	bool operator<(const tank &r)const {
		return r.high < high;
	}
};

priority_queue<tank> waterTank;

void insert(int a, int b, int c, int d) {
	if (c == -1 || a < 1 || m < a || b < 1 || n < b || visit[b][a])return;
	waterTank.push({ a,b,c,(d > c ? d : c) });
	return;
}

void bfs() {
	while (!waterTank.empty()) {
		tank t = waterTank.top();
		waterTank.pop();
		if (visit[t.y][t.x])continue;
		water[t.y][t.x] = (t.mx > t.high ? t.mx : t.high);
		visit[t.y][t.x] = 1;
		insert(t.x, t.y - 1, horEdge[t.y][t.x], t.mx);
		insert(t.x + 1, t.y, verEdge[t.y][t.x + 1], t.mx);
		insert(t.x, t.y + 1, horEdge[t.y + 1][t.x], t.mx);
		insert(t.x - 1, t.y, verEdge[t.y][t.x], t.mx);
	}
}

int main() {
	//freopen("watertank.inp", "r", stdin);
	//freopen("watertank.out", "w", stdout);
	
		int res = 0;
		cin >> n >> m >> h;
		horEdge.resize(n + 5, vector<int>(m + 5));
		verEdge.resize(n + 5, vector<int>(m + 5));
		visit.resize(n + 5, vector<int>(m + 5));
		water.resize(n + 5, vector<int>(m + 5));
		for (int i = 1; i <= n + 1; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> horEdge[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m + 1; j++) {
				cin >> verEdge[i][j];
			}
		}
		for (int i = 1; i <= m; i++) {
			insert(i, 1, horEdge[1][i], 0);
		}
		for (int i = 1; i <= m; i++) {
			insert(i, n, horEdge[n + 1][i], 0);
		}
		for (int i = 1; i <= n; i++) {
			insert(1, i, verEdge[i][1], 0);
		}
		for (int i = 1; i <= n; i++) {
			insert(m, i, verEdge[i][m + 1], 0);
		}
		bfs();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!visit[i][j])res += h;
				else res += water[i][j];
			}
		}
		cout << res << "\n";
		horEdge.clear();
		verEdge.clear();
		visit.clear();
		water.clear();
		while (!waterTank.empty())waterTank.pop();
	
}