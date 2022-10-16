#include <iostream>
#include <cmath>
using namespace std;

int n,m,map[10][10];
int ans = -1;
int dx[4] = {0,1,-1};
int dy[4] = {1,-1,0};

bool is(int a) {
    int k = sqrt(a);
    return (k * k) == a;
}

bool range(int x, int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}

void go(int i, int j, int x, int y, int d1, int d2, int sum) {
    
    if(!range(i,j)) return;
    
    sum = sum * 10 + map[i][j];
    
    if(is(sum) && ans < sum) {
        ans = sum;
    }
    
    go(i + x*d1, j + y*d2, x, y, d1, d2,sum);
}

int main() {
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<3;k++){
                for(int i1=1;i1<10;i1++){
                    for(int l=0;l<3;l++){
                        if(dx[k]==0&&dy[l]==0)continue;
                        for(int i2=1;i2<10;i2++){
                            go(i,j,dx[k],dy[l],i1,i2,0);
                        }
                    }
                }
            }
        }
    }
    
    cout<<ans;
}
