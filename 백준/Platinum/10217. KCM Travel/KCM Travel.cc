#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int T, N, M, K;

// distance, cost, location
vector<vector<pair<pair<int, int>, int>>> board;
//distance
vector<vector<int>> dist;

int dijkstra(int start) {
    // distance, cost, location
    priority_queue<pair<pair<int, int>, int>> pq;
    dist[start][0] = 0;
    pq.push({{0, 0}, start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int curDist = -pq.top().first.first;
        int curCost = -pq.top().first.second;
        pq.pop();

        if(dist[cur][curCost] < curDist) continue;
        if(curCost > M) continue;

        if(cur == N) return curDist;
        // cout << curCost << '\n';



        for(int i = 0; i < board[cur].size(); i++) {
            int next = board[cur][i].second;
            int nextDist = board[cur][i].first.first + curDist;
            int nextCost = board[cur][i].first.second + curCost;
            // cout << nextCost << '\n';
            if(nextCost > M) continue;
            if(nextDist < dist[next][nextCost]) {
                dist[next][nextCost] = nextDist;
                pq.push({{-nextDist, -nextCost}, next});
            }

        }

    }

    return -1;
}


int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int tCase = 0; tCase < T; tCase++) {
        cin >> N >> M >> K;

        if(N == 1) {
            cout << "0\n";
        } else if(K == 0) {
            cout << "Poor KCM\n";
        }

        
        // {pos, {cost, distance}}
        board.assign(N + 1, vector<pair<pair<int, int>, int>>());
        dist.assign(N + 1, vector<int>(M + 1, INF));

        int u, v, c, d;
        for(int i = 0; i < K; i++) {
            cin >> u >> v >> c >> d;
            board[u].push_back({{d, c}, v});
        }

        int temp = dijkstra(1);
        if(temp == -1) {
            cout << "Poor KCM\n";
        } else {
            cout << temp << '\n';
        }
        

    }


    return 0;
}