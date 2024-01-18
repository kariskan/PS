#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<vector<int>> v;
int n, start;
bool vis[1000001];
vector<int> answer(4);

// 현재 정점, 정점 개수, 간선 개수
void bfs() {
    for (int i = 0; i < v[start].size(); i++) {
        queue<int> q;
        int now = v[start][i], nodeCnt = 0;
        vector<int> nodeInfos;
        q.push(now);

        vis[now] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            nodeCnt++;
            nodeInfos.push_back(node);

            for (auto &j: v[node]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }

        int edgeSum = 0;
        for (int nodeInfo : nodeInfos) {
            edgeSum += v[nodeInfo].size();
        }

        if (edgeSum == nodeCnt + 1) {
            answer[3]++;
            continue;
        } else if (edgeSum == nodeCnt - 1) {
            answer[2]++;
            continue;
        }
        answer[1]++;
    }
}

vector<int> solution(vector<vector<int>> edges) {

    v.resize(1000001);

    for (auto &edge: edges) {
        int from = edge[0];
        int to = edge[1];
        n = max(n, max(from, to));
        vis[to] = true;

        v[from].push_back(to);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && v[i].size() >= 2) {
            answer[0] = start = i;
            break;
        }
    }

    memset(vis, false, sizeof(vis));
    bfs();

    return answer;
}

int main() {
    solution({{2,3},{4,3},{1,1},{2,1}});
    solution({{4,11},{1,12},{8,3},{12,7},{4,2},{7,11},{4,8},{9,6},{10,11},{6,10},{3,5},{11,1},{5,3},{11,9},{3,8}});
}