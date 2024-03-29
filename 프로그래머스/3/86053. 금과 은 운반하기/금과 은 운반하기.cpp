#include <string>
#include <vector>
#include <climits>
using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    
    long long left=0,right=1e14*5;
    while(left<=right){
        long long mid=(left+right)/2;
        long long gSum=0,sSum=0,totalSum=0;
        for(int i=0;i<s.size();i++){
            long long cnt=mid/(t[i]*2);
            if(mid-cnt*t[i]*2>=t[i]){
                cnt++;
            }
            long long gMin=min((long long)g[i],cnt*w[i]);
            long long sMin=min((long long)s[i],cnt*w[i]);
            gSum+=gMin;
            sSum+=sMin;
            totalSum+=min(gMin+sMin,cnt*w[i]);
        }
        
        if(gSum>=a&&sSum>=b&&totalSum>=a+b){
            answer=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    
    return answer;
}