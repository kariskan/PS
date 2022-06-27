#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<int>> game_board;
vector<vector<int>> table;
vector<vector<vector<int>>> v;
vector<vector<vector<int>>> rotated;
vector<vector<vector<int>>> emp;
int n, visit[50][50];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int check[1000000], check2[1000000];
void rotate() {

	for (int k = 0; k < v.size(); k++) {
		vector<vector<int>> t = v[k];
		for (int l = 0; l < 4; l++) {
			int vSize = v[k].size();
			vector<vector<int>> t2(vSize, vector<int>(vSize));
			for (int i = 0; i < vSize; i++) {
				for (int j = 0; j < vSize; j++) {
					t2[j][vSize - i - 1] = t[i][j];
				}
			}
			int ok = 1, cnt = 0;
			for (int i = 0; i < vSize; i++) {
				for (int j = 0; j < vSize; j++) {
					if (t2[j][i] != 0) {
						ok = 0;
						break;
					}
				}
				if (!ok)break;
				cnt++;
			}
			for (int i = 0; i < vSize; i++) {
				for (int j = 0; j < vSize; j++) {
					if (j < vSize - cnt)t2[i][j] = t2[i][j + cnt];
					else t2[i][j] = 0;
				}
			}
			ok = 1;
			cnt = 0;
			for (int i = 0; i < vSize; i++) {
				for (int j = 0; j < vSize; j++) {
					if (t2[i][j] != 0) {
						ok = 0;
						break;
					}
				}
				if (!ok)break;
				cnt++;
			}
			for (int i = 0; i < vSize; i++) {
				for (int j = 0; j < vSize; j++) {
					if (i < vSize - cnt)t2[i][j] = t2[i + cnt][j];
					else t2[i][j] = 0;
				}
			}
			rotated.push_back(t2);
			t = t2;
		}
	}
}

void bfs(int i, int j) {

	queue<pair<int, int>> q;
	vector<pair<int, int>> t;
	int minX = 51, minY = 51, maxX = 0, maxY = 0;
	t.push_back({ i,j });
	q.push({ i,j });
	visit[i][j] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		minX = min(minX, a);
		maxX = max(maxX, a);
		minY = min(minY, b);
		maxY = max(maxY, b);
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && table[nx][ny]) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
				t.push_back({ nx,ny });
			}
		}
	}
	v.push_back({});
	int vSize = v.size() - 1;
	int maxSize = max(maxX - minX, maxY - minY);
	v[vSize].resize(maxSize + 1, vector<int>(maxSize + 1));
	for (int i = 0; i < t.size(); i++) {
		v[vSize][t[i].first - minX][t[i].second - minY] = 1;
	}
}

void bfs2(int i, int j) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> t;
	int minX = 51, minY = 51, maxX = 0, maxY = 0;
	t.push_back({ i,j });
	q.push({ i,j });
	visit[i][j] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		minX = min(minX, a);
		maxX = max(maxX, a);
		minY = min(minY, b);
		maxY = max(maxY, b);
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && !game_board[nx][ny]) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
				t.push_back({ nx,ny });
			}
		}
	}
	emp.push_back({});
	int vSize = emp.size() - 1;
	int maxSize = max(maxX - minX, maxY - minY);
	emp[vSize].resize(maxSize + 1, vector<int>(maxSize + 1));
	for (int i = 0; i < t.size(); i++) {
		emp[vSize][t[i].first - minX][t[i].second - minY] = 1;
	}
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = 0;
	::game_board = game_board;
	::table = table;
	n = game_board.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j] && !visit[i][j]) {
				bfs(i, j);
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!game_board[i][j] && !visit[i][j]) {
				bfs2(i, j);
			}
		}
	}

	rotate();

	for (int i = 0; i < emp.size(); i++) {
		for (int j = 0; j < rotated.size(); j++) {
			if (!check[j] && emp[i].size()==rotated[j].size()) {
				int vSize = emp[i].size();
				int ok = 1, cnt = 0;
				for (int k = 0; k < vSize; k++) {
					for (int l = 0; l < vSize; l++) {
						if (emp[i][k][l] != rotated[j][k][l]) {
							ok = 0;
							break;
						}
						if (emp[i][k][l] == 1) {
							cnt++;
						}
					}
					if (!ok)break;
				}
				if (ok) {
					answer += cnt;
					check2[i] = 1;
					for (int l = j - j % 4; l < (j + 4) - (j + 4) % 4; l++) {
						check[l] = 1;
					}
					break;
				}
			}
		}
	}

	return answer;
}
