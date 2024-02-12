#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sticker) {
    int dp[100000][2] = {0,}; //i==0일때 안땜, i==1일때 땜
    dp[0][1] = dp[1][1] = sticker[0];
    dp[1][0] = sticker[1];
    for (int i = 2; i < sticker.size(); i++) {
        dp[i][0] = max(dp[i - 2][0] + sticker[i], dp[i - 1][0]);
        if (i == sticker.size() - 1) {
            dp[i][1] = dp[i - 1][1];
        } else {
            dp[i][1] = max(dp[i - 2][1] + sticker[i], dp[i - 1][1]);
        }
    }
    return max(dp[sticker.size() - 1][0], dp[sticker.size() - 1][1]);
}

