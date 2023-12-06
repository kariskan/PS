#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool prime[1000001];
queue<long long> v;

void go() {
    for (int i = 2; i * i <= 1000000; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= 1000000; j += i) {
                prime[j] = false;
            }
        }
    }
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    go();

    for (int i = 0; i < n; i++) {
        long long c;
        cin >> c;
        if (prime[c]) {
            v.push(c);
        }
    }

    while (v.size() >= 2) {
        long long a1 = v.front();
        v.pop();
        long long a2 = v.front();
        v.pop();

        v.push((a1 * a2) / gcd(a1, a2));
    }

    if (v.empty()) {
        cout << -1;
    } else {
        cout << v.front();
    }
}