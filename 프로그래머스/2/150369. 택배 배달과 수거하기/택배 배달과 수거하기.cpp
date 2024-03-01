#include <string>
#include <vector>

using namespace std;

long long traversal(int cap, vector<int>& v, long long idx){
    while(idx>=0&&cap){
        int mi=min(cap,v[idx]);
        cap-=mi;
        v[idx]-=mi;
        
        while(idx>=0&&v[idx]==0){
            idx--;
        }
    }
    return idx;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    long long deliveryIdx=-1,pickupIdx=-1;
    for(int i=0;i<n;i++){
        if(deliveries[i]){
            deliveryIdx=i;
        }
        if(pickups[i]){
            pickupIdx=i;
        }
    }
    while(deliveryIdx!=-1||pickupIdx!=-1){
        answer+=(max(deliveryIdx,pickupIdx)+1)*2;
        
        deliveryIdx=traversal(cap,deliveries,deliveryIdx);
        pickupIdx=traversal(cap,pickups,pickupIdx);
        
    }
    
    return answer;
}