#include <iostream>
#include<vector>
using namespace std;
int map[1001][1001];
int solution(vector<vector<int>> board){
    int n=board.size(),m=board[0].size();
    int answer=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            map[i][j]=board[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]){
                if(map[i-1][j]==0||map[i][j-1]==0){
                    map[i][j]=1;
                    continue;
                }
                int mi=min(map[i-1][j],map[i][j-1]);
                map[i][j]=mi;
                if(i>=mi&&j>=mi&&map[i-mi][j-mi]){
                    map[i][j]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            answer=max(answer,map[i][j]*map[i][j]);
        }
    }
    return answer;
}