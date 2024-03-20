#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> idMap;
map<int,int> totalSell;
int p[10001];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    for(int i=0;i<enroll.size();i++){
        idMap[enroll[i]]=i;
    }
    for(int i=0;i<enroll.size();i++){
        if(referral[i]=="-"){
            p[i]=-1;
        }else{
            p[i]=idMap[referral[i]];
        }
    }
    for(int i=0;i<seller.size();i++){
        totalSell[idMap[seller[i]]]+=amount[i]*100;
    }
    for(int i=0;i<amount.size();i++){
        int id=idMap[seller[i]];
        int sellCount=amount[i]*100;
        while(id!=-1){
            int benefit=sellCount/10;
            answer[id]+=sellCount-benefit;
            id=p[id];
            sellCount=benefit;
            if(benefit==0){
                break;
            }
        }
    }
    
    return answer;
}