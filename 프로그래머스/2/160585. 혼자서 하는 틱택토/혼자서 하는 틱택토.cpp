#include <string>
#include <vector>

using namespace std;
vector<string> board;
int cnt;
int answer;
bool isGameEnd(vector<string> now){
    for(int i=0;i<3;i++){
        if(now[i][0]!='.'&&now[i][0]==now[i][1]&&now[i][1]==now[i][2]){
            return true;
        }
        if(now[0][i]!='.'&&now[0][i]==now[1][i]&&now[1][i]==now[2][i]){
            return true;
        }
    }
    if(now[0][0]!='.'&&now[0][0]==now[1][1]&&now[1][1]==now[2][2]){
        return true;
    }
    if(now[0][2]!='.'&&now[0][2]==now[1][1]&&now[1][1]==now[2][0]){
        return true;
    }
    return false;
}
void go(vector<string> now, int flag, int c){
    if(c==cnt||isGameEnd(now)){
        bool f=true;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(now[i][j]!=board[i][j]){
                    f=false;
                    break;
                }
            }
        }
        if(f){
            answer=1;
        }
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(now[i][j]=='.'){
                if(flag==0){
                    now[i][j]='O';
                }else{
                    now[i][j]='X';
                }
                go(now,1-flag,c+1);
                now[i][j]='.';
            }
        }
    }
}

int solution(vector<string> board) {
    ::board=board;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j]!='.'){
                cnt++;
            }
        }
    }
    go({"...","...","..."},0,0);
    return answer;
}