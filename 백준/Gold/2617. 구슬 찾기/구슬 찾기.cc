#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, minV[100], maxV[100], visit[100], rVisit[100];
int v[100][100], rev[100][100];

int getMin(int node) {

	rVisit[node] = 1;
	int ret = 0;

	for (int i = 1; i <= n; i++) {
		if (!rVisit[i] && rev[node][i]) {
			ret += getMin(i);
		}
	}

	return ret + 1;
}

int getMax(int node) {

	visit[node] = 1;
	int ret = 0;

	for (int i = 1; i <= n; i++) {
		if (!visit[i] && v[node][i]) {
			ret += getMax(i);
		}
	}

	return ret + 1;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a][b] = 1;
		rev[b][a] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a = getMin(i);
		int b = getMax(i);

		if (a > (n + 1) / 2 || b > (n + 1) / 2)ans++;

		memset(visit, 0, sizeof(visit));
		memset(rVisit, 0, sizeof(rVisit));
	}

	cout << ans;

}