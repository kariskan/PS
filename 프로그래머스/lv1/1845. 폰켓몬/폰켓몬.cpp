#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for(int n:nums) {
        if(s.find(n)==s.end()){
            s.insert(n);
        }
    }
    return min(nums.size()/2,s.size());
}