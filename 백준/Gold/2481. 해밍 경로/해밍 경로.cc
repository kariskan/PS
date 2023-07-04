#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int vis[100001];
string s[100001];
map<long long, long long> ma; // 각 입력의 {10진수, 입력 번호}
vector<vector<long long>> v;  // 인접 리스트

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin >> n >> k;
    v.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> s[i];

        long long p = 1, sum = 0;

        // 입력을 2진수로 생각하고, 10진수(sum)로 변환함
        for (int j = k - 1; j >= 0; j--) {
            sum += p * (s[i][j] - '0');
            p *= 2;
        }

        ma[sum] = i;
    }

    // 모든 코드를 돌며
    for (auto &i : ma) {
        // 각 코드의 자리수를 탐색
        for (int j = 0; j < k; j++) {
            // 각 코드의 자리수를 하나씩 바꿔서 매칭되는게 있으면
            if (ma.find(i.first ^ (1 << j)) != ma.end()) {
                // 인접 리스트에 저장
                v[i.second].push_back(ma[i.first ^ (1 << j)]);
            }
        }
    }

    queue<long long> q;
    vis[1] = 1;
    q.push(1);

    // bfs
    while (!q.empty()) {
        long long node = q.front();
        q.pop();

        for (auto &i : v[node]) {
            if (vis[i] == 0) {
                vis[i] = node;
                q.push(i);
            }
        }
    }

    long long m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        long long a;
        cin >> a;
        if (vis[a] == 0) {
            cout << -1 << '\n';
        } else {
            int x = a;
            vector<string> ans;
            cout << 1 << ' ';
            while (x != 1) {
                ans.push_back(to_string(x));
                x = vis[x];
            }
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }
}
