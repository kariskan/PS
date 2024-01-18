#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int vis[500][500], cnt[250001];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n=land.size(),m=land[0].size();
    int visCnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&land[i][j]){
                queue<pair<int, int>> q;
                visCnt++;
                
                vis[i][j]=visCnt;
                q.push({i,j});
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    cnt[visCnt]++;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&land[nx][ny]){
                            vis[nx][ny]=visCnt;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    for(int j=0;j<m;j++){
        set<int> se;
        int sum=0;
        for(int i=0;i<n;i++){
            if(!land[i][j]||se.find(vis[i][j])!=se.end()){
                continue;
            }
            sum+=cnt[vis[i][j]];
            se.insert(vis[i][j]);
        }
        answer=max(answer,sum);
    }
    return answer;
}