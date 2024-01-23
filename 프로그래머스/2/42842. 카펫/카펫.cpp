#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=2;i<=1000000;i++){
        int w=i;
        if((brown+yellow)%w!=0){
            continue;
        }
        int h=(brown+yellow)/w;
        if((w-2)*(h-2)==yellow){
            return {max(w,h),min(w,h)};
        }
    }
    return answer;
}