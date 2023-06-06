#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[1000] = {0};
        set<int> se;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            se.insert(a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(a[i] + a[j]) % 2 == 1) {
                    continue;
                }
                if (se.find((a[i] + a[j]) / 2) != se.end()) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}