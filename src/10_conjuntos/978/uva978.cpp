/* Problema #978 - Lemmings Battle!
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
 */
#include <iostream>
#include <set>
#include <vector>

#define MORTE_AMBOS "green and blue died"
#define AZUL_V  "blue wins\n"
#define VERDE_V "green wins\n"

using namespace std;

int main() {

    /* Grupos de Lemmings verdes e azuis. Multiset é um conjunto que permite
     * valores duplicados*/
    multiset<int> g_verde, g_azul;

    /* Pilha para os sobreviventes após uma batalha*/
    vector<int> sobrev_verdes, sobrev_azuis;

    int n_testes, temp_forca, n_campos, n_verde, n_azul, min_qtd_grupo, n_batalhas;

    cin >> n_testes;

    while (n_testes--) {
        cin >> n_campos >> n_verde >> n_azul;

        /*Leia o poder de cada integrante do grupo verde*/
        for (int i = 0; i < n_verde; ++i) {
            cin >> temp_forca;
            g_verde.insert(temp_forca);
        }

        /*Leia o poder de cada integrante do grupo azul*/
        for (int i = 0; i < n_azul; ++i) {
            cin >> temp_forca;
            g_azul.insert(temp_forca);
        }

        /*Enquanto houverem guerreiros no grupo verde ou no grupo azul*/
        while (!g_verde.empty() and !g_azul.empty()) {

            /* Verifique o número máximo de batalhas possível com base na
             * quantidade de guerreiros em cada time e número de arenas*/
            min_qtd_grupo = (int) min(g_verde.size(), g_azul.size());
            n_batalhas = min(min_qtd_grupo, n_campos);

            for (int i = 0; i < n_batalhas; ++i) {
                int verde = *(--g_verde.end());
                int azul = *(--g_azul.end());

                /*Remova os dois guerreiros e só add no conjunto, o sobrevivente*/
                g_azul.erase(--g_azul.end()); g_verde.erase(--g_verde.end());

                if (verde > azul) sobrev_verdes.push_back(verde - azul);
                else if (verde < azul) sobrev_azuis.push_back(azul - verde);
            }

            for(auto verde: sobrev_verdes) g_verde.insert(verde);
            sobrev_verdes.clear();

            for(auto azul: sobrev_azuis) g_azul.insert(azul);
            sobrev_azuis.clear();
        }

        if (g_verde.empty() and g_azul.empty()) cout << MORTE_AMBOS << endl;

        /*Se um dos times sobreviveu, veja qual foi e imprima os sobreviventes*/
        else {
            auto g_vencedor = !g_verde.empty() ? g_verde : g_azul;
            cout << (g_vencedor == g_verde ? VERDE_V : AZUL_V);

            while(!g_vencedor.empty()) {
                cout << *(--g_vencedor.end()) << endl;
                g_vencedor.erase(--g_vencedor.end());
            }
        }

        g_verde.clear(); g_azul.clear();
        if (n_testes) cout << endl;
    }

    return 0;
}