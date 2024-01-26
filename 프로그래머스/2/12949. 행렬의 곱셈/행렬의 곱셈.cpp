#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n=arr1.size(),m=arr1[0].size(),l=arr2[0].size();
    vector<vector<int>> answer(n,vector<int>(l));
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            int sum=0;
            for(int k=0;k<m;k++){
                sum+=arr1[i][k]*arr2[k][j];
            }
            answer[i][j]=sum;
        }
    }
    return answer;
}