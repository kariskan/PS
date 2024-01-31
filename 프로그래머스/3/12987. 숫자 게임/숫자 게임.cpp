#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int last=0;
    for(int i=0;i<B.size();i++){
        int left=last,right=A.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            
            if(A[mid]>=B[i]){
                left=mid+1;
            }else{
                right=mid-1;
                last=mid;
            }
        }
        if(last>=0&&A[last]<B[i]){
            answer++;
            last++;
        }
    }
    return answer;
}