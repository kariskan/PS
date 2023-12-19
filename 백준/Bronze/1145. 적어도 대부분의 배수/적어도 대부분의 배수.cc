#include <iostream>

using namespace std;

int a[5];

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    int ans = 1000000;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                for (int l = k + 1; l < 5; l++) {
                    if (i % a[j] == 0 && i % a[k] == 0 && i % a[l] == 0) {
                        ans = min(ans, i);
                    }
                }
            }
        }
    }
    cout << ans;
}