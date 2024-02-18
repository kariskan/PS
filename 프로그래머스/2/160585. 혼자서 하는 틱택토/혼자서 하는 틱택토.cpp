#include <string>
#include <vector>

using namespace std;
int answer;
bool isGameEnd(vector<string> board, char c){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]==c){
            return true;
        }
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[2][i]==c){
            return true;
        }
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]==c){
        return true;
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]==c){
        return true;
    }
    return false;
}
int solution(vector<string> board) {
    int oCnt=0,xCnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='O'){
                oCnt++;
            }
            if(board[i][j]=='X'){
                xCnt++;
            }
        }
    }
    if((isGameEnd(board,'O')&&oCnt<=xCnt)||oCnt<xCnt||(isGameEnd(board,'O')&&isGameEnd(board,'X'))||oCnt>xCnt+1||(isGameEnd(board,'X')&&oCnt!=xCnt)){
        return 0;
    }
    
    return 1;
}