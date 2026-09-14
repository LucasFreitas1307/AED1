#include <stdio.h>

int n;
int used[9];
int perm[9];

void gerar(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            printf("%d%c", perm[i], i == n - 1 ? '\n' : ' ');
        }
        return;
    }
    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            used[v] = 1;
            perm[pos] = v;
            gerar(pos + 1);
            used[v] = 0;
        }
    }
}

int main(void) {
    scanf("%d", &n);
    gerar(0);
    return 0;
}
