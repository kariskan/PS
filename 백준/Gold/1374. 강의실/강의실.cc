#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> arr[100001];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a] = { b,c };
    }

    sort(arr + 1, arr + n + 1);

    priority_queue<int, vector<int>, greater<int>> q; //하고 있는 강의

    int ans = 0;

    for (int i = 1; i <= n; i++) {

        while (!q.empty() && q.top() <= arr[i].first) {
            q.pop();
        }

        q.push(arr[i].second);
        ans = max(ans, (int)q.size());
    }

    cout << ans;
}