#include <iostream>
using namespace std;
int a[10];
int visit[10];
int n;
long long ans;
void run(long long energy, int cnt) {
    ans = max(ans, energy);
    if (cnt == 2)return;
    for (int i = 1; i < n - 1; i++) {
        if (!visit[i]) {
            visit[i] = 1;
            int e;
            int k = i - 1;
            while (visit[k]) {
                k--;
            }
            e = a[k];
            k = i + 1;
            while (visit[k]) {
                k++;
            }
            e *= a[k];
            run(energy + e, cnt - 1);
            visit[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    run(0, n);
    cout << ans;
}