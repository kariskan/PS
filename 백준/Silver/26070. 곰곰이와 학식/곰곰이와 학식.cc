#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long ans = 0, k;

    k = min(a, d);
    ans += k;
    a -= k;
    d -= k;
    k = min(b, d / 3);
    ans += k;
    b -= k;
    d -= k * 3;
    k = min(c, d / 9);
    ans += k;
    c -= k;
    d -= k * 9;

    k = min(b, e);
    ans += k;
    b -= k;
    e -= k;
    k = min(c, e / 3);
    ans += k;
    c -= k;
    e -= k * 3;
    k = min(a, e / 9);
    ans += k;
    a -= k;
    e -= k * 9;

    k = min(c, f);
    ans += k;
    c -= k;
    f -= k;
    k = min(a, f / 3);
    ans += k;
    c -= k;
    f -= k * 3;
    k = min(b, f / 9);
    ans += k;
    b -= k;
    f -= k * 9;
    
    cout << ans;
}