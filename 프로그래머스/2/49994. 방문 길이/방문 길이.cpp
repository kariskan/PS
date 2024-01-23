#include <string>
#include <map>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[4][11][11];
map<char,int> dirMap={
    {'R',0},
    {'D',1},
    {'L',2},
    {'U',3}
};
int solution(string dirs) {
    int answer = 0;
    int x=5,y=5;
    for(int i=0;i<dirs.length();i++){
        printf("%d %d\n", x,y);
        int dir=dirMap[dirs[i]];
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(nx>=0&&nx<=10&&ny>=0&&ny<=10){
            if(!vis[dir][nx][ny]&&!vis[(dir+2)%4][x][y]){
                vis[dir][nx][ny]=vis[(dir+2)%4][x][y]=1;
                answer++;
            }
            x=nx;
            y=ny;
        }
    }
    return answer;
}