#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

long long digit[12];

int main() {
    for (int i = 0; i <= 11; i++) {
        digit[i] = (i + 1) * (long long)pow(10, i) * 9;
    }

    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i <= 10; i++) {
        if (sum + digit[i] >= m) {
            long long std = (long long)pow(10, i);
            long long app = std + (m - sum - 1) / (i + 1);
            if (app > n) {
                cout << -1;
                return 0;
            }
            long long mod = m - (app - std) * (i + 1) - sum;
            string s = to_string(app);
            cout << s[mod - 1];
            return 0;
        }
        sum += digit[i];
    }
}