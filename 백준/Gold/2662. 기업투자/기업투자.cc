#include <iostream>
#include <vector>
using namespace std;

int info[21][301], dp[21][301], p[21][301];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        for(int j=1;j<=m;j++){
            cin>>info[j][i];
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<=j;k++){
                int v = dp[i - 1][j - k] + info[i][k];
                if (dp[i][j] < v) {
                    dp[i][j] = v;
                    p[i][j] = k;
                }
            }
        }
    }
    
    int ans = dp[m][n];
    
    cout << ans << '\n';
    vector<int> seq;
    
    for(int i=m;i>=1;i--) {
        for(int j=0;j<=n;j++){
            if(dp[i][j] == ans) {
                seq.push_back(p[i][j]);
                ans -= info[i][p[i][j]];
            }
        }
    }
    
    for(int i=seq.size() - 1; i >= 0; i--) {
        cout << seq[i] << ' ';
    }
}
