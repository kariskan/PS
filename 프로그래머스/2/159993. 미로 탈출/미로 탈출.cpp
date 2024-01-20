#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[100][100];
int n,m;
vector<string> maps;

int bfs(int sx, int sy, int ex, int ey){
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==ex&&y==ey){
            return vis[x][y]-1;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&maps[nx][ny]!='X'){
                vis[nx][ny]=vis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}
int solution(vector<string> maps) {
    ::maps=maps;
    int sx,sy,ex,ey,lx,ly;
    n=maps.size(),m=maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]=='S'){
                sx=i;
                sy=j;
            }
            if(maps[i][j]=='L'){
                lx=i;
                ly=j;
            }
            if(maps[i][j]=='E'){
                ex=i;
                ey=j;
            }
        }
    }
    int first=bfs(sx,sy,lx,ly);
    int second=bfs(lx,ly,ex,ey);
    if(first==-1||second==-1){
        return -1;
    }
    return first+second;
}