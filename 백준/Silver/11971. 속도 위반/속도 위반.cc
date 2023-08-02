#include <iostream>
using namespace std;

int n, m, dis[101];
pair<int, int> inp[101];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> inp[i].first >> inp[i].second;
    }
    int pre = 1;
    for (int i = 0; i < n; i++) {
        for (int j = pre; j <= pre + inp[i].first - 1; j++) {
            dis[j] = inp[i].second;
        }
        pre += inp[i].first;
    }
    for (int i = 0; i < m; i++) {
        cin >> inp[i].first >> inp[i].second;
    }
    pre = 1;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = pre; j <= pre + inp[i].first - 1; j++) {
            ans = max(ans, inp[i].second - dis[j]);
        }
        pre += inp[i].first;
    }
    cout << ans;
}