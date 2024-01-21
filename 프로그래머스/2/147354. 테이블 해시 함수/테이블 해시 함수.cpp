#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int col;
bool compare(vector<int>& v1, vector<int>& v2){
    if(v1[col-1]==v2[col-1]){
        return v1[0]>v2[0];
    }
    return v1[col-1]<v2[col-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    ::col=col;
    sort(data.begin(),data.end(),compare);
    for(int i=row_begin-1;i<=row_end-1;i++){
        int s = 0;
        for(int j=0;j<data[i].size();j++){
            s+=data[i][j]%(i+1);
        }
        printf("%d\n", s);
        answer^=s;
    }
    return answer;
}