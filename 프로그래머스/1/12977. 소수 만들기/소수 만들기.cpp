#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                int a = nums[i]+nums[j]+nums[k];
                bool flag=true;
                for(int i1=2;i1*i1<=a;i1++){
                    if(a%i1==0){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    answer++;
                }
            }
        }
    }

    return answer;
}