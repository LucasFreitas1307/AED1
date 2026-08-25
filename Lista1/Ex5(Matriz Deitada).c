#include <stdio.h>
#include <stdlib.h>

static int m[50][100000];

int main() {
    int M, N, Q;
    scanf("%d %d %d", &M, &N, &Q);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &m[i][j]);

    while (Q--) {
        int x, found = 0;
        scanf("%d", &x);
        for (int i = 0; i < M && !found; i++) {
            int lo = 0, hi = N - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (m[i][mid] == x)      { found = 1; break; }
                else if (m[i][mid] < x)  lo = mid + 1;
                else                     hi = mid - 1;
            }
        }
        printf("%d\n", found);
    }
    return 0;
}
