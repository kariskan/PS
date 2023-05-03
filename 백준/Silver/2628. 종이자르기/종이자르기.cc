#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<pair<int, int>, pair<int, int>>> v;

    int n, m, k;
    cin >> n >> m >> k;
    v.push_back({{0, 0}, {n, m}});
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        vector<pair<pair<int, int>, pair<int, int>>> temp;
        if (a == 0) {
            for (int j = 0; j < v.size(); j++) {
                if (v[j].first.second < b && v[j].second.second > b) {
                    temp.push_back({v[j].first, {v[j].second.first, b}});
                    temp.push_back({{v[j].first.first, b}, v[j].second});
                } else {
                    temp.push_back(v[j]);
                }
            }
        } else {
            for (int j = 0; j < v.size(); j++) {
                if (v[j].first.first < b && v[j].second.first > b) {
                    temp.push_back({v[j].first, {b, v[j].second.second}});
                    temp.push_back({{b, v[j].first.second}, v[j].second});
                } else {
                    temp.push_back(v[j]);
                }
            }
        }
        v.clear();
        while (!temp.empty()) {
            v.push_back(temp.back());
            temp.pop_back();
        }
    }

    int ans = 0;

    for (int i = 0; i < v.size(); i++) {
        ans = max(ans, (v[i].second.first - v[i].first.first) * (v[i].second.second - v[i].first.second));
    }

    cout << ans;
}