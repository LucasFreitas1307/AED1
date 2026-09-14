#include <stdio.h>

int n;
int col[12];
long long total = 0;

int valido(int linha, int c) {
    for (int i = 0; i < linha; i++) {
        if (col[i] == c || col[i] - i == c - linha || col[i] + i == c + linha) {
            return 0;
        }
    }
    return 1;
}

void resolver(int linha) {
    if (linha == n) {
        total++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (valido(linha, c)) {
            col[linha] = c;
            resolver(linha + 1);
        }
    }
}

int main(void) {
    scanf("%d", &n);
    resolver(0);
    printf("%lld\n", total);
    return 0;
}
