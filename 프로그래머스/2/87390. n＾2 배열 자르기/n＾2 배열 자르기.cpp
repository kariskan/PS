#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left;i<=right;i++){
        int x=i/n,y=i%n;
        answer.push_back(max(x,y)+1);
    }
    return answer;
}