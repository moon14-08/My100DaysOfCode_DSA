#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int visited[26] = {0};

    for (int i = 0; i < strlen(s); i++) {
        if (visited[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
        visited[s[i] - 'a'] = 1;
    }

    printf("-1");
    return 0;
}