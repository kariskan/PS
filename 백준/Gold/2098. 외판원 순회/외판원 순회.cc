#include <iostream>
#include <vector>
using namespace std;
int n;
int dp[1<<16][16];
int board[16][16];
int dfs(int visited, int now) {
	if(dp[visited][now]) return dp[visited][now];
    if(visited == (1 << n) - 1) {
    	if(board[now][0] == 0) {
        	return 987654321;
        }
        return board[now][0];
    }
    int ret = 987654321;
    
    for(int i = 0; i < n; i++) {
    	if(!(visited & (1 << i)) && board[now][i]) {
        	ret = min(ret, dfs(visited | (1 << i), i) + board[now][i]);
        }
    }
    
    return dp[visited][now] = ret;
}
int main() {
	cin >> n;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
        	cin >> board[i][j];
        }
    }
    cout << dfs(1, 0);
}