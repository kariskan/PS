#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> horizon, vertical;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        horizon[a]++;
        vertical[b]++;
    }
    int ans = 0;
    for (auto &i : horizon) {
        if (i.second >= 2) {
            ans++;
        }
    }
    for (auto &i : vertical) {
        if (i.second >= 2) {
            ans++;
        }
    }
    cout << ans;
}