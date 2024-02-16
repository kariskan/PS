#include <string>
#include <vector>
#include <queue>
using namespace std;
int vis[101][101][2];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n;
vector<vector<int>> board;
queue<pair<pair<int,int>,int>> q;
bool range(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n&&!board[x][y];
}
vector<pair<pair<int,int>,int>> rotate(int x, int y, int dir){
    vector<pair<pair<int,int>,int>> v;
    if(dir==0){
        if(range(x+1,y)&&range(x+1,y+1)){
            v.push_back({{x,y},1});
            v.push_back({{x,y+1},1});
        }
        if(range(x-1,y)&&range(x-1,y+1)){
            v.push_back({{x-1,y},1});
            v.push_back({{x-1,y+1},1});
        }
    }else{
        if(range(x,y+1)&&range(x+1,y+1)){
            v.push_back({{x,y},0});
            v.push_back({{x+1,y},0});
        }
        if(range(x,y-1)&&range(x+1,y-1)){
            v.push_back({{x,y-1},0});
            v.push_back({{x+1,y-1},0});
        }
    }
    return v;
}
int solution(vector<vector<int>> board) {
    ::board=board;
    n=board.size();
    vis[0][0][0]=1;
    q.push({{0,0},0});
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int dir=q.front().second;
        q.pop();

        if((x==n-1&&y==n-1)||(x+dx[dir]==n-1&&y+dy[dir]==n-1)){
            return vis[x][y][dir]-1;
        }

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(range(nx,ny)&&range(nx+dx[dir],ny+dy[dir])&&!vis[nx][ny][dir]){
                q.push({{nx,ny},dir});
                vis[nx][ny][dir]=vis[x][y][dir]+1;
            }
        }
        vector<pair<pair<int,int>,int>> v=rotate(x,y,dir);
        for(pair<pair<int,int>,int> p:v){
            int nx=p.first.first;
            int ny=p.first.second;
            int nd=p.second;
            if(range(nx,ny)&&range(nx+dx[nd],ny+dy[nd])&&!vis[nx][ny][nd]){
                vis[nx][ny][nd]=vis[x][y][dir]+1;
                q.push({{nx,ny},nd});
            }
        }
    }
    return -1;
}

int main(){
    solution({{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}});
}