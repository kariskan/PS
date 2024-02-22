#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int totalDelivery=0,totalPickup=0,lastDeliveryIdx=-1,lastPickupIdx=-1;
    for(int i=0;i<n;i++){
        totalDelivery+=deliveries[i];
        totalPickup+=pickups[i];
        if(deliveries[i]){
            lastDeliveryIdx=i;
        }
        if(pickups[i]){
            lastPickupIdx=i;
        }
    }

    while(lastDeliveryIdx!=-1||lastPickupIdx!=-1){
        int pickupCnt=0,deliveryCnt=0;
        if(lastDeliveryIdx>=lastPickupIdx){
            answer+=(lastDeliveryIdx+1)*2;
            while(deliveryCnt<cap&&lastDeliveryIdx>=0){
                int diff=min(deliveries[lastDeliveryIdx], cap-deliveryCnt);
                deliveryCnt+=diff;
                deliveries[lastDeliveryIdx]-=diff;
                if(deliveries[lastDeliveryIdx]==0){
                    lastDeliveryIdx--;
                }
            }
            int tempCnt=cap;
            for(int i=lastPickupIdx;i>=0;i--){
                int diff=min(tempCnt, pickups[i]);
                tempCnt-=diff;
                pickups[i]-=diff;
                if(tempCnt==0){
                    break;
                }
            }
            // printf("1 %d %d %d\n", answer, lastDeliveryIdx, lastPickupIdx);
        }else{
            answer+=(lastPickupIdx+1)*2;
            while(pickupCnt<cap&&lastPickupIdx>=0){
                int diff=min(pickups[lastPickupIdx], cap-pickupCnt);
                pickupCnt+=diff;
                pickups[lastPickupIdx]-=diff;
                if(pickups[lastPickupIdx]==0){
                    lastPickupIdx--;
                }
            }
            int tempCnt=cap;
            for(int i=lastDeliveryIdx;i>=0;i--){
                int diff=min(tempCnt, deliveries[i]);
                tempCnt-=diff;
                deliveries[i]-=diff;
                if(tempCnt==0){
                    if(deliveries[i]==0){
                        lastDeliveryIdx=i-1;
                    }else{
                        lastDeliveryIdx=i;
                    }
                    break;
                }
                if(i==0){
                    lastDeliveryIdx=-1;
                }
            }
            // printf("1 %d %d %d\n", answer, lastDeliveryIdx, lastPickupIdx);
        }
        while(lastPickupIdx>=0&&!pickups[lastPickupIdx]){
            lastPickupIdx--;
        }
        while(lastDeliveryIdx>=0&&!deliveries[lastDeliveryIdx]){
            lastDeliveryIdx--;
        }
    }

    return answer;
}