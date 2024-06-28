#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int bit[32];

string toBinary(int a) {
    string res = "";
    while (a) {
        res += (a % 2 + '0');
        a /= 2;
    }
    return res;
}

int toDecimal() {
    int res = 0;
    int p = 1;
    for (int i: bit) {
        res += p * (i ? 1 : 0);
        p *= 2;
    }
    return res;
}

void bitwiseOr(string binary, bool exclude) {
    int idx = 0;
    for (char i: binary) {
        if (exclude) {
            bit[idx++] -= (i - '0');
        } else {
            bit[idx++] += (i - '0');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int l = 0, r = 0;

    string firstBinary = toBinary(v[0]);
    for (int i = 0; i < firstBinary.length(); i++) {
        bit[i] += (firstBinary[i] - '0');
    }

    while (r < v.size()) {
        int decimal = toDecimal();
        if (decimal == k) {
            cout << l + 1 << ' ' << r + 1;
            return 0;
        }

        if (decimal < k) {
            r++;
            if (r >= v.size()) {
                break;
            }
            string s = toBinary(v[r]);
            bitwiseOr(s, false);
        } else {
            string s = toBinary(v[l++]);
            bitwiseOr(s, true);
        }
    }
    cout << -1;

}