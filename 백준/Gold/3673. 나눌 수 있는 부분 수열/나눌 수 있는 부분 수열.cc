#include <cstring>
#include <iostream>
using namespace std;

long long c, a[50001], s[1000001], mod[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> c;

    while (c--) {
        memset(s, 0, sizeof(s));
        memset(mod, 0, sizeof(mod));

        long long d, n;
        cin >> d >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
            s[i] %= d;
            mod[s[i]]++;
        }

        long long ans = 0;

        for (int i = 0; i < d; i++) {
            ans += mod[i] * (mod[i] - 1) / 2;
        }

        cout << mod[0] + ans << '\n';
    }
}