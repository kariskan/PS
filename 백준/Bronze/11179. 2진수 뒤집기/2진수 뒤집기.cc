#include <iostream>
using namespace std;

int toBinaryToTen(int n) {
    string s = "";
    while (n) {
        s += (n % 2 + '0');
        n /= 2;
    }

    int res = 0, p = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        res += (s[i] - '0') * p;
        p *= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << toBinaryToTen(n);
}