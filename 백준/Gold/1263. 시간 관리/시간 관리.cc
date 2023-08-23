#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.second < p2.second;
}

int n;
pair<int, int> p[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    
    sort(p, p + n, compare);
    
    int l = 0, r = p[0].second - p[0].first, ans = -1;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        
        bool flag = true;
        int pre = mid;
        for (int i = 0; i < n; i++) {
            if (pre + p[i].first > p[i].second || pre + p[i].first > 1000000) {
                flag = false;
                break;
            }
            pre += p[i].first;
        }
        
        if (flag) {
            if (ans == -1 || ans < mid) {
                ans = mid;
            }
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}