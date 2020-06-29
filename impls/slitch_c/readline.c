

#include <stdio.h>
#include <stdlib.h>

char* _readline(char prompt[]) {

    int max_len = 100;
    int cur_len = max_len;
    char* line = malloc(max_len);
    char* linep = line;

    int c;

    if (line == NULL)
        return NULL;

    while(1) {
        c = fgetc(stdin);

        if (c == EOF) {
            linep[0] = EOF;
            return linep;
        }

        // If we're out of room, make more
        if (--cur_len == 0) {
            cur_len = max_len;
            char* line_new = realloc(linep, max_len *= 2);

            // If the reallocation failed, clean up and return NULL
            if (line_new == NULL) {
                free(linep);
                return NULL;
            }

            // line should now point to the current character, while linep is
            //   moved to point to the new base
            line = line_new + (line - linep);
            linep = line_new;
        }

        if ((*line++ = c) == '\n')
            break;
    }

    *line = '\0';
    return linep;
}
