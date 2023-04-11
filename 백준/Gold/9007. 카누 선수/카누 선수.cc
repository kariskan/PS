#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v[4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                v[i].push_back(a);
            }
        }
        vector<int> v1, v2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                v1.push_back(v[0][i] + v[1][j]);
                v2.push_back(v[2][i] + v[3][j]);
            }
        }
        sort(v2.begin(), v2.end());
        int ans = -200000000;
        for (int i = 0; i < v1.size(); i++) {
            int a = v1[i];

            int left = 0, right = v2.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;

                int sum = a + v2[mid];
                if (sum > n) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }

                if (abs(ans - n) > abs(sum - n) || (abs(ans - n) == abs(sum - n) && ans > sum)) {
                    ans = sum;
                }
            }
        }

        cout << ans << '\n';
    }
}