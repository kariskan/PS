#include <string>
#include <vector>

using namespace std;
vector<vector<string>> places;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int ans = 1;
void dfs(int i, int j, int k, int cnt, int visit[5][5]) {
	if (cnt == 2) {
		return;
	}
	for (int l = 0; l < 4; l++) {
		int nx = j + x[l];
		int ny = k + y[l];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visit[nx][ny] && places[i][nx][ny] != 'X') {
			if (places[i][nx][ny] == 'P') {
				ans = 0;
				return;
			}
			visit[nx][ny] = 1;
			dfs(i, nx, ny, cnt + 1, visit);
			visit[nx][ny] = 0;
			if (!ans)return;
		}
	}
}
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	::places = places;
	for (int i = 0; i < 5; i++) {
		int visit[5][5] = { 0, };
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				ans = 1;
				if (places[i][j][k] == 'P') {
 					visit[j][k] = 1;
					dfs(i, j, k, 0, visit);
					visit[j][k] = 0;
					if (!ans) {
						answer.push_back(ans);
						break;
					}
				}
			}
			if (!ans)break;
		}
		if (ans) {
			answer.push_back(ans);
		}
	}
	return answer;
}