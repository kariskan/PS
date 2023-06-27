#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

string intToBinary(unsigned long long a) {
    string res(64, '0');
    int idx = 0;
    while (a) {
        res[idx++] = (a % 2 + '0');
        a /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

unsigned long long binaryToUll(string binary) {
    unsigned long long res = 0;
    unsigned long long p = 1;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            res += p;
        }
        p *= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            string s;
            cin >> s;
            stringstream ss(s);
            string t;
            string binary = "";
            while (getline(ss, t, '.')) {
                binary += intToBinary(stoull(t)).substr(56);
            }
            cout << binaryToUll(binary) << '\n';
        } else {
            unsigned long long a;
            cin >> a;
            string res = intToBinary(a);
            for (int i = 0; i < res.length(); i += 8) {
                cout << binaryToUll(res.substr(i, 8));
                if (i < res.length() - 9) {
                    cout << ".";
                }
            }
            cout << '\n';
        }
    }
}