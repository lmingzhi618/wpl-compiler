#include <stdio.h>

#include "wpl_runtime.h"

int sum(int a, int b) {
    return a + b;
}

int program() {
    int nArgs = getArgCount();
    int sum = 0;
    int i = 1;
    while (i < nArgs) {
        sum += getIntArg(i++);
    }
    printf("The sum of the arguments is: %d\n", sum);
    return sum;
}

