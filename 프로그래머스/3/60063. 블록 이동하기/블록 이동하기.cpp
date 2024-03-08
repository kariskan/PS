#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[100][100][2],n;
vector<vector<int>> board;
bool isValidRange(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n&&!board[x][y];
}
pair<int,int> getConnectedCoor(int x,int y,int dir){
    if(dir==0){
        return {x,y+1};
    }
    return {x+1,y};
}
int solution(vector<vector<int>> board) {
    ::board=board;
    n=board.size();
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    vis[0][0][0]=1;
    
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int dir=q.front().second;
        q.pop();
        
        if((x==n-1&&y==n-2&&dir==0)||(x==n-2&&y==n-1&&dir==1)){
            return vis[x][y][dir]-1;
        }
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            pair<int,int> nnc=getConnectedCoor(nx,ny,dir);
            if(isValidRange(nx,ny)&&isValidRange(nnc.first,nnc.second)
              &&!vis[nx][ny][dir]){
                q.push({{nx,ny},dir});
                vis[nx][ny][dir]=vis[x][y][dir]+1;
            }
        }
        
        // 수평에서 수직으로 회전
        if(dir==0){
            if(isValidRange(x+1,y)&&isValidRange(x+1,y+1)){
                if(!vis[x][y][1-dir]){
                    vis[x][y][1-dir]=vis[x][y][dir]+1;
                    q.push({{x,y},1-dir});
                }
                if(!vis[x][y+1][1-dir]){
                    vis[x][y+1][1-dir]=vis[x][y][dir]+1;
                    q.push({{x,y+1},1-dir});
                }
            }
            if(isValidRange(x-1,y)&&isValidRange(x-1,y+1)){
                if(!vis[x-1][y][1-dir]){
                    vis[x-1][y][1-dir]=vis[x][y][dir]+1;
                    q.push({{x-1,y},1-dir});
                }
                if(!vis[x-1][y+1][1-dir]){
                    vis[x-1][y+1][1-dir]=vis[x][y][dir]+1;
                    q.push({{x-1,y+1},1-dir});
                }
            }
        }else {
            // 수직에서 수평으로 회전
            if(isValidRange(x,y+1)&&isValidRange(x+1,y+1)){
                if(!vis[x][y][1-dir]){
                    vis[x][y][1-dir]=vis[x][y][dir]+1;
                    q.push({{x,y,},1-dir});
                }
                if(!vis[x+1][y][1-dir]){
                    vis[x+1][y][1-dir]=vis[x][y][dir]+1;
                    q.push({{x+1,y},1-dir});
                }
            }
            if(isValidRange(x,y-1)&&isValidRange(x+1,y-1)){
                if(!vis[x][y-1][1-dir]){
                    vis[x][y-1][1-dir]=vis[x][y][dir]+1;
                    q.push({{x,y-1},1-dir});
                }
                if(!vis[x+1][y-1][1-dir]){
                    vis[x+1][y-1][1-dir]=vis[x][y][dir]+1;
                    q.push({{x+1,y-1},1-dir});
                }
            }
        }
    }
}