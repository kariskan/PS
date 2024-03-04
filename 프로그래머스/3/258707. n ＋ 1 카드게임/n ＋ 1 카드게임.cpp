#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> mine,discard;
int solution(int coin, vector<int> cards) {
    int answer = 0;
    for(int i=0;i<cards.size()/3;i++){
        mine.insert(cards[i]);
    }
    
    for(int i=cards.size()/3;i<cards.size();i+=2){
        discard.insert(cards[i]);
        discard.insert(cards[i+1]);
        bool flag=false;
        for(auto&j:mine){
            for(auto&k:mine){
                if(j==k){
                    continue;
                }
                if(j+k==cards.size()+1){
                    mine.erase(j);
                    mine.erase(k);
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            if(coin>0){
                for(auto&j:mine){
                    if(discard.find(cards.size()+1-j)!=discard.end()){
                        coin--;
                        discard.erase(cards.size()+1-j);
                        flag=true;
                        break;
                    }
                }
            }
            if(!flag){
                if(coin>=2){
                    for(auto&j:discard){
                        for(auto&k:discard){
                            if(j==k){
                                continue;
                            }
                            if(j+k==cards.size()+1){
                                coin-=2;
                                discard.erase(j);
                                discard.erase(k);
                                flag=true;
                                break;
                            }
                        }
                        if(flag){
                            break;
                        }
                    }
                }
            }
        }
        printf("%d %d", i, coin);
        if(!flag){
            return (i-cards.size()/3)/2+1;
        }
    }
    return (cards.size()-cards.size()/3)/2+1;
}