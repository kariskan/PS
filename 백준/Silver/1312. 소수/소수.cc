#include <iostream>
using namespace std;

int a, b, n;

int main() {
    cin >> a >> b >> n;

    if (a % b == 0) {
        cout << 0;
    } else {
        int mod = 0;
        for (int i = 0; i < n; i++) {
            a = (a - (a / b) * b) * 10;
            mod = a / b;
        }
        cout << mod;
    }
}