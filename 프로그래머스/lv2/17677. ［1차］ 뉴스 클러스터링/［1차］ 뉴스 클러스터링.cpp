#include <string>
#include <vector>
using namespace std;

vector<string> v1, v2;
int sum() {
    int res = 0;
    vector<string> t1 = v1, t2 = v2;
    if (t1.empty() && t2.empty())return 65536;
    int t1Size = t1.size(), t2Size = t2.size();
    for (int i = 0; i < t1Size; i++) {
        for (int j = 0; j < t2Size; j++) {
            if (t1[i] == t2[j]) {
                res++;
                t1.erase(t1.begin() + i);
                t2.erase(t2.begin() + j);
                i--;
                t1Size--;
                t2Size--;
                break;
            }
        }
    }
    return 65536 * res / (t1.size() + t2.size() + res);
}
int solution(string str1, string str2) {
    int answer = 0;
    for (int i = 0; i < str1.length() - 1; i++) {
        v1.push_back(str1.substr(i, 2));
    }
    for (int i = 0; i < str2.length() - 1; i++) {
        v2.push_back(str2.substr(i, 2));
    }
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (v1[i][j] >= 'A' && v1[i][j] <= 'Z')v1[i][j] += 32;
            if (!(v1[i][j] >= 'a' && v1[i][j] <= 'z')) {
                v1.erase(v1.begin() + i);
                i--;
                break;
            }
        }
    }
    for (int i = 0; i < v2.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (v2[i][j] >= 'A' && v2[i][j] <= 'Z')v2[i][j] += 32;
            if (!(v2[i][j] >= 'a' && v2[i][j] <= 'z')) {
                v2.erase(v2.begin() + i);
                i--;
                break;
            }
        }
    }
    answer = sum();
    return answer;
}