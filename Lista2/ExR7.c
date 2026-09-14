#include <stdio.h>

int n, k;
int comb[18];

void gerar(int pos, int proximo) {
    if (pos == k) {
        for (int i = 0; i < k; i++) {
            printf("%d%c", comb[i], i == k - 1 ? '\n' : ' ');
        }
        return;
    }
    for (int v = proximo; v <= n; v++) {
        comb[pos] = v;
        gerar(pos + 1, v + 1);
    }
}

int main(void) {
    scanf("%d %d", &n, &k);
    gerar(0, 1);
    return 0;
}
