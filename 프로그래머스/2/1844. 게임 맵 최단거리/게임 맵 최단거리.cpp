#include<vector>
#include<queue>
using namespace std;
int vis[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int solution(vector<vector<int>> maps){
    int n=maps.size(),m=maps[0].size();
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==n-1&&y==m-1){
            return vis[x][y];
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&maps[nx][ny]==1){
                vis[nx][ny]=vis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}