#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define RANGE 1048576u       /* 2^20 */
#define MOD   1000000007ULL

int main(void) {
    long n;
    unsigned long long s;
    if (scanf("%ld %llu", &n, &s) != 2) return 0;

    /* counting sort: só precisamos de quantas vezes cada valor aparece */
    long long *count = calloc(RANGE, sizeof(long long));

    uint32_t c = (uint32_t)s;
    for (long i = 0; i < n; i++) {
        c ^= c << 13;
        c ^= c >> 17;
        c ^= c << 5;
        count[c % RANGE]++;
    }

    unsigned long long total = 0;
    long long prefix = 0;
    for (unsigned v = 0; v < RANGE; v++) {
        long long cnt = count[v];
        if (cnt == 0) continue;
        /* soma dos índices (1-based) ocupados pelo valor v na ordem crescente */
        long long range_sum = cnt * (2 * prefix + cnt + 1) / 2;
        unsigned long long term = (unsigned long long)v * (unsigned long long)(range_sum % MOD) % MOD;
        total = (total + term) % MOD;
        prefix += cnt;
    }

    printf("%llu\n", total);

    free(count);
    return 0;
}
