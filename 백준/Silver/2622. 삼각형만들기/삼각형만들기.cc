#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n - i; j++) {
            int k = n - i - j;
            if (k >= i && k >= j && k < i + j) {
                ans++;
            }
        }
    }
    cout << ans;
}