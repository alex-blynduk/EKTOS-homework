#include <stdint.h>
#include <stdio.h>

static void isLittleEndian(void);

const int global_var = 1; // this variable is visible everywhere inside this file and can be accessed from other files
static int static_global_var = 1; //this variable only accessible inside this file
extern const int extern_var; // its variable value is taken from another file

extern void (*func_ptr)(void);

int main(void) {
    //============TASK1===============
    const int x = 1;
    {
        const int x = 2;
        printf("x = %d\n", x);
    }

    {
        const int x = 3;
        printf("x = %d\n", x);

        switch (x) {
            case 1: {
                printf("x value is kept from main function scope\n");
                break;
            }
            case 2 : {
                printf("x value is kept from block 1\n");
                break;
            }
            case 3 : {
                printf("x value is kept from block 2 because of shadowing\n");
                break;
            }
            default: {
                printf("char is unknown");
                break;
            }
        }
    }
    printf("x = %d\n", x);

    //============TASK2===============
    const int local_var = 1; //this variable is only visible inside this function;
    printf("local_var = %d\n", local_var);
    printf("global_var = %d\n", global_var);

    for (int i = 0; i < 3; ++i) {
        static int static_local_var = 0; //this variable preserves its value between loop iterations
        static_local_var += 2;

        if (2 == i) {
            printf("static_local_var = %d\n", static_local_var);
        }
    }

    printf("static_global_var = %d\n", static_global_var);
    printf("extern_var = %d\n", extern_var);


    //============TASK3===============
    static const int array[5] = {1, 2, 3, 4, 5};
    const int* ptr = array;
    uint64_t ptr_in_uint64 = (uint64_t)ptr;
    printf("uint64_ptr = %llx\n", ptr_in_uint64);
    ptr = (int*)ptr_in_uint64;
    printf("ptr = %p\n", ptr);
    printf("++ptr = %p\n", ++ptr);
    printf("ptr - array = %lld\n", ptr - array);
    printf("ptr < array = %s\n\n", ptr < array ? "true" : "false");

    ptr_in_uint64++;
    ptr = (int*)ptr_in_uint64;
    printf("ptr = %p\n", ptr);
    printf("*ptr = %d\n", *ptr);

    ptr_in_uint64 += 3; //now it is the address of second element of the array
    ptr = (int*)ptr_in_uint64;
    printf("ptr = %p\n", ptr);
    printf("*ptr = %d\n", *ptr);

    //============TASK4===============
    isLittleEndian();

    //============TASK5===============
    func_ptr();

    return 0;
}

static void isLittleEndian(void) {
    const uint16_t num = 0x1234;
    const uint8_t* p = (uint8_t*)&num;
    if (0x34 == *p) {
        printf("Machine is little endian\n");
    } else {
        printf("Machine is big endian\n");
    }
}