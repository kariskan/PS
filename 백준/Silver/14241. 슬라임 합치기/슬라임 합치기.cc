#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> q;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        q.push(-a);
    }
    int ans = 0;
    while (q.size() != 1) {
        int a = -q.top();
        q.pop();
        int b = -q.top();
        q.pop();
        
        ans += a * b;
        q.push(-(a + b));
    }
    cout << ans;
}