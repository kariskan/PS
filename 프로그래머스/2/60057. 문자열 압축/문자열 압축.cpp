#include <string>
#include <vector>

using namespace std;
int len(int n){
    if(n<=1){
        return 0;
    }
    int res=0;
    while(n){
        res++;
        n/=10;
    }
    return res;
}
int solution(string s) {
    int answer = 100000;
    for(int cnt=1;cnt<=s.length();cnt++){
        int t=0;
        for(int i=0;i<s.length();i++){
            if(s.length()-i<cnt){
                t+=s.length()-i;
                break;
            }
            string base=s.substr(i,cnt);
            int idx=i;
            while(idx<s.length()-cnt+1&&s.substr(idx,cnt)==base){
                idx+=cnt;
            }
            t+=len((idx-i)/cnt)+cnt;
            i=idx-1;
        }
        if(answer>t){
            answer=t;
        }
    }
    return answer;
}