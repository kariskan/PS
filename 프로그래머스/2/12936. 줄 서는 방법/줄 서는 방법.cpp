#include <string>
#include <vector>

using namespace std;

long long getNFac(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int vis[21];

vector<int> solution(int n, long long k) {
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        int d = (k - 1) / getNFac(n - i - 1) + 1;
        k -= (d-1)*getNFac(n - i - 1);
        for (int j = 1; j <= 20; j++) {
            if (!vis[j]) {
                d--;
                if (d == 0) {
                    answer.push_back(j);
                    vis[j] = 1;
                    break;
                }
            }
        }
    }
    return answer;
}