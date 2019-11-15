/* Problema #10038 - Jolly Jumpers
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
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
        for (int i = 1; i < n and jolly; ++i) jolly = diferencas[i];

        cout << (jolly) ? JOL : NJOL << endl;
    }

    return 0;
}