#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[100][100];
queue<pair<int, int>>q;
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n=maps.size(),m=maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]!='X'&&!vis[i][j]){
                q.push({i,j});
                vis[i][j]=1;
                int s=0;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    s+=maps[x][y]-'0';
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&maps[nx][ny]!='X'){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
                answer.push_back(s);
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty()){
        return {-1};
    }
    return answer;
}