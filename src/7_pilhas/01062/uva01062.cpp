/* Problema #1062 - Containers
 * Autor: Antônio Carlos Durães da Silva
 */
#include <iostream>
#include <vector>
#include <stack>

#define MAX_N 1000

using namespace std;

int indice_pilha_satisf(vector<stack<char>> *pilhas, char letra) {

    int ind_menor = INT32_MAX;
    char char_topo;
    char menor_char = 'Z';

    for (int i = 0; i < pilhas->size(); ++i) {
        char_topo = ((*pilhas)[i]).top();

        if (letra <= char_topo and char_topo <= menor_char) {
            menor_char = char_topo;
            ind_menor = i;
        }
    }

    return ind_menor;
}

int main() {

    string linha;
    vector<stack<char>> pilhas;
    int indice_pil_adeq;
    int n_caso = 0;

    /* OTIM: Reserve o máximo de caracteres a serem lidos*/
    linha.reserve(MAX_N);

    // Enquanto a linha lida não estiver vazia
    while (getline(cin, linha) and linha != "end") {

        // Para cada container (letra)
        for (char letra : linha) {

            /* Obtenha o índice da pilha adequada para o container E de topo
             * mais próximo do container atual. */
            indice_pil_adeq = indice_pilha_satisf(&pilhas, letra);

            /* Se não encontrou um índice satisfatório, crie uma nova pilha
             * para o container atual*/
            if (indice_pil_adeq == INT32_MAX) {
                stack<char> nova_pilha;
                nova_pilha.push(letra);
                pilhas.push_back(nova_pilha);
            }

            /* Senão, empilhe o container atual na pilha mais adequada*/
            else {
                pilhas[indice_pil_adeq].push(letra);
            }
        }

        printf("Case %d: %d\n", ++n_caso, pilhas.size());
        pilhas.clear();
    }

    return 0;
}