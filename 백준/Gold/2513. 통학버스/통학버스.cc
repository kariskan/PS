#include <iostream>
#include <queue>
using namespace std;

int n, k, s;
pair<int, int> inp[30000];

int main() {
    cin >> n >> k >> s;
    priority_queue<pair<int, int>> left, right;
    for (int i = 0; i < n; i++) {
        cin >> inp[i].first >> inp[i].second;
        if (inp[i].first < s) {
            left.push({-inp[i].first, inp[i].second});
        } else {
            right.push({inp[i].first, inp[i].second});
        }
    }
    int ans = 0;
    while (!left.empty()) {
        int temp = k;
        ans += abs(-left.top().first - s) * 2;
        while (!left.empty() && temp > 0) {
            pair<int, int> top = left.top();
            left.pop();
            int t = min(temp, top.second);
            top.second -= t;
            temp -= t;
            if (top.second != 0) {
                left.push(top);
            }
        }
    }
    while (!right.empty()) {
        int temp = k;
        ans += abs(right.top().first - s) * 2;
        while (!right.empty() && temp > 0) {
            pair<int, int> top = right.top();
            right.pop();
            int t = min(temp, top.second);
            top.second -= t;
            temp -= t;
            if (top.second != 0) {
                right.push(top);
            }
        }
    }
    cout << ans;
}