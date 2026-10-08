#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static int bit_size;
static long long *bit;

static void bit_update(int i) {
    for (; i <= bit_size; i += i & (-i))
        bit[i]++;
}

static long long bit_query(int i) {
    long long sum = 0;
    for (; i > 0; i -= i & (-i))
        sum += bit[i];
    return sum;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *v = malloc((size_t)n * sizeof(long long));
    long long *sorted = malloc((size_t)n * sizeof(long long));
    int *rank = malloc((size_t)n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        sorted[i] = v[i];
    }

    qsort(sorted, (size_t)n, sizeof(long long), cmp);

    bit_size = n;
    bit = calloc((size_t)(n + 1), sizeof(long long));

    for (int i = 0; i < n; i++) {
        int lo = 0, hi = n - 1, pos = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (sorted[mid] >= v[i]) {
                pos = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        rank[i] = pos + 1;
    }

    long long swaps = 0;
    for (int i = n - 1; i >= 0; i--) {
        swaps += bit_query(rank[i] - 1);
        bit_update(rank[i]);
    }

    printf("%lld\n", swaps);

    free(v);
    free(sorted);
    free(rank);
    free(bit);
    return 0;
}
