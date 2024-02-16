#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int g[250000],gCnt=1;
int vis[500][500];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int solution(vector<vector<int>> land) {
    int answer = 0;
    
    queue<pair<int,int>> q;
    
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land[i].size();j++){
            if(land[i][j]&&!vis[i][j]){
                vis[i][j]=gCnt;
                q.push({i,j});
                
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    g[gCnt]++;
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0&&nx<land.size()&&ny>=0&&ny<land[0].size()&&land[nx][ny]&&!vis[nx][ny]){
                            vis[nx][ny]=gCnt;
                            q.push({nx,ny});
                        }
                    }
                }
                gCnt++;
            }
        }
    }
    
    for(int j=0;j<land[0].size();j++){
        int temp=0;
        set<int> se;
        for(int i=0;i<land.size();i++){
            if(land[i][j]){
                se.insert(vis[i][j]);
            }
        }
        for(auto&i:se){
            temp+=g[i];
        }
        answer=max(answer,temp);
    }
    
    return answer;
}