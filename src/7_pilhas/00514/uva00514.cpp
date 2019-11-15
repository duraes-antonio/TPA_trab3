/* Problema #00514 – Rails
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
 */
#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<int> pilha_carros;
    int n_carros, carro, cont_carro;
    bool linha_vazia;
    cin >> n_carros;

    while (n_carros > 0) {
        linha_vazia = false;
        cont_carro = 0;
        /*Esvazie / inicialize a pilha de carros*/
        pilha_carros = stack<int>();

        /*Enquanto houverem carros a serem lidos*/
        for (int i = 0; i < n_carros; ++i) {
            cin >> carro;

            /*Se o número lido sinalizar o fim de um bloco, aborte o empilhamento*/
            if (carro == 0) {
                cin >> n_carros;

                /*Se houver um próximo bloco a ser lido, separe a saída com uma
                 * linha em branco*/
                cout << endl;
                linha_vazia = true;
                break;
            }

            while (cont_carro < n_carros && cont_carro != carro) {
                if (!pilha_carros.empty() && pilha_carros.top() == carro) break;
                pilha_carros.push(++cont_carro);
            }

            if (pilha_carros.top() == carro) pilha_carros.pop();
        }

        /* Se o empilhamento não foi quebrado por um fim de bloco, imprima o
         * resultado*/
        if (!linha_vazia) pilha_carros.empty() ? printf("Yes\n") : printf("No\n");
    }

    return 0;
}