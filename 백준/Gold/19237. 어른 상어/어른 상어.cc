#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, k;                   // n: 격자의 길이, m: 상어의 수, k: 냄새가 없어지는데 걸리는 시간
int dir[401];                  // i번째 상어의 현재 방향
pair<int, int> location[401];  // i번째 상어의 현재 위치
int priority[401][5][5];       // i번째 상어가 j방향을 하고 있을 때 우선순위가 높은 순
int sharkCount, ans;           // 현재 상어의 개수, 지난 시간
pair<int, int> smell[20][20];  // {[i,j]에 있는 냄새의 주인, 현재 냄새의 남은 기간}
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

void tearDownSmell() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            smell[i][j].second = max(smell[i][j].second - 1, 0);
            if (smell[i][j].second == 0) {
                smell[i][j].first = 0;
            }
        }
    }
}

bool checkRange(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

int getMaxPriority(int sharkNum, int nowDir, vector<int> q) {
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < q.size(); j++) {
            int nextDir = q[j];
            if (nextDir == priority[sharkNum][nowDir][i]) {
                return nextDir;
            }
        }
    }
    return 0;
}

// 현재 상어의 다음 방향을 찾는 함수
int getNextDir(int sharkNum) {
    int nowDir = dir[sharkNum];
    vector<int> notSmell;  // 아무 냄새가 없는 칸의 방향
    vector<int> mine;      // 나의 냄새의 방향

    for (int i = 1; i <= 4; i++) {
        int nx = location[sharkNum].first + dx[i];
        int ny = location[sharkNum].second + dy[i];
        if (checkRange(nx, ny)) {             // 범위가 맞고
            if (smell[nx][ny].second == 0) {  // 아무 냄새도 안난다면
                notSmell.push_back(i);
            } else if (smell[nx][ny].first == sharkNum) {  // 내 냄새라면
                mine.push_back(i);
            }
        }
    }
    if (notSmell.empty()) {  // 주변의 모든 곳이 냄새가 난다면
        return getMaxPriority(sharkNum, nowDir, mine);
    }
    return getMaxPriority(sharkNum, nowDir, notSmell);
}

int main() {
    cin >> n >> m >> k;
    sharkCount = m;

    // 격자 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            if (c == 0) {
                continue;
            }
            location[c] = {i, j};
            smell[i][j] = {c, k};
        }
    }

    // 상어의 방향 입력
    for (int j = 1; j <= m; j++) {
        cin >> dir[j];
    }

    // 상어의 우선순위 입력
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                cin >> priority[i][j][k];
            }
        }
    }

    // 답이 1000이 넘거나 상어의 개수가 1이되는 순간 종료
    while (ans <= 1000 && sharkCount != 1) {
        priority_queue<int> pq[20][20];
        queue<pair<int, int>> smellQ[20][20];
        for (int i = 1; i <= m; i++) {
            if (dir[i] == 0) {  // 상어가 죽었으면
                continue;
            }

            // 다음 이동할 방향과 위치
            int nextDir = getNextDir(i);
            int nx = location[i].first + dx[nextDir];
            int ny = location[i].second + dy[nextDir];

            pq[nx][ny].push(i);
            dir[i] = nextDir;
            location[i] = {nx, ny};
            smellQ[nx][ny].push({i, k});
        }

        tearDownSmell();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sharkCount -= max(0, (int)pq[i][j].size() - 1);
                while (pq[i][j].size() > 1) {
                    int nowShark = pq[i][j].top();
                    pq[i][j].pop();
                    dir[nowShark] = 0;  // 상어 죽이기
                }
                if (smellQ[i][j].size() >= 1) {
                    smell[i][j] = smellQ[i][j].front();
                }
            }
        }

        ans++;
    }

    if (ans > 1000) {
        cout << -1;
    } else {
        cout << ans;
    }
}