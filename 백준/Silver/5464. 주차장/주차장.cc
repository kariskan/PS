#include <iostream>
#include <queue>
using namespace std;

int n, m, fee[101], weight[2001], park[101], remainPark;
long long ans;

int main() {
    cin >> n >> m;
    remainPark = n;
    for (int i = 1; i <= n; i++) {
        cin >> fee[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> weight[i];
    }

    queue<int> wait;

    for (int i = 1; i <= 2 * m; i++) {
        int a;
        cin >> a;

        if (a > 0) {
            if (remainPark) {
                int idx;
                for (int j = 1; j <= n; j++) {
                    if (!park[j]) {
                        idx = j;
                        break;
                    }
                }
                remainPark--;
                park[idx] = a;
                ans += fee[idx] * weight[a];
            } else {
                wait.push(a);
            }
        } else {
            a = -a;
            int idx;
            for (int j = 1; j <= n; j++) {
                if (park[j] == a) {
                    park[j] = 0;
                    idx = j;
                    break;
                }
            }
            
            if (!wait.empty()) {
                int first = wait.front();
                wait.pop();
                
                park[idx] = first;
                ans += fee[idx] * weight[first];
            } else {
                remainPark++;
            }
        }
    }

    cout << ans;
}