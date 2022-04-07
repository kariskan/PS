#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<double, int>& a, const pair<double, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> arr(N);
    for (int i : stages) {
        if (i == N + 1)continue;
        else arr[i - 1]++;
    }
    vector<pair<double, int>> v(N);
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            v[i] = { arr[i] / (double)stages.size(),i };
        }
        else {
            if (stages.size() - sum == 0)v[i] = { 0,i };
            else v[i] = { arr[i] / (double)(stages.size() - sum),i };
        }
        sum += arr[i];
    }
    sort(v.begin(), v.end(), compare);
    for (const pair<double, int>& p : v) {
        answer.push_back(p.second + 1);
    }
    return answer;
}