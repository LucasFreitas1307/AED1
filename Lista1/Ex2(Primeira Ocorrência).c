#include <stdio.h>
#include <stdlib.h>

int primeira_ocorrencia(int *v, int n, int x) {
    int lo = 0, hi = n - 1, resp = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x) {
            resp = mid;
            hi = mid - 1; // tem q continuar buscando a esquerda 
        } else if (v[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return resp;
}

int main(){

    int n, q;
    scanf("%d %d", &n, &q);

    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        int pos = primeira_ocorrencia(v, n, x);
        printf("%d\n", pos == -1 ? -1 : pos + 1);
    }

    free(v);
    return 0;
}
