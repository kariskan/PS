#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int lastIdx=n-1;
    while(1){
        int idx=0;
        int flag=0;
        for(int i=lastIdx;i>=0;i--){
            if(deliveries[i]||pickups[i]){
                flag=1;
                idx=i;
                int cnt=cap;
                answer+=(i+1)*2;
                while(idx>=0&&cnt){
                    int mi=min(cnt,deliveries[idx]);
                    cnt-=mi;
                    lastIdx=idx;
                    deliveries[idx--]-=mi;
                }
                idx=i;
                cnt=cap;
                int li=i;
                while(idx>=0&&cnt){
                    int mi=min(cnt,pickups[idx]);
                    cnt-=mi;
                    li=idx;
                    pickups[idx--]-=mi;
                }
                lastIdx=max(lastIdx,li);
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    return answer;
}