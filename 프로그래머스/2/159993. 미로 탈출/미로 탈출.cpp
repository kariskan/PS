#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int solution(vector<string> maps) {
    queue<pair<pair<int,int>,int>> q;
    int vis[100][100][2]={0,};
    int n=maps.size(),m=maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]=='S'){
                vis[i][j][0]=1;
                q.push({{i,j},0});
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int flag=q.front().second;
        q.pop();
        if(maps[x][y]=='E'&&flag==1){
            return vis[x][y][flag]-1;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nf=flag;
            if(nx>=0&&nx<n&&ny>=0&&ny<m){
                if(maps[nx][ny]=='L'){
                    nf++;
                }
                if(nf>=2){
                    continue;
                }
                if(maps[nx][ny]!='X'&&!vis[nx][ny][nf]){
                    vis[nx][ny][nf]=vis[x][y][flag]+1;
                    q.push({{nx,ny},nf});
                }
            }
        }
    }
    return -1;
}