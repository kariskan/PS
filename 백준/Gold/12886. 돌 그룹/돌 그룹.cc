#include <iostream>
#include <queue>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;
int visit[501][501][501];
tuple<int, int, int> s(tuple<int, int, int>t) {
    int f1 = get<0>(t);
    int f2 = get<1>(t);
    int f3 = get<2>(t);
    if (f1 > f2) {
        if (f3 > f1) return { f2,f1,f3 };
        else {
            if (f2 > f3) return { f3,f2,f1 };
            else return { f2,f3,f1 };
        }
    }
    else {
        if (f3 > f2) return { f1,f2,f3 };
        else {
            if (f1 > f3)return{ f3,f1,f2 };
            else return{ f1,f3,f2 };
        }
    }
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    queue<tuple<int, int, int>> q;
    q.push(s({ a,b,c }));
    while (!q.empty()) {
        tuple<int, int, int> t = q.front();
        q.pop();
        int f0 = get<0>(t);
        int f1 = get<1>(t);
        int f2 = get<2>(t);
        if (f0 == f1 && f1 == f2) {
            cout << 1;
            return 0;
        }
        tuple<int, int, int> temp;
        if (f0 != f1) {
            temp = s({ f0 * 2,f1 - f0,f2 });
            if (!visit[get<0>(temp)][get<1>(temp)][get<2>(temp)]) {
                q.push(temp);
                visit[get<0>(temp)][get<1>(temp)][get<2>(temp)] = 1;
            }
        }
        if (f0 != f2) {
            temp = s({ f0 * 2,f1,f2 - f0 });
            if (!visit[get<0>(temp)][get<1>(temp)][get<2>(temp)]) {
                q.push(temp);
                visit[get<0>(temp)][get<1>(temp)][get<2>(temp)] = 1;
            }
        }
        if (f1 != f2) {
            temp = s({ f0,f1 * 2,f2 - f1 });
            if (!visit[get<0>(temp)][get<1>(temp)][get<2>(temp)]) {
                q.push(temp);
                visit[get<0>(temp)][get<1>(temp)][get<2>(temp)] = 1;
            }
        }
    }
    cout << 0;
}