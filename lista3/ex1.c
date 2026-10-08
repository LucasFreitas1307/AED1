#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int *a = malloc(n * sizeof(int));
    int *b = malloc(m * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    int *res = malloc((n + m) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) res[k++] = a[i++];
        else res[k++] = b[j++];
    }
    while (i < n) res[k++] = a[i++];
    while (j < m) res[k++] = b[j++];

    for (int t = 0; t < n + m; t++) {
        printf("%d%c", res[t], t == n + m - 1 ? '\n' : ' ');
    }

    free(a);
    free(b);
    free(res);
    return 0;
}
