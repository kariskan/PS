#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    int mi = -1, idx = 0;
    for(int i=0;i<arr.size();i++){
        if(mi==-1||mi>arr[i]){
            mi=arr[i];
            idx=i;
        }
    }
    arr.erase(arr.begin() + idx);
    if(arr.empty()) arr.push_back(-1);
    return arr;
}