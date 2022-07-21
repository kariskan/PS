#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> ans;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 2;
        int pre = n;
        int pos = i;
        vector<int> v;
        v.push_back(pre);
        v.push_back(pos);
        while (pre - pos >= 0) {
            int t = pre - pos;
            pre = pos;
            pos = t;
            cnt++;
            v.push_back(pos);
        }
        if (max < cnt) {
            max = cnt;
            ans = v;
        }
    }
    cout << max << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }
}