#include <stdio.h>
#include <stdlib.h>
   

char gagnant(char a, char b) {
    if (a == b) {
        return a;
    }
    if ((a == 'P' && b == 'C') || (a == 'C' && b == 'F') || (a == 'F' && b == 'P')) {
        return a;
    }
    return b;
}

int main() {
    char S[1024];
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0';
    char cur = S[0];
    for (int i = 0; i < strlen(S); i++) {
        cur = gagnant(cur, S[i]);
    }
    printf("%c\n", cur);
    return 0;
}

