#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int n;
map<string, int> vis;
queue<string> q;

int main() {
    cin >> n;

    for (int i = 0; i <= 9; i++) {
        vis[to_string(i)] = i;
        q.push(to_string(i));
    }
    int k = 10;

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        if (vis[num] == n) {
            cout << num;
            return 0;
        }
        if (num.length() == 10) {
            continue;
        }
        int lastNum = num[num.length() - 1] - '0';
        for (int i = 0; i < lastNum; i++) {
            if (vis.find(num + to_string(i)) == vis.end()) {
                vis[num + to_string(i)] = k++;
                q.push(num + to_string(i));
            }
        }
    }

    cout << -1;
}