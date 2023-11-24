#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool isPrime[100000001];

bool isPalindrome(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return s == to_string(n);
}

void go() {
    for (int i = 2; i * i <= 10000000; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= 10000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    go();
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= min(10000000, b); i++) {
        if (isPrime[i] && isPalindrome(i)) {
            cout << i << '\n';
        }
    }
    cout << -1;
}