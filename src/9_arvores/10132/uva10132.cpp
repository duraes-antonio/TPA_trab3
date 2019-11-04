/* Problema #10132 - File Fragmentation
 * Autor: Antônio Carlos Durães da Silva
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> frag_bits;

vector<pair<int, string>> gerar_combinacoes() {

    const int tam = frag_bits.size();
    map<string, int> comb_freq;
    vector<pair<int, string>> freq_comb;

    /* Gere todas permutações possíveis e associe com sua frequência.
     * Combine cada fragmento com outro*/
    for (int i = 0; i < tam; ++i) {

        /* Gere tanto a combinação do frag <i, j> quanto <j, i>, pois
         * ordem diferente trata-se de um arquivo diferente*/
        for (int j = i + 1; j < tam; ++j) {
            ++comb_freq[frag_bits[i] + frag_bits[j]];
            ++comb_freq[frag_bits[j] + frag_bits[i]];
        }
    }

    freq_comb.reserve(comb_freq.size());

    for(auto comb_cont: comb_freq) {
        freq_comb.emplace_back(comb_cont.second, comb_cont.first);
    }

    return freq_comb;
}

int main() {

    int n_testes;
    string bits;

    /*Leia o número de testes e a primeira linha*/
    cin >> n_testes >> bits;
    cin.ignore();

    while (n_testes--) {

        /*Enquanto houverem fragmentos a serem lidos*/
        while (!bits.empty()) {
            frag_bits.push_back(bits);
            getline(cin, bits);
        }

        /*Gere todas combinações e ordene por sua frequência na lista de combinações*/
        vector<pair<int, string>> comb_cont = gerar_combinacoes();
        sort(comb_cont.begin(), comb_cont.end());

        cout << comb_cont[comb_cont.size() - 1].second << endl;
        frag_bits.clear();
        getline(cin, bits);

        if (!bits.empty()) cout << endl;
    }

    return 0;
}