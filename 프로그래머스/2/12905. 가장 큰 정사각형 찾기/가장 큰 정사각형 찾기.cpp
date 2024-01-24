#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer=0;
    int n=board.size(),m=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]){
                answer=max(answer,1);
            }
            if(i==0||j==0||!board[i-1][j]||!board[i][j-1]||!board[i][j]){
                continue;
            }
            int mi=min(board[i-1][j],board[i][j-1]);
            board[i][j]=mi;
            if(board[i-mi][j-mi]){
                board[i][j]++;
            }
            answer=max(answer,board[i][j]*board[i][j]);
        }
    }
    return answer;
}