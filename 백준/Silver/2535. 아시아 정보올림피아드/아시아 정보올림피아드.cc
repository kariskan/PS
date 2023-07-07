#include <iostream>
#include <queue>
using namespace std;

int n, cnt[101];
priority_queue<pair<int, pair<int, int>>> q;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        q.push({c, {a, b}});
    }

    int ans = 0;
    while (ans != 3) {
        if (cnt[q.top().second.first] != 2) {
            cnt[q.top().second.first]++;
            cout << q.top().second.first << ' ' << q.top().second.second
                 << '\n';
            ans++;
        }
        q.pop();
    }
}