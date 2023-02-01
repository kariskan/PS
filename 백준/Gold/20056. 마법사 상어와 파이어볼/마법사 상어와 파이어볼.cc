#include <iostream>
#include <vector>
using namespace std;
int x[8] = { -1,-1,0,1,1,1,0,-1 };
int y[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<int> M[51][51], S[51][51], D[51][51], map[51][51];
vector<int> tempM[51][51], tempS[51][51], tempD[51][51], tempMap[51][51];
int main() {
	int n, m, T;
	cin >> n >> m >> T;
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		map[a][b].push_back(1);
		M[a][b].push_back(c);
		S[a][b].push_back(d);
		D[a][b].push_back(e);
	}
	for (int t = 0; t < T; t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!map[i][j].empty()) {
					int size = map[i][j].size();
					for (int k = 0; k < size; k++) {
						if (map[i][j][k]) {
							int nx = i;
							int ny = j;
							for (int l = 0; l < S[i][j][k]; l++) {
								nx += x[D[i][j][k]];
								ny += y[D[i][j][k]];
								if (nx == 0)nx = n;
								if (nx > n)nx = 1;
								if (ny == 0)ny = n;
								if (ny > n)ny = 1;
							}
							tempMap[nx][ny].push_back(map[i][j][k]);
							map[i][j].erase(map[i][j].begin());
							tempM[nx][ny].push_back(M[i][j][k]);
							M[i][j].erase(M[i][j].begin());
							tempS[nx][ny].push_back(S[i][j][k]);
							S[i][j].erase(S[i][j].begin());
							tempD[nx][ny].push_back(D[i][j][k]);
							D[i][j].erase(D[i][j].begin());
							k--;
							size--;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!tempMap[i][j].empty()) {
					int size = tempMap[i][j].size();
					if (size == 1) {
						D[i][j].push_back(tempD[i][j][0]);
						map[i][j].push_back(tempMap[i][j][0]);
						M[i][j].push_back(tempM[i][j][0]);
						S[i][j].push_back(tempS[i][j][0]);
					}
					else {
						int mSum = 0, sSum = 0;
						bool isH = false, isJ = false; //홀-짝
						for (int k = 0; k < size; k++) {
							mSum += tempM[i][j][k];
							sSum += tempS[i][j][k];
							if (tempD[i][j][k] % 2 == 0)isJ = true;
							else isH = true;
						}
						if (mSum / 5) {
							for (int k = 0; k < 4; k++) {
								if ((isJ && !isH) || (isH && !isJ)) {
									D[i][j].push_back(k * 2);
								}
								else {
									D[i][j].push_back(k * 2 + 1);
								}
								map[i][j].push_back(1);
								M[i][j].push_back(mSum / 5);
								S[i][j].push_back(sSum / size);
							}
						}
					}
					tempMap[i][j].clear();
					tempS[i][j].clear();
					tempM[i][j].clear();
					tempD[i][j].clear();
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!map[i][j].empty()) {
				for (int s : M[i][j]) {
					ans += s;
				}
			}
		}
	}
	cout << ans;
}