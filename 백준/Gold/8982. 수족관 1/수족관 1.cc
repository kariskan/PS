#include <algorithm>
#include <iostream>
using namespace std;

int n, k, hole[2500];
pair<int, int> x[40001];

int main() {
    cin >> n;
    int t1, t2;
    cin >> t1 >> t2;
    int width;
    for (int i = 0; i < n / 2 - 1; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j < c; j++) {
            x[j].first = b;
        }
    }
    cin >> width >> t2 >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        hole[i] = a;
    }

    for (int i = 0; i < k; i++) {
        int height = x[hole[i]].first;
        x[hole[i]].second = height;

        for (int j = hole[i] - 1; j >= 0; j--) {
            height = min(height, x[j].first);
            x[j].second = max(x[j].second, height);
        }
        height = x[hole[i]].first;
        for (int j = hole[i] + 1; j < width; j++) {
            height = min(height, x[j].first);
            x[j].second = max(x[j].second, height);
        }
    }
    int ans = 0;
    for (int i = 0; i < width; i++) {
        ans += x[i].first - x[i].second;
    }
    cout << ans;
}