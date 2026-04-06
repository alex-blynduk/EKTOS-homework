#include <stdio.h>

static bool unreachableFunction() {
    printf("This text will not be displayed\n");
    return true;
}

int main(void) {
    //===TASK1====
    if (true || unreachableFunction()) {
        printf("Only this text will be displayed\n");
    }

    if (false && unreachableFunction()) {
        //The function will also not be executed
    }


    //===TASK2====
    if (2 & 5 ) {
        printf("This code will not be reached, though both numbers considered true");
    }

    int num = 4;
    num = num && ~(1 << 2); //we wanted to reset 3rd bit, but used wrong operator instead
    if (num) {
        printf("This text should not be displayed, but it will be because of the usage of wrong operator");
    }

    return 0;
}