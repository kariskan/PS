#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

pair<pair<int, int>, int> inp[300000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inp[i].first.first >> inp[i].first.second;
        inp[i].second = i + 1;
    }
    sort(inp, inp + n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.top().first < inp[i].first.first) {
            q.pop();
        }
        q.push({inp[i].first.second, inp[i].second});
        ans = max(ans, (int)q.size());
    }
    cout << ans << '\n';
    
    while (!q.empty()) q.pop();
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.top().first < inp[i].first.first) {
            q.pop();
        }
        q.push({inp[i].first.second, inp[i].second});
        
        if (ans == (int)q.size()) {
            while(!q.empty()) {
                cout << q.top().second << ' ';
                q.pop();
            }
            return 0;
        }
    }    
}