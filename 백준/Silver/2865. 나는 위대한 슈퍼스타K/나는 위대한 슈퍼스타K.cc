#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m, k;
vector<vector<double>> v;

int main() {
    cin >> n >> m >> k;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            double score;
            cin >> num >> score;
            v[num].push_back(score);
        }
    }
    priority_queue<double> pq;
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
        pq.push(v[i].back());
    }
    double ans = 0;
    while (k--) {
        ans += pq.top();
        pq.pop();
    }
    cout.precision(1);
    cout << fixed << round(ans * 10) / 10;
}