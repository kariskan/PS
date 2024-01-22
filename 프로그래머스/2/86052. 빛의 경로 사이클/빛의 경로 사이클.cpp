#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int vis[4][500][500];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m;
vector<int> answer;
vector<string> grid;

int charToDir(char c, int dir){
    if(c=='S'){
        return dir;
    }
    if(c=='L'){
        return (dir+3)%4;
    }
    return (dir+1)%4;
}

void go(int cnt,int dir,int x,int y){
    int nextDir=charToDir(grid[x][y],dir);
    int nx=x+dx[nextDir];
    if(nx>=n){
        nx=0;
    }else if(nx<0){
        nx=n-1;
    }
    int ny=y+dy[nextDir];
    if(ny>=m){
        ny=0;
    }else if(ny<0){
        ny=m-1;
    }
    
    if(vis[nextDir][nx][ny]){
        answer.push_back(cnt);
    }else{
        vis[nextDir][nx][ny]=1;
        go(cnt+1,nextDir,nx,ny);
    }
}
vector<int> solution(vector<string> grid) {
    ::grid=grid;
    n=grid.size(),m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                if(!vis[k][i][j]){
                    go(0,k,i,j);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}