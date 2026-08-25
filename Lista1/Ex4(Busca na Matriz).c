#include <stdio.h>
#include <stdlib.h>

static int m[1000][1000];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    while (q--) {
        int x;
        scanf("%d", &x);

        /* funcionou se começar de cima e pela direita direita */
        int row = 0, col = n - 1, found = 0;
        while (row < n && col >= 0) {
            if (m[row][col] == x) { found = 1; break; }
            else if (m[row][col] > x) col--;
            else row++;
        }
        printf("%d\n", found);
    }
    return 0;
}
