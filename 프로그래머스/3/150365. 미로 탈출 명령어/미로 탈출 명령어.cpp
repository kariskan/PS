#include <string>
#include <vector>

using namespace std;
// d l r u
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
char d[4]={'d','l','r','u'};
int getDis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    if(getDis(x,y,r,c)>k||getDis(x,y,r,c)%2!=k%2){
        return "impossible";
    }
    string answer="";
    for(int t=0;t<k;t++){
        if(k-t==getDis(x,y,r,c)){
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
                    if(getDis(x,y,r,c)>getDis(nx,ny,r,c)){
                        if(i==0||i==3){
                            for(int j=0;j<abs(x-r);j++){
                                answer+=d[i];
                            }
                        }else{
                            for(int j=0;j<abs(y-c);j++){
                                answer+=d[i];
                            }
                        }
                    }
                }
            }
            break;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
                answer+=d[i];
                x=nx;
                y=ny;
                break;
            }
        }
    }
    return answer;
}