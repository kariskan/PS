#include <iostream>
using namespace std;

int a[100001];

int main() {
    int n;
    cin >> n;
    int ans = 0, cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        int c;
        cin >> c;
        if (a[c]) {
            a[c] = 0;
            cnt--;
        } else {
            a[c] = 1;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}