#include <string>
#include <vector>
#include <climits>
using namespace std;

int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int n,m;

bool range(vector<vector<int>> board,int nx,int ny){
    return nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny];
}
bool isGameEnd(vector<vector<int>> board,vector<int> loc){
    for(int i=0;i<4;i++){
        int nx=loc[0]+x[i];
        int ny=loc[1]+y[i];
        if(range(board,nx,ny)){
            return false;
        }
    }
    return true;
}

pair<int,int> go(vector<vector<int>> board,vector<int> a,vector<int> b,int cnt){
    if(isGameEnd(board,a)){
        return {0,0};
    }
    if(a[0]==b[0]&&a[1]==b[1]){
        return {1,1};
    }

    int mi=INT_MAX,ma=INT_MIN,win=0;
    board[a[0]][a[1]]=0;
    for(int i=0;i<4;i++){
        int nx=a[0]+x[i];
        int ny=a[1]+y[i];
        pair<int,int> res;
        if(!range(board,nx,ny)){
            continue;
        }
        res = go(board,b,{nx,ny},cnt+1);
        if(res.first==1){
            ma=max(ma,res.second);
        }else{
            mi=min(mi,res.second);
            win=1;
        }
    }
    board[a[0]][a[1]]=1;

    return {win,win==1?mi+1:ma+1};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = 0;
    n=board.size();
    m=board[0].size();

    return go(board,aloc,bloc,0).second;
}

int main(){
    solution({{1}},{0,0},{0,0});
}