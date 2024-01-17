#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int mi=1000000000,idx=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<mi){
            mi=arr[i];
            idx=i;
        }
    }
    arr.erase(arr.begin()+idx);
    if(arr.empty()){
        return{-1};
    }
    return arr;
}