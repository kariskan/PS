#include <iostream>
#include <map>
#include <string>
using namespace std;

struct mat {
    long long first;
    long long second;
    long long third;
    long long fourth;
};

long long mod = 1000000000;
map<long long, mat> ma;

long long bigMod(string a, long long b) {
    long long res = 0;

    for (long long i = 0; i < a.length(); i++) {
        res = (res * 10) + (a[i] - '0');
        res %= b;
    }
    return res;
}

mat go(long long n) {
    if (ma.find(n) != ma.end()) {
        return ma[n];
    }
    if (n == 1) {
        return {1, 1, 1, 0};
    }

    long long mid = n / 2;

    mat left = go(mid);
    mat right = go(n - mid);

    mat m;
    m.first = bigMod(to_string((left.first * right.first) + (left.second * right.third) + mod), mod);
    m.second = bigMod(to_string((left.first * right.second) + (left.second * right.fourth) + mod), mod);
    m.third = m.second;
    m.fourth = bigMod(to_string((left.third * right.second) + (left.fourth * right.fourth) + mod), mod);

    return ma[n] = m;
}

int main() {
    long long a, b;

    cin >> a >> b;

    cout << (go(b + 2).second - 1 - (go(a + 1).second - 1) + mod) % mod;
}