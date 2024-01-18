#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int attackIdx = 0;
    int now=health,seq=0;
    for(int i=1;i<=attacks[attacks.size()-1][0];i++){
        if(i==attacks[attackIdx][0]){
            seq=0;
            now-=attacks[attackIdx][1];
            if(now<=0){
                return -1;
            }
            attackIdx++;
        }else{
            now=min(health,now+bandage[1]);
            seq++;
            if(seq==bandage[0]){
                seq=0;
                now=min(health,now+bandage[2]);
            }
        }
    }
    return now;
}