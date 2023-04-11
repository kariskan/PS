#include <iostream>
#include <map>
using namespace std;

int a[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 1, right = n / m, ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;  // 각 그룹의 카드 수

        int group = 0;
        map<int, int> se;
        for (int i = 0; i < n; i++) {
            if (se.find(a[i]) != se.end()) {
                i = se[a[i]];
                se.clear();
                continue;
            }
            se[a[i]] = i;
            if (se.size() == mid) {
                group++;
                se.clear();
                continue;
            }
        }

        if (se.size() == mid) {
            group++;
        }

        if (group >= m) {
            left = mid + 1;
            ans = max(ans, mid);
        } else {
            right = mid - 1;
        }
    }

    cout << ans;
}