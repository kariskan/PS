#include <stdio.h>

int main() {
    char s[10001];
    fgets(s, sizeof(s), stdin);

    int idx = 0;
    while (s[idx] != '\n') {
        if ((s[idx] == 'd' || s[idx] == 'D') && s[idx + 1] == '2') {
            printf("D2");
            return 0;
        }
        idx++;
    }

    printf("unrated");
    return 0;
}
