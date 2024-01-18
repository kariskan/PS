#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare1(vector<int>& v1, vector<int>&v2) {
    return v1[0]<v2[0];
}
bool compare2(vector<int>& v1, vector<int>&v2) {
    return v1[1]<v2[1];
}
bool compare3(vector<int>& v1, vector<int>&v2) {
    return v1[2]<v2[2];
}
bool compare4(vector<int>& v1, vector<int>&v2) {
    return v1[3]<v2[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    if(ext=="code"){
        for(int i=0;i<data.size();i++){
            if(data[i][0]<val_ext){
                answer.push_back(data[i]);
            }
        }
    }else if(ext=="date"){
        for(int i=0;i<data.size();i++){
            if(data[i][1]<val_ext){
                answer.push_back(data[i]);
            }
        }
    }else if(ext=="maximum"){
        for(int i=0;i<data.size();i++){
            if(data[i][2]<val_ext){
                answer.push_back(data[i]);
            }
        }
    }else{
        for(int i=0;i<data.size();i++){
            if(data[i][3]<val_ext){
                answer.push_back(data[i]);
            }
        }
    }
    if(sort_by=="code"){
        sort(answer.begin(), answer.end(), compare1);
    }else if(sort_by=="date"){
        sort(answer.begin(), answer.end(), compare2);
    }else if(sort_by=="maximum"){
        sort(answer.begin(), answer.end(), compare3);
    }else{
        sort(answer.begin(), answer.end(), compare4);
    }
    return answer;
}