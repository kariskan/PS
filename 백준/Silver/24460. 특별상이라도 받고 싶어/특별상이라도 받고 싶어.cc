#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int map[1025][1025], n;

int go(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return map[x1][y1];
    }

    vector<int> v;
    v.push_back(go(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2));
    v.push_back(go((x1 + x2 + 1) / 2, y1, x2, (y1 + y2) / 2));
    v.push_back(go(x1, (y1 + y2 + 1) / 2, (x1 + x2) / 2, y2));
    v.push_back(go((x1 + x2 + 1) / 2, (y1 + y2 + 1) / 2, x2, y2));
    sort(v.begin(), v.end());
    return v[1];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    cout << go(1, 1, n, n);
}