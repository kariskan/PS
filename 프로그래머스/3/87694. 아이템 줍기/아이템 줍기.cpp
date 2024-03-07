#include <string>
#include <vector>
#include <queue>
using namespace std;
int map[101][101],vis[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool isValid(int x,int y,int x1,int y1,int x2,int y2){
    return !(x>x1&&x<x2&&y>y1&&y<y2);
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(int i=0;i<rectangle.size();i++){
        for(int j=0;j<4;j++){
            rectangle[i][j]*=2;
        }
    }
    int mx=0,my=0;
    for(int i=0;i<rectangle.size();i++){
        for(int i1=rectangle[i][0];i1<=rectangle[i][2];i1++){
            for(int j1=rectangle[i][1];j1<=rectangle[i][3];j1++){
                if(i1==rectangle[i][0]||i1==rectangle[i][2]||j1==rectangle[i][1]||j1==rectangle[i][3]){
                    bool flag=true;
                    for(int j=0;j<rectangle.size();j++){
                        if(i==j){
                            continue;
                        }
                        vector<int> rec=rectangle[j];
                        if(!isValid(i1,j1,rec[0],rec[1],rec[2],rec[3])){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        map[i1][j1]=1;
                        mx=max(mx,i1);
                        my=max(my,j1);
                    }
                }
            }
        }
    }
    queue<pair<int,int>> q;
    vis[characterX*2][characterY*2]=1;
    q.push({characterX*2,characterY*2});
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        if(x==itemX*2&&y==itemY*2){
            return (vis[x][y]-1)/2;
        }
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<=100&ny>=0&&ny<=100&&!vis[nx][ny]&&map[nx][ny]){
                vis[nx][ny]=vis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return 0;
}