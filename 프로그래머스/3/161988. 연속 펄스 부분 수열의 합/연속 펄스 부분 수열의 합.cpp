#include <string>
#include <vector>
#include <climits>
using namespace std;

long long solution(vector<int> sequence) {
    vector<long long> v;
    long long answer = 0,mi=0,ma=0;
    for(int i=0;i<sequence.size();i++){
        if(i%2==1){
            sequence[i]*=-1;
        }
        v.push_back(sequence[i]);
        if(i>0){
            v[i]+=v[i-1];
        }
    }
    for(int i=0;i<v.size();i++){
        answer=max(answer,max(abs(v[i]-mi),abs(v[i]-ma)));
        mi=min(mi,v[i]);
        ma=max(ma,v[i]);
    }
    return answer;
}