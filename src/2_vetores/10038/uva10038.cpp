/* Problema #10038 - Jolly Jumpers
 * Autor: Antônio Carlos Durães da Silva
 */
#include <vector>
#include <iostream>

using namespace std;

#define JOL     "Jolly"
#define NJOL    "Not jolly"
#define MAX_N   3000

int main() {

    vector<bool> diferencas;
    bool jolly;
    int n, num_anterior, num_atual, dif;

    /*OTIM: Reserve o máximo de elementos possível*/
    diferencas.reserve(MAX_N);

    while(cin >> n && n > 0) {
        jolly = true;
        fill(diferencas.begin(), diferencas.begin() + n, false);

        cin >> num_anterior;

        /*Marque todas diferenças entre elementos que forem encontradas*/
        for (int i = 1; i < n; ++i) {
            cin >> num_atual;
            dif = abs(num_anterior - num_atual);
            if (dif < n) diferencas[dif] = true;
            num_anterior = num_atual;
        }

        /*Na primeira diferença ausente, imprima que não é Jolly*/
        for (int i = 1; i < n and jolly; ++i) {
            jolly = diferencas[i];
        }

        if (jolly) cout << JOL << endl;
        else cout << NJOL << endl;
    }

    return 0;
}