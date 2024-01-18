#include <vector>
using namespace std;
int vis[200001];
int solution(vector<int> nums)
{
    int answer = 0;
    for(int i=0;i<nums.size();i++){
        if(!vis[nums[i]]){
            vis[nums[i]]=1;
            answer++;
            if(answer==nums.size()/2){
                return answer;
            }
        }
    }
    return answer;
}