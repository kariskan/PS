#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    map<int, int> ma;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a;
        if (a == 1) {
            cin >> b;
            ma[b]++;
        } else if (a == 2) {
            cin >> b;
            ma[b]--;
            if (ma[b] <= 0) {
                ma.erase(b);
            }
        } else {
            if (ma.empty()) {
                cout << "0\n";
                continue;
            }
            int pre = ma.begin()->first;
            int cnt = 1;
            while (ma.lower_bound(pre * 2)->second > 0) {
                cnt++;
                pre = ma.lower_bound(pre * 2)->first;
            }
            cout << cnt << '\n';
        }
    }
}