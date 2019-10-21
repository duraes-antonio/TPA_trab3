/* Problema #11849 - CD
 * Autor: Antônio Carlos Durães da Silva
 */
#include <iostream>
#include <set>

using namespace std;

int main() {

    set<int> cd_numeros;
    int n_jack, n_jill, soma_jj, temp_num;

    // Enquanto Jack ou Jill tiverem discos a serem lidos
    while (cin >> n_jack >> n_jill and (n_jack + n_jill) > 0) {

        // Guarde a soma da quantidade de discos que ambos possuem
        soma_jj = n_jack + n_jill;

        // Leia os valores dos N discos
        for (int i = 0; i < soma_jj; ++i) {
            cin >> temp_num;
            cd_numeros.insert(temp_num);
        }

        /* O que ambos possuem em comum é exatamente:
         * a soma da quantidade de discos - a quantidade discos únicos*/
        cout << soma_jj - cd_numeros.size() << endl;
        cd_numeros.clear();
    }

    return 0;
}