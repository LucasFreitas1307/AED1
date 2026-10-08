#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MOD 1000000007ULL

static int cmp(const void *a, const void *b) {
    uint32_t x = *(const uint32_t *)a;
    uint32_t y = *(const uint32_t *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    long n;
    unsigned long long s;
    if (scanf("%ld %llu", &n, &s) != 2) return 0;

    uint32_t *x = malloc((size_t)n * sizeof(uint32_t));

    uint32_t c = (uint32_t)s;
    for (long i = 0; i < n; i++) {
        c ^= c << 13;
        c ^= c >> 17;
        c ^= c << 5;
        x[i] = c;
    }

    qsort(x, (size_t)n, sizeof(uint32_t), cmp);

    unsigned long long total = 0;
    for (long i = 0; i < n; i++) {
        unsigned long long term = (unsigned long long)(i + 1) * (unsigned long long)x[i] % MOD;
        total = (total + term) % MOD;
    }

    printf("%llu\n", total);

    free(x);
    return 0;
}
