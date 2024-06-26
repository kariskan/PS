#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

bool vis[1501][1501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;

    queue<pair<int, int> > q;
    vis[a][b] = 1;
    q.push({a, b});

    // 20 15 25 , 20 30 10 , 20 20 20

    while (!q.empty()) {
        int first = q.front().first;
        int second = q.front().second;
        int third = sum - first - second;
        q.pop();

        if (first == second && second == third) {
            cout << 1;
            return 0;
        }

        vector<int> v = {first, second, third};
        sort(v.begin(), v.end());

        first = v[0];
        second = v[1];
        third = v[2];

        if (first != second && !vis[first + first][second - first]) {
            q.push({first + first, second - first});
            vis[first + first][second - first] = 1;
        }
        if (first != third && !vis[first + first][third - first]) {
            q.push({first + first, third - first});
            vis[first + first][third - first] = 1;
        }
        if (second != third && !vis[second + second][third - second]) {
            q.push({second + second, third - second});
            vis[second + second][third - second] = 1;
        }
    }
    cout << 0;
}
