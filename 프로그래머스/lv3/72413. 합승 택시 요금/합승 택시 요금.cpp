#include <string>
#include <vector>
#include <climits>
using namespace std;
int dis[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 10000000;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j)dis[i][j] = 0;
			else dis[i][j] = 10000000;

	for (vector<int> f : fares) {
		dis[f[0]][f[1]] = f[2];
		dis[f[1]][f[0]] = f[2];
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] == -1 || dis[k][j] == -1)continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		answer = min(answer, dis[s][i] + dis[i][a] + dis[i][b]);
	}

	return answer;
}