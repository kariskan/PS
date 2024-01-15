#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int vis[500][500], g[250001];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int solution(vector<vector<int>> land) {
    int n=land.size(),m=land[0].size();
    int answer = 0, visCnt = 1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (!vis[i][j] && land[i][j]){
                queue<pair<int, int>> q;
                g[visCnt]=1;
                vis[i][j]=visCnt++;
                q.push({i,j});
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0&&nx<n&ny>=0&&ny<m&&!vis[nx][ny]&&land[nx][ny]==1){
                            vis[nx][ny]=vis[x][y];
                            g[vis[nx][ny]]++;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    
    for(int j=0;j<m;j++){
        set<int> k;
        int sum=0;
        for(int i=0;i<n;i++){
            if(k.find(vis[i][j]) == k.end()){
                k.insert(vis[i][j]);
                sum+=g[vis[i][j]];
            }
        }
        answer=max(answer,sum);
    }
    
    return answer;
}