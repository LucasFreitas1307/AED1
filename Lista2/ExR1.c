#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long a = 1, b = 1; 
    if (n == 0 || n == 1) {
        printf("%lld\n", a);
        return 0;
    }

    long long f = 0;
    for (int i = 2; i <= n; i++) {
        f = a + b;
        a = b;
        b = f;
    }

    printf("%lld\n", f);
    return 0;
}
