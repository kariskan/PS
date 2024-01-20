#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[4][100][100];
int solution(vector<string> board) {
    int n=board.size(),m=board[0].size();
    int sx,sy;
    queue<pair<int,pair<int, int>>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='R'){
                sx=i;
                sy=j;
                for(int k=0;k<4;k++){
                    q.push({k,{i,j}});
                    vis[k][i][j]=1;
                }
            }
        }
    }
    while(!q.empty()){
        int dir=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        q.pop();
        if(board[x][y]=='G'){
            return vis[dir][x][y]-1;
        }
        for(int i=0;i<4;i++){
            int nx=x;
            int ny=y;
            while(nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny]!='D'){
                nx+=dx[i];
                ny+=dy[i];
            }
            nx-=dx[i];
            ny-=dy[i];
            if(!vis[i][nx][ny]){
                vis[i][nx][ny]=vis[dir][x][y]+1;
                q.push({i,{nx,ny}});
            }
        }
    }
    return -1;
}