#include <iostream>
using namespace std;

int a[11][10], n;
string ans;

void go(int i) {
    
    int cnt = 0;
    for(int k=0;k<10;k++){
        if(cnt + a[i][k] >= n) {
            n -= cnt;
            ans += (k + '0');
            go(i-1);
            break;
        }
        cnt += a[i][k];
    }
}

int main(){
    for(int i=0;i<10;i++){
        a[1][i] = 1;
    }
    
    for(int i=2;i<=10;i++){
        for(int j=1;j<=9;j++){
            for(int k=0;k<j;k++){
                a[i][j] += a[i-1][k];
            }
        }
    }
    
    cin >> n;
    int cnt = 0;
    
    for(int i=1;i<=10;i++){
        for(int j=0;j<=9;j++){
            if(cnt + a[i][j] >= n) {
                ans += (j + '0');
                n -= cnt;
                go(i - 1);
                cout<<ans;
                return 0;
            }
            cnt += a[i][j];
        }
    }
    
    cout<<-1;
    
    return 0;
}
