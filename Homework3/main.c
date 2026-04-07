#include <stdio.h>
#include <string.h>
#include "weak_func/weak_func.h"

__attribute__((weak)) void weak_func2(void) {
    printf("Defaul behavoir of second func\n");
}

void weak_func1(void) {
    printf("User-defined implementation of first weak function\n");
}

int main(void) {
    //========STRNCPY==========
    char dest1[5][10];
    const char *src1 = "Just some string";

    for (int i = 0; i < 5; ++i) {
        strncpy(dest1[i], src1, sizeof(dest1[i]));
    }

    dest1[4][9] = '\0';
    printf("%s\n", dest1[0]);

    char dest2[5][10];
    const char *src2 = "Right example";

    for (int i = 0; i < 5; ++i) {
        strncpy(dest2[i], src2, sizeof(dest2[i]) - 1);
        dest2[i][sizeof(dest2[i]) - 1] = '\0';
    }

    printf("%s\n", dest2[0]);
    printf("%s\n", dest2[2]);

    //=======STRNCAT==========
    char dest3[10] = "Hi";
    const char *src3 = "Another string";

    strncat(dest3, src3, 4);
    printf("\n%s\n", dest3);
    printf("%llu\n", sizeof(dest3));
    printf("%llu\n", strlen(dest3));

    strncat(dest3, src3, 10);
    printf("\n%s\n", dest3);
    printf("%llu\n", sizeof(dest3));
    printf("%llu\n", strlen(dest3)); //The actual length of the string is bigger, than buffer size

    //=======WEAK FUNCTIONS==========
    #ifdef __GNUC__
    printf("Weak should work\n");
    #endif

    weak_func1();
    weak_func2(); // I moved this function from the weak_func.c to main.c and now it works
    printf("Address of weak_func3: %p\n", (void*)weak_func3); //the address is 0
    weak_func3(); // at this line program crashes because definition is in another file, as far as I can tell, it has to be something with compiler or linker

    return 0;
}