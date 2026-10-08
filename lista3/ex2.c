#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[1024];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int rounds = 0;
    for (int t = n; t > 1; t >>= 1) rounds++;

    for (int r = 1; r <= rounds; r++) {
        int t = n >> (r - 1);
        for (int lo = 0; lo < n; lo += t) {
            for (int i = lo; i < lo + t / 2; i++)
                if (a[i] > a[i + t / 2]) {
                    int tmp = a[i];
                    a[i] = a[i + t / 2];
                    a[i + t / 2] = tmp;
                }
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
