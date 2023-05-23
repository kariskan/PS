#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

int main() {
    while (1) {
        int n;
        cin >> n;
        long long ans = LLONG_MAX;
        if (!n) {
            break;
        }
        int a[14] = {0};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < (1 << n) - 1; i++) {
            string first = "";
            string second = "";

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    first += (a[j] + '0');
                } else {
                    second += (a[j] + '0');
                }
            }
            sort(first.begin(), first.end());
            sort(second.begin(), second.end());
            int idx = 0;
            while (idx < first.length() && first[idx] == '0') {
                idx++;
            }
            if (idx < first.length()) {
                swap(first[0], first[idx]);
            }

            idx = 0;
            while (idx < second.length() && second[idx] == '0') {
                idx++;
            }
            if (idx < second.length()) {
                swap(second[0], second[idx]);
            }
            if (first[0] == '0' || second[0] == '0') {
                continue;
            }
            ans = min(ans, stoll(first) + stoll(second));
        }
        cout << ans << '\n';
    }
}