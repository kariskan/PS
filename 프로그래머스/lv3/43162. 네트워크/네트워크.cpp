#include <string>
#include <vector>

using namespace std;
int visit[200];
void dfs(int idx, int n, vector<vector<int>> computers) {

    for (int i = 0; i < n; i++) {
        if (computers[idx][i] && !visit[i]) {
            visit[i] = 1;
            dfs(i, n, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            visit[i] = 1;
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}