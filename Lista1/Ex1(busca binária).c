#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v, int n, int x) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x) return 1;
        else if (v[mid] < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return 0;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        printf("%d", busca_binaria(v, n, x));
        if (i < q - 1) printf(" ");
    }
    printf("\n");

    free(v);
    return 0;
}
