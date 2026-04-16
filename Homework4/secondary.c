#include <stdio.h>
const int extern_var = 5;

static void func(void) {
    printf("This is a static function from another file\n");
}

void (*func_ptr)(void) = func;
