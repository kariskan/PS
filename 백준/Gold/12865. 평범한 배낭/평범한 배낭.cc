#include <iostream>
#include <algorithm>
using namespace std;
int bag[101][100001] = { 0, };
int weight[101] = { 0, };
int value[101] = { 0, };

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            bag[i][j] = bag[i - 1][j];
            if(j >= weight[i]) {
                bag[i][j] = max(bag[i][j], bag[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    
    cout<<bag[n][k];
}