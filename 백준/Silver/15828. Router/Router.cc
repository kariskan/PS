#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    while (1) {
        int a;
        cin >> a;
        if (a == -1) {
            break;
        }
        if (a == 0) {
            q.pop();
            continue;
        }
        if (q.size() < n) {
            q.push(a);
        }
    }
    if (q.empty()) {
        cout << "empty";
        return 0;
    }
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
}