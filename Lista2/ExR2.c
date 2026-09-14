#include <stdio.h>

long long mdc(long long a, long long b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", mdc(a, b));
    return 0;
}
