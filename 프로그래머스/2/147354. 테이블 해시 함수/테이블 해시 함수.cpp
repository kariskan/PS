#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int col;
bool compare(vector<int>& v1,vector<int>& v2){
    if(v1[col]==v2[col]){
        return v1[0]>v2[0];
    }
    return v1[col]<v2[col];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    ::col=col-1;
    sort(data.begin(),data.end(),compare);
    int answer=0;
    for(int i=row_begin-1;i<=row_end-1;i++){
        int s=0;
        for(int j=0;j<data[i].size();j++){
            s+=data[i][j]%(i+1);
        }
        answer^=s;
    }
    return answer;
}