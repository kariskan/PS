#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int score[101] = {0};
    map<int, int> ma; // num, score
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }
    int ans = 0, ansNum = -1;
    for (int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        ma[num] = 0;
        for (int j = 1; j <= n; j++) {
            char a;
            cin >> a;
            if (a == 'O') {
                ma[num] += score[j];
            }
        }
        if (ansNum == -1) {
            ansNum = num;
            ans = ma[ansNum];
        }
    }
    
    for (auto &i : ma) {
        if (ans < i.second || (ans == i.second && ansNum > i.first)) {
            ans = i.second;
            ansNum = i.first;
        }
    }
    cout << ansNum << ' ' << ans;
}