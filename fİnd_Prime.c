#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern void find_prime(uint8_t* sieve, int n);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Kullanim: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N < 2) {
        printf("N >= 2 olmali\n");
       return 1;
    }

    uint8_t* mask = malloc(N + 1);

    for (int i = 0; i <= N; i++)
        mask[i] = 1;

    mask[0] = mask[1] = 0;

    find_prime(mask, N);
    
    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (mask[i])
            count++;
    }

    printf("2..%d arasinda %d asal var\n", N, count);
    
    for (int i = 2; i < N; i++) {
        if (mask[i])
            printf("%d ", i);
    }
    printf("\n");
    

    free(mask);
    return 0;
}
