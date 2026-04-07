#include "weak_func.h"
#include <stdio.h>

__attribute__((weak)) void weak_func1(void) {
    printf("Default behavior of first func\n");
}

// __attribute__((weak)) void weak_func2(void) {
//     printf("Defaul behavoir of second func\n");
// }

__attribute__((weak)) void weak_func3(void) {
    printf("Defaul behavoir of third func\n");
}