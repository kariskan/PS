#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> v={k};
    while(k!=1){
        if(k%2==1){
            k=k*3+1;
        }else{
            k/=2;
        }
        v.push_back(k);
    }
    vector<double> width={0};
    for(int i=1;i<v.size();i++){
        width.push_back(((double)v[i]+v[i-1])/2);
        if(i>1){
            width[i]+=width[i-1];
        }
    }
    for(int i=0;i<ranges.size();i++){
        int start=ranges[i][0];
        int end=width.size()+ranges[i][1]-1;
        if(start>end){
            answer.push_back(-1);
        }else{
            answer.push_back(width[end]-width[start]);
        }
    }
    return answer;
}