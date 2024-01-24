#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[100][100];
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(vis,0,sizeof(vis));
    int ground=0,ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]&&picture[i][j]){
                ground++;
                queue<pair<int,int>>q;
                vis[i][j]=1;
                q.push({i,j});
                int cnt=0;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    cnt++;
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0&&nx<m&&ny>=0&&ny<n&&!vis[nx][ny]&&picture[nx][ny]==picture[x][y]){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
                ans=max(ans,cnt);
            }
        }
    }
    return {ground,ans};
}