/* Problema #11581 - Grid successors
 * Autor: Lucas Gomes Flegler
 */

#include <cstdio>
using namespace std;

int g[3][3];

bool allzeros()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (g[i][j] > 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int TC;

    scanf("%d", &TC);

    while (TC--)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%1d", &g[i][j]);
            }
        }

        int resposta = -1;
        //se todos os valores sao zeros, retorna -1
        // caso contrario calcula a soma dos adjacentes
        while (!allzeros())
        {
            int matAux[3][3];
            
            // calculando a soma dos adjancentes, 
            // posicao por posicao
            matAux[0][0] = (g[0][1] + g[1][0]) % 2;
            matAux[0][1] = (g[0][0] + g[1][1] + g[0][2]) % 2;
            matAux[0][2] = (g[0][1] + g[1][2]) % 2;

            matAux[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
            matAux[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
            matAux[1][2] = (g[1][1] + g[0][2] + g[2][2]) % 2;

            matAux[2][0] = (g[2][1] + g[1][0]) % 2;
            matAux[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
            matAux[2][2] = (g[2][1] + g[1][2]) % 2;

            // atribuindo o valor da matiz auxiliar para 
            // a original
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    g[i][j] = matAux[i][j];
                }
            }
            // somando +1 para resposta final
            resposta++;
        }

        printf("%d\n", resposta);
    }

    return 0;
}