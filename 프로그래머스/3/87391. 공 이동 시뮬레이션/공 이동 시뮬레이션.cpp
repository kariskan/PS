#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
typedef long long ll;
int reverseDir(int dir){
    if(dir==0){
        return 1;
    }
    if(dir==1){
        return 0;
    }
    if(dir==3){
        return 2;
    }
    return 3;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    ll x1=x,y1=y,x2=x,y2=y;
    for(int i=queries.size()-1;i>=0;i--){
        int dir=queries[i][0];
        ll dis=queries[i][1];
        
        if(dir==0){
            if(y1!=0){
                y1+=dis;
            }
            y2=min((ll)m-1,y2+dis);
        }else if(dir==1){
            if(y2!=m-1){
                y2-=dis;
            }
            y1=max((ll)0,y1-dis);
        }else if(dir==2){
            if(x1!=0){
                x1+=dis;
            }
            x2=min((ll)n-1,x2+dis);
        }else{
            if(x2!=n-1){
                x2-=dis;
            }
            x1=max((ll)0,x1-dis);
        }
        // printf("%d %d %d %d\n", x1,y1,x2,y2);
        if(!(x1<n&&x2>=0&&y1<m&&y2>=0)){
            return 0;
        }
    }
    return (x2-x1+1)*(y2-y1+1);
}