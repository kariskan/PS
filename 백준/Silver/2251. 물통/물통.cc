#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int visit[201][201][201];
int a, b, c;
vector<int> ans;
queue<tuple<int, int, int>> q;

int main() {
	cin >> a >> b >> c;
	q.push({ 0,0,c });
	visit[0][0][c] = 1;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		if (!x)ans.push_back(z);
		q.pop();
		if (x != 0) {
			if (!visit[x - min(x, c - z)][y][z + min(x, c - z)]) {
				visit[x - min(x, c - z)][y][z + min(x, c - z)] = 1;
				q.push({ x - min(x, c - z),y,z + min(x,c - z) });
			}

			if (!visit[x - min(x, b - y)][y + min(x, b - y)][z]) {
				visit[x - min(x, b - y)][y + min(x, b - y)][z] = 1;
				q.push({ x - min(x,b - y),y + min(x,b - y),z });
			}
		}
		if (y != 0) {
			if (!visit[x + min(a - x, y)][y - min(a - x, y)][z]) {
				visit[x + min(a - x, y)][y - min(a - x, y)][z] = 1;
				q.push({ x + min(a - x, y),y - min(a - x, y),z });
			}

			if (!visit[x][y - min(c - z, y)][z + min(c - z, y)]) {
				visit[x][y - min(c - z, y)][z + min(c - z, y)] = 1;
				q.push({ x,y - min(c - z,y),z + min(c - z,y) });
			}
		}
		if (z != 0) {
			if (!visit[x + min(a - x, z)][y][z - min(a - x, z)]) {
				visit[x + min(a - x, z)][y][z - min(a - x, z)] = 1;
				q.push({ x + min(a - x, z),y,z - min(a - x,z) });
			}

			if (!visit[x][y + min(b - y, z)][z - min(b - y, z)]) {
				visit[x][y + min(b - y, z)][z - min(b - y, z)] = 1;
				q.push({ x,y + min(b - y,z),z - min(b - y,z) });
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int k : ans) {
		cout << k << " ";
	}
}