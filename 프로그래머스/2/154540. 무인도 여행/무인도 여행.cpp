#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[100][100];
vector<string> maps;
int get(int x,int y){
    int n=maps.size(),m=maps[0].size();
    queue<pair<int,int>> q;
    
    vis[x][y]=1;
    q.push({x,y});
    int res=0;
    while(!q.empty()){
        int sx=q.front().first;
        int sy=q.front().second;
        q.pop();
        res+=(maps[sx][sy]-'0');
        for(int i=0;i<4;i++){
            int nx=sx+dx[i];
            int ny=sy+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&maps[nx][ny]!='X'){
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
    }
    return res;
}
vector<int> solution(vector<string> maps) {
    ::maps=maps;
    vector<int> answer;
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(!vis[i][j]&&maps[i][j]!='X'){
                answer.push_back(get(i,j));
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    if(answer.empty()){
        return {-1};
    }
    return answer;
}