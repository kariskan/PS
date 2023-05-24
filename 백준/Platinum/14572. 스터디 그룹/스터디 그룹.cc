#include <algorithm>
#include <iostream>
using namespace std;

int n, k, d;
vector<pair<int, vector<int>>> v;

int main() {
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) {
        int m, skill;
        cin >> m >> skill;
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        v.push_back({skill, temp});
    }
    sort(v.begin(), v.end());

    int left = 0, right = 0, ans = 0, algo[31] = {0};

    while (left <= right && right < n) {
        int all = 0;
        int all2 = 0;
        for (int i = 0; i < v[right].second.size(); i++) {
            algo[v[right].second[i]]++;
        }
        for (int i = 1; i <= 30; i++) {
            if (algo[i]) {
                all++;
            }
            if (algo[i] == right - left + 1) {
                all2++;
            }
        }
        ans = max(ans, (all - all2) * (right - left + 1));

        right++;

        while (v[right].first - v[left].first > d) {
            for (int i = 0; i < v[left].second.size(); i++) {
                algo[v[left].second[i]]--;
            }
            left++;
        }
    }
    
    cout << ans;
}