#include <iostream>
#include <map>
using namespace std;

struct mat {
    long long first;
    long long second;
    long long third;
    long long fourth;
};

long long mod = 1000000007;
map<long long, mat> ma;

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
    m.first = (left.first * right.first + left.second * right.third) % mod;
    m.second = (left.first * right.second + left.second * right.fourth) % mod;
    m.third = (left.third * right.first + left.fourth * right.third) % mod;
    m.fourth = (left.third * right.second + left.fourth * right.fourth) % mod;

    return ma[n] = m;
}

int main() {
    long long n;
    cin >> n;
    if (n % 2 == 0) {
        cout << go(n).second;
    } else {
        cout << go(n + 1).second;
    }
}