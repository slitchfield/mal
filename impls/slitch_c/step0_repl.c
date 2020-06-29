#include <stdio.h>

#include "readline.h"

char* READ(char* in) {
    return in;
}

char* EVAL(char* in) {
    return in;
}

char* PRINT(char* in) {
    return in;
}

char* rep(char* in) {
    char* read_res = READ(in);
    char* eval_res = EVAL(read_res);
    char* print_res = PRINT(eval_res);
    return print_res;
}

int main()
{
    char prompt[] = "user> ";

    for(;;) {
        fprintf(stdout, "%s", prompt);

        char* line = _readline("");
        char* res = rep(line);

        if (res[0] == EOF) {
            break;
        }

        fprintf(stdout, "%s", res);
    } 

}
