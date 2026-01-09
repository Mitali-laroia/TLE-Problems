#include<stdio.h>
#include<stdlib.h>
#include<stdatomic.h>

int main(int argc, char *argv[]) {
    if (argc != 3){
        printf("Usage: %s <num1> <num2> \n", argv[0]);
        return 1;
    }

    atomic_int a, b;
    atomic_int result;

    atomic_init(&a, atoi(argv[1]));
    atomic_init(&b, atoi(argv[2]));

    atomic_store(&result, atomic_load(&a) + atomic_load(&b));
    printf("Addition: %d\n", atomic_load(&result));

    atomic_store(&result, atomic_load(&a) - atomic_load(&b));
    printf("Subtraction: %d\n", atomic_load(&result));

    atomic_store(&result, atomic_load(&a) * atomic_load(&b));
    printf("Multiplication %d\n", atomic_load(&result));
    
    return 0;
}