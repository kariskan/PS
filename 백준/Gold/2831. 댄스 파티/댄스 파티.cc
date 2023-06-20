#include <algorithm>
#include <iostream>
using namespace std;
vector<int> wm, wp, mm, mp;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            mm.push_back(a); // 남자이면서 음수
        } else {
            mp.push_back(a); // 남자이면서 양수
        }
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            wm.push_back(a); // 여자이면서 음수
        } else {
            wp.push_back(a); // 여자이면서 양수
        }
    }
    sort(mm.begin(), mm.end());
    sort(wp.begin(), wp.end());
    sort(mp.begin(), mp.end());
    sort(wm.begin(), wm.end());

    int ans = 0;
    int idx = 0;
    for (int i = (int)mm.size() - 1; i >= 0; i--) {
        if (idx >= (int)wp.size()) {
            break;
        }
        // 양수인 여자 중 자기보다 키가 작다면
        if (abs(mm[i]) > wp[idx]) {
            idx++;
            ans++;
        }
    }
    idx = 0;
    for (int i = (int)wm.size() - 1; i >= 0; i--) {
        if (idx >= (int)mp.size()) {
            break;
        }
        // 음수인 여자 중 자기보다 키가 크다면
        if (abs(wm[i]) > mp[idx]) {
            ans++;
            idx++;
        }
    }
    cout << ans;
}