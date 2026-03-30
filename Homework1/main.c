#include <stdint.h>
#include <stdio.h>
#include "int_to_binary/int_to_binary.h"

//====== PREVIOUS HOMEWORK==========
void prev(void) {
    const uint32_t int32 = 0x12345678;
    const uint8_t* int8p = (uint8_t*)&int32;

    for (int i = 0; i < 4; ++i) {
        printf("%x ", *int8p++);
    }
}

//======== TASK 1 =============
void task1(void) {
    printf("Task 1\n");
    printf("\n\nMy age is 20, binary: ");
    print_binary16(20);
    printf("Negative: ");
    print_binary16(-20);
    printf("\nMy birth year is 2005, binary: ");
    print_binary16(2005);
    printf("Negative: ");
    print_binary16(-2005);

}

//======== TASK2 ===============
int8_t add_age(const int8_t arg) {
    return 20 + arg;
}

void task2(void) {
    const int8_t arr[4] = {127, -1, 10, -128};

    printf("\nTask 2\n");
    for (int i = 0; i < 4; ++i) {
        printf("Decimal: %d\nBinary: ", add_age(arr[i]));
        print_binary8(add_age(arr[i]));
    }
}

//======== TASK3 ===============
uint8_t add_age_u(const uint8_t arg) {
    return 20 + arg;
}

void task3(void) {
    const uint8_t arr[4] = {127, 255, 10, 240};

    printf("\nTask 3\n");
    for (int i = 0; i < 4; ++i) {
        printf("Decimal: %d\nBinary: ", add_age_u(arr[i]));
        print_binary8u(add_age_u(arr[i]));
    }
}

//======== TASK9 ===============
uint32_t setBit(const uint32_t arg, const uint8_t bit) {
    return arg | (1 << bit);
}

uint32_t resetBit(const uint32_t arg, const uint8_t bit) {
    return arg & ~(1 << bit);
}

void task9() {
    printf("\nTask 9\n");
    printf("Number: ");
    print_binary16(20);
    printf("After setting bit 1: ");
    print_binary16(setBit(20, 1));
    printf("Number: ");
    print_binary16(20);
    printf("After resetting bit 2: ");
    print_binary16(resetBit(20, 2));
}

//======== TASK10 ===============
uint8_t switchBit(const uint8_t arg, const uint8_t bit) {
    return arg ^ (1 << bit);
}

void task10() {
    printf("\nTask 10 (blink)\n");
    uint8_t num = 20;

    printf("Blinking number 20\n");
    print_binary8u(num);

    for (int i = 0; i < 4; ++i) {
        num = switchBit(num, 2);
        print_binary8u(num);
    }
}

//======== TASK11 ===============
void task11() {
    printf("\nTask 11\n");
    const uint8_t num = 121;
    const int8_t num2 = 121;

    printf("\nUnsigned left shift demo\n Initial number: %d\n", num);
    print_binary8u(num);
    for (int i = 1; i <= 3; ++i) {
        printf("After << %d: %d - ", i, (uint8_t)(num << i));
        print_binary8u(num << i);
    }

    printf("\nUnsigned right shift demo\n Initial number: %d\n", num);
    print_binary8u(num);
    for (int i = 1; i <= 3; ++i) {
        printf("After >> %d: %d - ", i, (uint8_t)(num >> i));
        print_binary8u(num >> i);
    }

    printf("\nSigned left shift demo\n Initial number: %d\n", num2);
    print_binary8(num2);
    for (int i = 1; i <= 3; ++i) {
        printf("After << %d: %d - ", i, (int8_t)(num2 << i));
        print_binary8(num2 << i);
    }

    printf("\nSigned right shift demo\n Initial number: %d\n", num2);
    print_binary8(num2);
    for (int i = 1; i <= 3; ++i) {
        printf("After >> %d: %d - ", i, (int8_t)(num2 >> i));
        print_binary8(num2 >> i);
    }
}


int main(void) {
    prev();

    task1();
    task2();
    task3();
    task9();
    task10();
    task11();

    return 0;
}

