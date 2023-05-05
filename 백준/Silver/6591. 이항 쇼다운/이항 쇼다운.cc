#include <iostream>
#include <vector>
using namespace std;

long long gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    while (1) {
        vector<int> v, v2;
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        for (int i = a - min(b, a - b) + 1; i <= a; i++) {
            v.push_back(i);
        }

        for (int i = 1; i <= min(b, a - b); i++) {
            v2.push_back(i);
        }

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                int g = gcd(v[i], v2[j]);
                v[i] /= g;
                v2[j] /= g;
            }
        }
        int ans = 1;
        for (int i = 0; i < v.size(); i++) {
            ans *= v[i];
        }
        cout << ans << '\n';
    }
}