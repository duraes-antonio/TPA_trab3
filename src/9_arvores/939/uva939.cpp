/* Problema #00939 – Genes
 * Autor: Antônio Carlos Durães da Silva
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define STR_DOM "dominant"
#define STR_REC "recessive"
#define STR_NON "non-existent"

using namespace std;

typedef struct pessoa {
    string nome;
    string pai_1;
    string pai_2;
    string gene;
} t_pess;

map<string, t_pess> map_p_c_gen;    /*Mapa de pessoas com gene preenchido*/
map<string, t_pess> map_filhos;     /*Mapa de pessoas com gene não preenchido*/
map<pair<char, char>, string> gene_comb;

void gerar_combinacoes() {
    gene_comb[make_pair('d', 'd')] = STR_DOM;
    gene_comb[make_pair('d', 'r')] = STR_DOM;
    gene_comb[make_pair('r', 'd')] = STR_DOM;
    gene_comb[make_pair('d', 'n')] = STR_REC;
    gene_comb[make_pair('r', 'r')] = STR_REC;
    gene_comb[make_pair('r', 'n')] = STR_NON;
    gene_comb[make_pair('n', 'n')] = STR_NON;
    gene_comb[make_pair('n', 'r')] = STR_NON;
    gene_comb[make_pair('n', 'd')] = STR_REC;
}

void buscar_pais(const t_pess pessoa) {

    /* Se o primeiro pai do individuo não estiver na lista de pessoas com
     * gene definido, defina seu gene*/
    if (map_p_c_gen.find(pessoa.pai_1) == map_p_c_gen.end()) {
        buscar_pais(map_filhos[pessoa.pai_1]);
    }

    /* Se o segundo pai do individuo não estiver na lista de pessoas com
     * gene definido, defina seu gene*/
    if (map_p_c_gen.find(pessoa.pai_2) == map_p_c_gen.end()) {
        buscar_pais(map_filhos[pessoa.pai_2]);
    }

    /*Já que seus pais possuem o gene preenchido, defina o gene do filho*/
    map_p_c_gen[pessoa.nome].gene = gene_comb[make_pair(
            map_p_c_gen[pessoa.pai_1].gene[0],
            map_p_c_gen[pessoa.pai_2].gene[0])];
}

int main() {

    int n_testes;
    string nome_genitor, gene_filho;

    cin >> n_testes;

    while (n_testes--) {
        cin >> nome_genitor >> gene_filho;

        /* Se o segundo parâmetro for a dominância, registre a pessoa atual no
         * mapa de pessoas com o gene definido*/
        if (gene_filho == STR_NON || gene_filho == STR_REC || gene_filho == STR_DOM) {
            t_pess pessoa;
            pessoa.nome = nome_genitor;
            pessoa.gene = gene_filho;
            map_p_c_gen[nome_genitor] = pessoa;
        }

        /* Senão, se o 2º param for o nome de um filho ainda não registrado,
         * registre-o e armazene seu primeiro pai*/
        else if (map_filhos.find(gene_filho) == map_filhos.end()) {
            t_pess pessoa;
            pessoa.nome = gene_filho;
            pessoa.pai_1 = nome_genitor;
            map_filhos[gene_filho] = pessoa;
        }

        /*Senão, se o filho já estiver registrado, registre seu segundo pai*/
        else map_filhos[gene_filho].pai_2 = nome_genitor;
    }

    gerar_combinacoes();

    /*Para cada filho, busque os genes de seus pais para definir seu próprio*/
    for (auto par: map_filhos) buscar_pais(par.second);

    /*Imprima o par de nome e gene de acordo com a ordem do nome*/
    for (const auto &par: map_p_c_gen) {
        cout << par.first << ' ' << map_p_c_gen[par.first].gene << endl;
    }

    return 0;
}
