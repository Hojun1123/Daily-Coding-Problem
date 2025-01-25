#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
char str[100];
void conv() {
   
    if (strlen(str) % 2) {
        return;
    }

    char curr[100];
    int index = 0;
    char prev = 'a';
    for (int i = 0; i < strlen(str); i += 2) {
        int cnt = str[i] - '0';
        char alpha = str[i + 1];
        if (alpha == prev) {
            return;
        }
        prev = alpha;
        for (int j = 0; j < cnt; ++j) {
            curr[index++] = alpha;
        }
    }
    curr[index] = '\0';
    if (strcmp(curr, str) == 0) {
        return;
    }
    strcpy(str, curr);
    conv();
}
int main()
{
    int tc = 1;
    while (1) {
        scanf("%s", str);
        if (str[0] == '0') break;

        conv();

        printf("Test %d: %s\n", tc++, str);

    }
}