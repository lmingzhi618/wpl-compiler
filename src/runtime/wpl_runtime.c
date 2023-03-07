#include "wpl_runtime.h"

#include <stdio.h>
#include <stdlib.h>

// The WPL program entry function
int program();

int argCount;
char **args;

/* @ brief main program that calls the WPL program() function
 * @param argc
 * @param argv
 * @returnint
 */
int main(int argc, char *argv[]) {
    argCount = argc;
    args = argv;
    return program();
}

int getArgCount() { return argCount; }

char *getStrArg(int i) {
    if (i < 0 || i >= argCount) {
        fprintf(stderr,
                "Attempt to access an argument out of bounds -- aborting!\n");
        exit(-1);
    }
    return args[i];
}

/**
 * @brief Get an argument from the command line as an integer
 * @param i
 * @return int
 */
int getIntArg(int i) {
    if (i < 0 || i >= argCount) {
        fprintf(stderr,
                "Attempt to access an argument out of bounds -- aborting!\n");
        exit(-1);
    }
    return atoi(args[i]);
}
