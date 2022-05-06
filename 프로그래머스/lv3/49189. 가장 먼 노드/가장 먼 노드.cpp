#include <string>
#include <vector>
#include <queue>
using namespace std;
int visit[20001];
queue<int> q;
vector<vector<int>> v;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    v.resize(n + 1);
    for (const vector<int>& e : edge) {
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }
    q.push(1);
    visit[1] = 1;
    int max = 0;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        if (max < visit[a]) {
            max = visit[a];
        }
        for (const int& k : v[a]) {
            if (!visit[k]) {
                visit[k] = visit[a] + 1;
                q.push(k);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (max == visit[i])answer++;
    }
    return answer;
}