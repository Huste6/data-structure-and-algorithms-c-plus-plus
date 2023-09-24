#include<stdio.h>
#include<string.h>

void replaceString(char *str, const char *old, const char *new) {
    char temp[1000];
    int i, j, k;
    int oldLen = strlen(old);
    int newLen = strlen(new);

    for (i = j = 0; str[i] != '\0'; ) {
        if (strstr(&str[i], old) == &str[i]) {
            strcpy(&temp[j], new);
            j += newLen;
            i += oldLen;
        } else {
            temp[j++] = str[i++];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char p1[1000];
    char p2[1000];
    char t[1000];

    fgets(p1, 1000, stdin);
    fgets(p2, 1000, stdin);
    fgets(t, 1000, stdin);

    p1[strcspn(p1, "\n")] = '\0';
    p2[strcspn(p2, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

    replaceString(t, p1, p2);

    printf("%s", t);

    return 0;
}
