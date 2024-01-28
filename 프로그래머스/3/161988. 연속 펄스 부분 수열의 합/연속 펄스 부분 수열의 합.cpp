#include <string>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
ll sum[500001];
long long solution(vector<int> sequence) {
    ll answer = abs(sequence[0]);
    sum[1]=sequence[0];
    
    ll fmi=0,smi=0;
    for(int i=1;i<=sequence.size();i++){
        sum[i]=(i%2==1?1:-1)*sequence[i-1]+sum[i-1];
        
        answer=max(answer, max(sum[i]-fmi,-sum[i]-smi));
        fmi=min(fmi,sum[i]);
        smi=min(smi,-sum[i]);
    }
    return answer;
}