/* Problema #12247 - Jollo
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const bool Contem(vector<int> &Vec, const int &Element) {
    if (find(Vec.begin(), Vec.end(), Element) != Vec.end()) return true;
    return false;
}

int main() {
    vector<int> princesa(3), principe(2), todaEntrada;
    int a, b, c, x, y, saida;

    while (cin >> a >> b >> c >> x >> y, a) {
        princesa.clear(); principe.clear();

        saida = 53;

        princesa.push_back(a);
        princesa.push_back(b);
        princesa.push_back(c);
        principe.push_back(x);
        principe.push_back(y);

        sort(princesa.begin(), princesa.end());  //ordena os valores
        sort(principe.begin(), principe.end());  //ordena os valores

        todaEntrada(princesa);
        todaEntrada.insert(todaEntrada.end(), principe.begin(), principe.end()); //Adiciona todas as entradas em um vetor

        if (principe[0] > princesa[2]) {  //verifica se todas as cartas do principe são maiores do que as da princesa
            for (int i = 1; i <= 52 && i < saida; ++i)
                if (!Contem(todaEntrada, i)) saida = i;
        }
        if (principe[1] > princesa[2]) { // verifica se a maior carta do principe é maior que todas da princesa
            for (int i = princesa[2] + 1; i <= 52 && i < saida; ++i)
                if (!Contem(todaEntrada, i)) saida = i;
        }
        if (principe[0] > princesa[1]) { // verifica se o primeiro do principe é maior do que duas cartas da princesa
            for (int i = princesa[1] + 1; i <= 52 && i < saida; ++i)
                if (!Contem(todaEntrada, i)) saida = i;
        }
        if (saida == 53) saida = -1;
        cout << saida << '\n';
    }
}