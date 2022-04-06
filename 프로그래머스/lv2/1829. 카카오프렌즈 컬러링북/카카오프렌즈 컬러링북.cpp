#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int visit[100][100];
int cnt[10000];
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(visit, -1, sizeof(visit));
    memset(cnt,0,sizeof(cnt));
    int x[4] = {0,0,1,-1};
    int y[4] = {1,-1,0,0};
    int number_of_area = -1;
    int max_size_of_one_area = 0;
    int pSize = picture.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < pSize; i++) {
        int piSize = picture[i].size();
        for (int j = 0; j < piSize; j++) {
            if (visit[i][j] == -1 && picture[i][j]) {
                int num = picture[i][j];
                number_of_area++;
                visit[i][j] = 1;
                q.push({ i,j });
                while (!q.empty()) {
                    int a, b;
                    a = q.front().first;
                    b = q.front().second;
                    cnt[number_of_area]++;
                    if (cnt[number_of_area]>max_size_of_one_area){
                        max_size_of_one_area= cnt[number_of_area];
                    }
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = a + x[k];
                        int ny = b + y[k];
                        if (nx >= 0 && nx < pSize && ny >= 0 && ny < piSize && visit[nx][ny] == -1 && picture[nx][ny] == num) {
                            visit[nx][ny] = num;
                            q.push({ nx,ny });
                        }
                    }
                }
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area + 1;
    answer[1] = max_size_of_one_area;
    return answer;
}