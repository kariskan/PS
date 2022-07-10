#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int idx = 0; //B의 idx
    for(int i=0;i<A.size();i++){
        while(idx < B.size()) {
            if(B[idx] > A[i]) {
                idx++;
                answer++;
                break;
            }
            idx++;
        }
    }
    return answer;
}