#include <stdio.h>

int n;
long long a[24];

int existe(int pos, long long restante) {
    if (restante == 0) return 1;
    if (pos == n || restante < 0) return 0;
    if (existe(pos + 1, restante - a[pos])) return 1;
    return existe(pos + 1, restante);
}

int main(void) {
    long long t;
    scanf("%d %lld", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    printf("%d\n", existe(0, t));
    return 0;
}
