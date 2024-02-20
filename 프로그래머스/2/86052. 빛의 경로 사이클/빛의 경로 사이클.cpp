#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> grid;
vector<int> answer;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[500][500][4];

int getDir(int dir,char c){
    if(c=='S'){
        return dir;
    }
    if(c=='L'){
        return (dir+3)%4;
    }
    return (dir+1)%4;
}

void go(int i,int j,int dir,int cnt){
    
    vis[i][j][dir]=1;
    int nd=getDir(dir,grid[i][j]);
    int nx=i+dx[nd];
    if(nx<0){
        nx=grid.size()-1;
    }else if(nx>=grid.size()){
        nx=0;
    }
    int ny=j+dy[nd];
    if(ny<0){
        ny=grid[0].size()-1;
    }else if(ny>=grid[0].size()){
        ny=0;
    }
    
    if(vis[nx][ny][nd]){
        answer.push_back(cnt+1);
    }else{
        go(nx,ny,nd,cnt+1);
    }
}

vector<int> solution(vector<string> grid) {
    ::grid=grid;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].length();j++){
            for(int k=0;k<4;k++){
                if(!vis[i][j][k]){
                    go(i,j,k,0);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}