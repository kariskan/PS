#include <algorithm>
#include <iostream>
using namespace std;

int n;
vector<pair<int, int>> v[20001]; // i행의 시작, 끝

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = a * 10, y = b * 10, z = c * 10, w = d * 10;
        for (int j = x; j < x + z; j++) {
            v[j].push_back({y, y + w});
        }
    }
    for (int i = 0; i <= 20000; i++) {
        sort(v[i].begin(), v[i].end());
    }
    long long ans = 0;
    for (int i = 0; i <= 20000; i++) {
        if (v[i].empty()) {
            continue;
        }
        int first = 0, last = 0;
        for (int j = 0; j < v[i].size(); j++) {
            first = max(last, v[i][j].first);
            last = max(last, v[i][j].second);
            ans += last - first;
        }
    }

    if (ans % 100 == 0) {
        cout << ans / 100;
    } else {
        printf("%.2lf", (double)ans / 100);
    }
}