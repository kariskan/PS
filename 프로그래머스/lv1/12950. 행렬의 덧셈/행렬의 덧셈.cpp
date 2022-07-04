#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int siz = arr1.size();
    vector<vector<int>> answer(siz, vector<int>(arr1[0].size()));
    for(int i=0;i<siz;i++){
        for(int j=0;j<arr1[0].size();j++){
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}