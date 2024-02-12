#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left=*min_element(stones.begin(),stones.end()),right=*max_element(stones.begin(),stones.end());
    while(left<=right){
        int mid=(left+right)/2;
        
        vector<int> v=stones;
        int seq=0;
        bool flag=true;
        for(int i=0;i<v.size();i++){
            v[i]-=mid;
            if(v[i]<0){
                seq++;
            }else{
                seq=0;
            }
            if(seq>=k){
                flag=false;
                break;
            }
        }
        
        if(flag){
            answer=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return answer;
}