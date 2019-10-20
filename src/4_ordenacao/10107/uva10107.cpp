/* Problema #10107 - What is the Median?
 * Autor: Antônio Carlos Durães da Silva
 */
#include <iostream>
#include <algorithm>

#define MAX_N 10000

using namespace std;

int main() {

    int meio, n;

    /* Defina um array com o maior tamanho possível. Long é usado, pois o valor
     * pode atingir 2^31*/
    long entrada[MAX_N];
    int i = -1;

    /*OTIM: Leia o elemento direto para posição do array processado (Sem
     * variável auxiliar)*/
    while (cin >> entrada[++i] && entrada[i] > -1) {

        /* O endereço do array já é um ponteiro para o local do 1ª item.
         * Some o endereço de memória do array com a posição atual (i) + 1 para
         * definir sua última posição.*/
        sort(entrada, entrada + i + 1);
        meio = i / 2;

        /*Se o número de elementos for ímpar, imprima o elemento do meio*/
        if (i % 2 == 0) cout << entrada[meio];

        /*Senão, imprima o piso da média dos dois elementos centrais*/
        else cout << (entrada[meio] + entrada[meio+1])/2;

        cout << endl;
    }

    return 0;
}