#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[5000001], b[5000001];

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    for(int i=1;i<=e;i++){
        for(int j=i;j<=e;j+=i){
            a[j]++;
        }
    }
    int ma=0,mi;
    for(int i=e;i>=1;i--){
        if(ma<=a[i]){
            ma=a[i];
            mi=i;
        }
        b[i]=mi;
    }
    for(int i=0;i<starts.size();i++){
        answer.push_back(b[starts[i]]);
    }
    return answer;
}