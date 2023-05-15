#include <iostream>
using namespace std;
int a[100];
int main() {
    int n;
    cin >> n;

    int remain = 30;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int res = min(remain, a[i]);
        remain -= res;

        if (res >= (a[i] + 1) / 2) {
            ans++;
        }

        if (remain == 0) {
            remain = 30;
        }
        
    }

    cout << ans;
}