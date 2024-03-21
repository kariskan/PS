#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left=1,right=200000000;
    while(left<=right){
        int mid=(left+right)/2;
        
        int cnt=0;
        bool flag=true;
        for(int i=0;i<stones.size();i++){
            if(stones[i]-mid<0){
                cnt++;
            }else{
                cnt=0;
            }
            if(cnt>=k){
                flag=false;
                break;
            }
        }
        
        if(flag){
            left=mid+1;
            answer=mid;
        }else{
            right=mid-1;
        }
    }
    return answer;
}