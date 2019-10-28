/* Problema #10920 - Spiral tap
 * Autor: Lucas Gomes Flegler
 */

#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    // convem usar longos longos, pois os valores de
    // entrada e saida podem ser bastante grandes
    long long SZ, P, raiz, i, j, linha, coluna;
    long grupo;

    while (true)
    {
        scanf("%lld %lld", &SZ, &P);
        if (SZ == 0 && P == 0)
            break;

        // Para descobrir em que anel estamos, pegamos a raiz quadrada de P
        // e calculamos o próximo valor ímpar acima
        raiz = sqrt(P);
        if ((raiz * raiz != P) && (raiz % 2 == 1))
            raiz += 2;
        else if (raiz % 2 != 1)
            raiz++;

        // verifica-se o valor da raiz eh diferente de 1, para nao fazer
        // divisao por 0
        if (raiz * raiz != 1)
        {
            i = raiz / 2, j = raiz / 2;
            grupo = (raiz * raiz - P) / (raiz - 1);
            switch (grupo)
            {
            case 0:
                i -= ((raiz * raiz) - P);
                break;
            case 1:
                i -= raiz - 1;
                j -= ((raiz * raiz) - P - (raiz - 1));
                break;
            case 2:
                i -= (raiz - 1) - ((raiz * raiz) - P - (raiz - 1) * 2);
                j -= raiz - 1;
                break;
            case 3:
                j -= (raiz - 1) - ((raiz * raiz) - P - (raiz - 1) * 3);
                break;
            }
        }
        linha = (i + SZ / 2 + 1);
        coluna = (j + SZ / 2 + 1);
        printf("Linha = %lld, Coluna = %lld.\n", linha, coluna);
    }
}