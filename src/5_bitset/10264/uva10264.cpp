/* Problema #10264 - The Most Potent Corner uva
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int N;
int vet[20000];
int sum[20000];

int main()
{
    while (cin>>N)
    {
        // Deslocamento para a esquerda mudando os bits do primeiro operando, 
        // o segundo operando decide o número de locais a serem deslocados.
        int potencia = 1 << N;
        int max_sum = 0;
        for (int i = 0; i < potencia; i++)
        {
            scanf("%d", &vet[i]);
        }

        // Calculando e somando as potencias.
        for (int i = 0; i < potencia; i++)
        {
            int sum_potencia = 0;
            for (int j = 0; j < N; j++)
            {
                int aux = i ^ (1 << j);
                sum_potencia += vet[aux];
            }
            sum[i] = sum_potencia;
        }

        // Realizando pesquisa completa pela soma máxima de potências dos dois cantos vizinhos
        for (int i = 0; i < potencia; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int aux = i ^ (1 << j);
                max_sum = max(max_sum, sum[i] + sum[aux]);
            }
        }

        printf("%d\n", max_sum);
    }
}