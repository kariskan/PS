#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int solution(vector<string> board) {
    int answer = -1;
    queue<pair<int,int>> q;
    int vis[100][100]={0,};
    int n=board.size(),m=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='R'){
                vis[i][j]=1;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(board[x][y]=='G'){
            return vis[x][y]-1;
        }
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            while(nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny]!='D'){
                nx+=dx[i];
                ny+=dy[i];
            }
            nx-=dx[i];
            ny-=dy[i];
            if(!vis[nx][ny]){
                vis[nx][ny]=vis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return answer;
}