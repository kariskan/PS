#include <string>
#include <vector>
#include <set>
using namespace std;
set<long long> dp[9];
int solution(int N, int number) {
    long long n=N;
    if(n==number){
        return 1;
    }
    dp[1]={n};
    for(int i=2;i<=8;i++){
        long long a=0;
        for(int j=0;j<i;j++){
            a=a*10+n;
        }
        dp[i].insert(a);
        for(int j=1;j<i;j++){
            for(auto&k:dp[j]){
                for(auto&l:dp[i-j]){
                    dp[i].insert(k+l);
                    dp[i].insert(k-l);
                    dp[i].insert(l-k);
                    dp[i].insert(k*l);
                    if(l){
                        dp[i].insert(k/l);
                    }
                    if(k){
                        dp[i].insert(l/k);
                    }
                }
            }
        }
        for(auto&j:dp[i]){
            // printf("%d ",j);
            if(j==number){
                return i;
            }
        }
        // printf("\n");
    }
    return -1;
}