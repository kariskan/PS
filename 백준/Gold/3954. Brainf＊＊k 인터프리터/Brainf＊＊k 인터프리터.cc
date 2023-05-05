#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int sm, sc, si;
int mem[100000] = {0}, idx[5000] = {0};

int ptrPlus(int ptr, int s) { return ptr == s - 1 ? 0 : ptr + 1; }

int ptrMinus(int ptr, int s) { return ptr == 0 ? s - 1 : ptr - 1; }

int main() {
    int n;
    cin >> n;
    while (n--) {
        memset(mem, 0, sizeof(mem));
        memset(idx, 0, sizeof(idx));
        char code[5000] = {0}, inp[5000] = {0};
        cin >> sm >> sc >> si;
        for (int i = 0; i < sc; i++) {
            cin >> code[i];
        }
        for (int i = 0; i < si; i++) {
            cin >> inp[i];
        }

        stack<int> st;
        for (int i = 0; i < sc; i++) {
            if (code[i] != '[' && code[i] != ']') {
                continue;
            }
            if (code[i] == ']') {
                idx[i] = st.top();
                idx[st.top()] = i;
                st.pop();
            } else {
                st.push(i);
            }
        }

        int inpIdx = 0, ptr = 0, codePtr = 0, inpPtr = 0, t = 0;
        int codeMaxPtr, codeMinPtr;
        while (codePtr < sc) {
            if (t == 50000000) {
                codeMaxPtr = codeMinPtr = codePtr;
            }
            if (t >= 100000000) {
                cout << "Loops " << codeMinPtr - 1 << ' ' << codeMaxPtr << '\n';
                break;
            }
            if (code[codePtr] == '-') {
                mem[ptr] = (mem[ptr] + 255) % 256;
            } else if (code[codePtr] == '+') {
                mem[ptr] = (mem[ptr] + 1) % 256;
            } else if (code[codePtr] == '<') {
                ptr = ptrMinus(ptr, sm);
            } else if (code[codePtr] == '>') {
                ptr = ptrPlus(ptr, sm);
            } else if (code[codePtr] == '[') {
                if (mem[ptr] == 0) {
                    codePtr = idx[codePtr];
                }
            } else if (code[codePtr] == ']') {
                if (mem[ptr] != 0) {
                    codePtr = idx[codePtr];
                }
            } else if (code[codePtr] == ',') {
                if (inpPtr >= si) {
                    mem[ptr] = 255;
                } else {
                    mem[ptr] = inp[inpPtr++];
                }
            }
            codePtr++;
            t++;

            if (t > 50000000) {
                codeMaxPtr = max(codeMaxPtr, codePtr);
                codeMinPtr = min(codeMinPtr, codePtr);
            }
        }

        if (codePtr == sc) {
            cout << "Terminates\n";
        }
    }
}
