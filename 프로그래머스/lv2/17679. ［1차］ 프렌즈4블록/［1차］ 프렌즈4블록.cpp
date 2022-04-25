#include <string>
#include <vector>
#include <cstring>
using namespace std;
int x[3] = { 0,1,1 };
int y[3] = { 1,0,1 };
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int visit[30][30] = { 0, };
    while (1) {
        int unless = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == ' ')continue;
                int canClear = 1;
                for (int k = 0; k < 3; k++) {
                    int nx = i + x[k];
                    int ny = j + y[k];
                    if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && board[i][j] == board[nx][ny])) {
                        canClear = 0;
                        break;
                    }
                }
                if (canClear) {
                    if (!visit[i][j]) answer++;
                    if (!visit[i + 1][j]) answer++;
                    if (!visit[i][j + 1]) answer++;
                    if (!visit[i + 1][j + 1]) answer++;
                    unless = 1;
                    visit[i][j] = visit[i + 1][j] = visit[i][j + 1] = visit[i + 1][j + 1] = 1;
                }
            }
        }
        if (!unless)break;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j]) {
                    int idx = i;
                    while (visit[idx][j]) {
                        idx--;
                    }
                    int mi = i - idx;
                    for (int k = i; k >= 0; k--) {
                        if (k - mi >= 0) {
                            visit[k][j] = visit[k - mi][j];
                            board[k][j] = board[k - mi][j];
                        }
                        else {
                            visit[k][j] = 0;
                            board[k][j] = ' ';
                        }
                    }
                }
            }
        }
        memset(visit, 0, sizeof(visit));
    }
    return answer;
}