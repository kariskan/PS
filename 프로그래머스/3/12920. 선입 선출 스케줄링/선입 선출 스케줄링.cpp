#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> cores) {
    long long N = n;
    long long left=1,right=n*(*min_element(cores.begin(),cores.end()));
    long long t=1;
    if(N<=cores.size()){
        return N;
    }
    while(left<=right){
        int mid=(left+right)/2;
        
        int cnt=0;
        for(int i=0;i<cores.size();i++){
            cnt+=(mid+cores[i])/cores[i];
        }
        if(cnt>=N){
            t=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    long long sum=0;
    for(int i=0;i<cores.size();i++){
        sum += (t-1+cores[i])/cores[i];
    }
    N-=sum;
    for(int i=0;i<cores.size();i++){
        if(t%cores[i]==0){
            N--;
            if(N==0){
                return i+1;
            }
        }
    }
}