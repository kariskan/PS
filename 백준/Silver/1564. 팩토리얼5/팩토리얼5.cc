#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    long long s = 1;
    for (int i = 1; i <= n; i++) {
        s = (s % 1000000000000) * i;
        while (s % 10 == 0) {
            s /= 10;
        }
    }

    s %= 100000;
    long long temp = s, dig = 0;
    while (temp) {
        dig++;
        temp /= 10;
    }
    for (int i = 0; i < 5 - dig; i++) {
        cout << 0;
    }
    cout << s;
}