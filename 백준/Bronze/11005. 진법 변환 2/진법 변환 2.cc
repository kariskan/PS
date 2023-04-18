#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s = "";

    while (n) {
        int num = n % m;
        if (num >= 10) {
            s += num - 10 + 'A';
        } else {
            s += num + '0';
        }
        n /= m;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }
}