#include <stdio.h>

int main() {
    int t;
    int n;
    scanf("%d", &t);
    int dp1[41], dp0[41];
    dp1[0] = 0; dp0[0] = 1;
    dp1[1] = 1; dp0[1] = 0;
    dp1[2] = 1; dp0[2] = 1;

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        for (int j = 3; j <= n; j++) {
            dp1[j] = dp1[j - 1] + dp1[j - 2];
            dp0[j] = dp0[j - 1] + dp0[j - 2];
        }
        printf("%d %d\n", dp0[n], dp1[n]);
    }
}