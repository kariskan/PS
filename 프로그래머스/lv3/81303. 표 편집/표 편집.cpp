#include <string>
#include <vector>
#include <stack>
using namespace std;
struct Node {
    int num;
    Node* prev;
    Node* next;
};
string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    vector<Node*> v;
    stack<Node*> deleted;
    for (int i = 0; i < n; i++) {
        v.push_back(new Node{ i,nullptr,nullptr });
    }
    v[0]->next = v[1];
    v[n - 1]->prev = v[n - 2];
    for (int i = 1; i < n - 1; i++) {
        v[i]->prev = v[i - 1];
        v[i]->next = v[i + 1];
    }

    Node* nowIdx = v[k];

    for (string s : cmd) {
        if (s[0] == 'U' || s[0] == 'D') {
            int x = stoi(s.substr(2));
            if (s[0] == 'U') {
                while (x--)nowIdx = nowIdx->prev;
            }
            else {
                while (x--)nowIdx = nowIdx->next;
            }
        }
        else if (s[0] == 'C') {
            deleted.push(nowIdx);

            if (nowIdx->prev == nullptr) {
                nowIdx->next->prev = nullptr;
                nowIdx = nowIdx->next;
            }
            else if (nowIdx->next == nullptr) {
                nowIdx->prev->next = nullptr;
                nowIdx = nowIdx->prev;
            }
            else {
                nowIdx->prev->next = nowIdx->next;
                nowIdx->next->prev = nowIdx->prev;
                nowIdx = nowIdx->next;
            }
        }
        else {
            Node* top = deleted.top();
            deleted.pop();

            if (top->prev != nullptr)top->prev->next = top;
            if (top->next != nullptr)top->next->prev = top;
        }
    }

    while (nowIdx->prev != nullptr)nowIdx = nowIdx->prev;
    while (nowIdx != nullptr) {
        answer[nowIdx->num] = 'O';
        nowIdx = nowIdx->next;
    }

    return answer;
}