#include <string>
#include <vector>

using namespace std;
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
char ch[4]={'d','l','r','u'};
int getDis(int x,int y,int targetX,int targetY){
    return abs(x-targetX)+abs(y-targetY);
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    if(k<getDis(x,y,r,c)||(k-getDis(x,y,r,c))%2==1){
        return "impossible";
    }
    string answer = "";
    for(int i=k;i>0;i--){
        for(int j=0;j<4;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&getDis(nx,ny,r,c)<=i-1){
                x=nx;
                y=ny;
                answer+=ch[j];
                break;
            }
        }
    }
    return answer;
}