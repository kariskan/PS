#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0;i<photo.size();i++){
        int sum = 0;
        for(int j=0;j<photo[i].size();j++){
            int t = 0;
            string p = photo[i][j];
            for(int k=0;k<name.size();k++){
                if(name[k]==p){
                    t=yearning[k];
                    break;
                }
            }
            sum += t;
        }
        answer.push_back(sum);
    }
    return answer;
}