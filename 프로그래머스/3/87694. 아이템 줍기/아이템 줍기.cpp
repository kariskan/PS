#include <string>
#include <vector>
#include <queue>

using namespace std;
int vis[101][101],map[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(int i=0;i<rectangle.size();i++){
        rectangle[i][0]*=2;
        rectangle[i][1]*=2;
        rectangle[i][2]*=2;
        rectangle[i][3]*=2;
    }
    for(int r1=0;r1<rectangle.size();r1++){
        for(int i=rectangle[r1][0];i<=rectangle[r1][2];i++){
            for(int j=rectangle[r1][1];j<=rectangle[r1][3];j++){
                int flag=1;
                if(i==rectangle[r1][0]||i==rectangle[r1][2]||j==rectangle[r1][1]||j==rectangle[r1][3]){
                    for(int r2=0;r2<rectangle.size();r2++){
                        if(r1==r2){
                            continue;
                        }

                        if(i>rectangle[r2][0]&&i<rectangle[r2][2]&&j>rectangle[r2][1]&&j<rectangle[r2][3]){
                            flag=0;
                            break;
                        }
                    }
                    if(flag){
                        map[i][j]=1;
                    }
                }
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({characterX*2,characterY*2});
    vis[characterX*2][characterY*2]=1;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==itemX*2&&y==itemY*2){
            return (vis[x][y] - 1)/2;
        }
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0&&nx<=100&&ny>=0&&ny<=100&&map[nx][ny]&&!vis[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny]=vis[x][y]+1;
            }
        }
    }
}