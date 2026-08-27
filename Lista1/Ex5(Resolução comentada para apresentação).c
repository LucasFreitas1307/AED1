#include <stdio.h>
#include <stdlib.h>

static int m[50][100000];

int main() {
    int M, N, Q; // M = numero de linhas, N = numero de colunas, Q = numero de consultas
    scanf("%d %d %d", &M, &N, &Q);
    for (int i = 0; i < M; i++) // Laços aninhados para preencher a matriz.
        for (int j = 0; j < N; j++)
            scanf("%d", &m[i][j]); // Preenche a matriz com os valores fornecidos pelo usuário.

    while (Q--) { //O laço vai executar exatamente Q vezes. A cada iteração, Q é decrementado até chegar a zero
        int x, found = 0; // x é o valor a ser buscado na matriz, found é uma variável de controle que indica se o valor foi encontrado ou não.
        scanf("%d", &x);
        for (int i = 0; i < M && !found; i++) { //Este laço percorre as linhas de cima para baixo.
                                                //&& !found garante que o laço só continue enquanto o valor não for encontrado. Se o número for encontrado na linha 2, por exemplo, o found vira 1, !found vira 0 (falso), e o laço é interrompido imediatamente.
            int lo = 0, hi = N - 1;  // lo e hi sao indices de limites inferior e superior da busca binária. Inicialmente, lo é 0 (primeiro índice da linha) e hi é N - 1 (último índice da linha).
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (m[i][mid] == x)      { found = 1; break; } // se o x for exatamente igual a m[i][mid], found vira 1 e usamos break para sair do laço while.
                else if (m[i][mid] < x)  lo = mid + 1; // se o valor no meio for menor que x, ajustamos o limite inferior da busca para mid + 1.
                else                     hi = mid - 1; // se o valor no meio for maior que x, ajustamos o limite superior da busca para mid - 1.
            }
        }
        printf("%d\n", found);
    }
    return 0;
}

//O numero de complexidade desse codigo é que M log N, limite de linhas M é pequeno (50) e limite de colunas N é grande (100000). 
// Assim, limitamos esse codigo a 17 comparações por linha, totalizando 850 comparações no pior caso.
// A complexidade do código é O(M log N) porque para cada uma das M linhas, realizamos uma busca binária que tem complexidade O(log N).
