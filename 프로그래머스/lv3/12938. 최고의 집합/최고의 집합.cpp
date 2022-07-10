#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s<n)return {-1};
    int div = s/n;
    int mod = s%n;
    while(n--) {
        int t = div + (mod>0?1:0);
        answer.push_back(t);
        mod--;
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}