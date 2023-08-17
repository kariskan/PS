#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << "Case #" << i << ": ";
        if (n == 0) {
            cout << "INSOMNIA\n";
            continue;
        }
        int temp = n;
        int a[10] = {0}, cnt = 0;
        while (temp) {
            if (!a[temp % 10]) {
                a[temp % 10] = 1;
                cnt++;
            }
            temp /= 10;
        }
        int cur = 2;
        while (cnt != 10) {
            temp = n * cur++;
            while (temp) {
                if (!a[temp % 10]) {
                    a[temp % 10] = 1;
                    cnt++;
                }
                temp /= 10;
            }
        }
        cout << n * (cur - 1) << '\n';
    }
}