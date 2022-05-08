#include <string>
#include <vector>
using namespace std;

bool res[101][101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (const vector<int>& r : results) {
        res[r[0]][r[1]] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (res[i][k] && res[k][j])res[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (res[i][j] || res[j][i])sum++;
        }
        if (sum == n - 1)answer++;
    }

    return answer;
}