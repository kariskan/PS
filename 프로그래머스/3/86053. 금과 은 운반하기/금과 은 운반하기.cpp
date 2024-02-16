#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 0;
    long long left=1,right=4*10e14;
    while(left<=right){
        long long mid=(left+right)/2;
        
        long long total=0,totalG=0,totalS=0;
        for(int i=0;i<g.size();i++){
            long long cnt=mid/(2*t[i]);
            if(mid-cnt*2*t[i]>=t[i]){
                cnt++;
            }
            
            total+=min(cnt*w[i],(long long)g[i]+s[i]);
            totalG+=min((long long)g[i],cnt*w[i]);
            totalS+=min((long long)s[i],cnt*w[i]);
        }
        if(total>=a+b&&totalG>=a&&totalS>=b){
            right=mid-1;
            answer=mid;
        }else{
            left=mid+1;
        }
    }
    return answer;
}