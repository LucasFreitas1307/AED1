#include <stdio.h>

int n;
char grade[100][101];
int visitado[100][100];
int fila[10000][2];

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", grade[i]);
    }

    if (grade[0][0] == '0' || grade[n - 1][n - 1] == '0') {
        printf("0\n");
        return 0;
    }

    int inicio = 0, fim = 0;
    fila[fim][0] = 0;
    fila[fim][1] = 0;
    fim++;
    visitado[0][0] = 1;

    int dl[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (inicio < fim) {
        int l = fila[inicio][0];
        int c = fila[inicio][1];
        inicio++;

        if (l == n - 1 && c == n - 1) {
            printf("1\n");
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nl = l + dl[d];
            int nc = c + dc[d];
            if (nl >= 0 && nl < n && nc >= 0 && nc < n &&
                !visitado[nl][nc] && grade[nl][nc] == '1') {
                visitado[nl][nc] = 1;
                fila[fim][0] = nl;
                fila[fim][1] = nc;
                fim++;
            }
        }
    }

    printf("0\n");
    return 0;
}
