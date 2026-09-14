#include <stdio.h>

long long dp[81];

int main(void) {
    int n;
    scanf("%d", &n);

    dp[0] = 1;
    for (int parte = 1; parte <= n; parte++) {
        for (int j = parte; j <= n; j++) {
            dp[j] += dp[j - parte];
        }
    }

    printf("%lld\n", dp[n]);
    return 0;
}
