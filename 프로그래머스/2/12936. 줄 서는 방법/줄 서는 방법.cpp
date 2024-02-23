#include <string>
#include <vector>

using namespace std;
long long p(int n){
    long long res=1;
    for(int i=2;i<=n;i++){
        res*=i;
    }
    return res;
}
int vis[21];
vector<int> solution(int n, long long k) {
    vector<int> answer;
    for(int i=1;i<=n;i++){
        long long a=(k+p(n-i)-1)/p(n-i);
        int c=0;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                continue;
            }
            c++;
            if(c==a){
                vis[i]=1;
                answer.push_back(i);
                break;
            }
        }
        k-=(a-1)*p(n-i);
    }
    return answer;
}