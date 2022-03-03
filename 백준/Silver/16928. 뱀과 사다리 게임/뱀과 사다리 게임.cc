#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    int next[101] = { 0, };
    int visit[101] = { 0, };
    for (int i = 1; i <= 100; i++)next[i] = i;
    for (int i = 0; i < n + m; i++) {
        int a, b;
        cin >> a >> b;
        next[a] = b;
    }
    visit[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int y = a + i;
            if (y > 100)continue;
            y = next[y];
            if (!visit[y]) {
                visit[y] = visit[a] + 1;
                q.push(y);
            }
        }
    }
    cout << visit[100] - 1;
}