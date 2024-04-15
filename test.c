#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main() {
    char *line;
    while ((line = readline("Enter a line: ")) != NULL) {
        if (*line) {
            add_history(line);
        }
        free(line);
    }
    return 0;
}