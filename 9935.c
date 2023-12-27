#include <stdio.h>
#include <string.h>

char str[1000000] = "";
char stack[1000000] = "";

int main() {
    char explosion[36] = "";
    int str_len = 0;
    int ex_len = 0;
    int index = 0;

    scanf("%s", &str);
    scanf("%s", &explosion);
    
    str_len = strlen(str);
    ex_len = strlen(explosion);
    index = ex_len - 1;

    strncpy(stack, str, ex_len - 1);

    for (int i = ex_len - 1; i <= str_len; i++) {
        stack[index++] = str[i];
        if (strncmp(&stack[index - ex_len], explosion, ex_len) == 0) {
            index -= ex_len;
        }
    }
    stack[index] = 0;
    if (strcmp(stack, "") == 0) {
        printf("FRULA\n");
    }
    else {
        printf("%s\n", stack);
    }
    
    return 0;
}
