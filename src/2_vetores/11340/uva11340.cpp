/* Problema #11340 - Newspaper
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
 */
#include <iostream>

#define MAX_PRECO_CHAR  100
#define MAX_N_CHAR_LIN  10000

using namespace std;

int main() {

    int n_testes, n_preco_char, n_linha, preco_soma, precos[100];
    char caracteres[100];
    string linha;
    cin >> n_testes;

    while (n_testes--) {
        preco_soma = 0;
        cin >> n_preco_char;

        // Leia os caracteres e seus respectivos preços
        for (int i = 0; i < n_preco_char; ++i) {
            cin >> caracteres[i];

            // Armazene o valor do caractere que acabou de ser lido
            cin >> precos[i];
        }

        cin >> n_linha;
        cin.ignore();   // Ignore o char de fim de linha antes de um 'getline'

        for (int i = 0; i < n_linha; ++i) {
            getline(cin, linha);

            for (const char simb : linha) {

                // Procure seu preço correspondente na lista de preços por char
                for(int j = 0; j < n_preco_char; ++j) {
                    if (caracteres[j] == simb) {
                        preco_soma += precos[j];
                        break;
                    }
                }
            }
        }

        printf("%.2lf$\n", preco_soma / 100.0);
    }

    return 0;
}