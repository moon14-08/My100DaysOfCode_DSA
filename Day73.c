#include <stdio.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    // Step 1: frequency count
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[1000];

    // input
    scanf("%s", s);

    char result = firstNonRepeating(s);

    // output
    printf("%c\n", result);

    return 0;
}