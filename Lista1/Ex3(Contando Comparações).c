#include <stdio.h>
#include <stdlib.h>

long long count(long long key, long long n) {
    long long e = 0, d = n - 1, steps = 0;
    while (e <= d) {
        long long c = (e + d) / 2;
        steps++;
        if (c == key) return steps;
        else if (c < key) e = c + 1;
        else d = c - 1;
    }
    return steps;
}
int main() {
    long long n, q;
    scanf("%lld %lld", &n, &q);
    while (q--) {
        long long x;
        scanf("%lld", &x);
        printf("%lld\n", count(x, n));
    }
    return 0;
}
