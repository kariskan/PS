#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> mine,discard;  
int solution(int coin, vector<int> cards) {
    int n=cards.size();
    for(int i=0;i<n/3;i++){
        mine.insert(cards[i]);
    }
    for(int i=cards.size()/3;i<n;i+=2){
        // printf("%d %d\n",i, coin);
        int flag=0;
        discard.insert(cards[i]);
        discard.insert(cards[i+1]);
        // for(auto&j:mine){
        //     printf("%d ",j);
        // }
        // printf("\n");
        // for(auto&j:discard){
        //     printf("%d ",j);
        // }
        // printf("\n\n");
        for(auto&j:mine){
            for(auto&k:mine){
                if(j==k){
                    continue;
                }
                if(j+k==n+1){
                    mine.erase(j);
                    mine.erase(k);
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            if(coin==0){
                return (i-n/3)/2+1;
            }
            int flag=0;
            for(auto&j:discard){
                if(mine.find(n+1-j)!=mine.end()){
                    mine.erase(n+1-j);
                    discard.erase(j);
                    flag=1;
                    coin--;
                    break;
                }
            }
            if(flag==0){
                if(coin<2){
                    return (i-n/3)/2+1;
                }
                for(auto&j:discard){
                    for(auto&k:discard){
                        if(j==k){
                            continue;
                        }
                        if(j+k==n+1){
                            discard.erase(j);
                            discard.erase(k);
                            flag=1;
                            coin-=2;
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                if(!flag){
                    return (i-n/3)/2+1;
                }
            }
        }
    }
    return (n-n/3)/2+1;
}