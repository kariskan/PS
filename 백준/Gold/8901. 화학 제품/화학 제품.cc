#include <iostream>
using namespace std;

int ans, t, a, b, c, ab, bc, ca;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> ab >> bc >> ca;
        
        ans = 0;
        
        int minab = min(a, b);
        for (int i = 0; i <= minab; i++) {
            int minbc = min(b - i, c);
            for (int j = 0; j <= minbc; j++) {
                int minca = min(a - i, c - j);
                ans = max(ans, ab * i + bc * j + minca * ca);
            }
        }
        
        cout << ans << '\n';
    }
}