/* Problema #10258 - Contest Scoreboard?
 * Autor: Antônio Carlos Durães da Silva
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

#define INV_PENALIDADE 20
#define N_USUARIOS 100
#define N_PROBLEMAS 10


using namespace std;

struct problema {
    int id;
    int minutos;
    char status;
    bool resolvido;
};
typedef struct problema t_prob;

struct usuario_problema {
    int id_usuario = -1;
    int n_prob_res = 0;
    int n_minutos = 0;
    bool participa = false;

    t_prob probs[N_PROBLEMAS]{};
};
typedef struct usuario_problema t_usu_prob;

bool cmpUsuarioProblemas(usuario_problema u1, usuario_problema u2) {

    if (u1.participa != u2.participa)
        return u1.participa > u2.participa;

    if (u1.n_prob_res != u2.n_prob_res)
        return u1.n_prob_res > u2.n_prob_res;

    if (u1.n_minutos != u2.n_minutos)
        return u1.n_minutos < u2.n_minutos;

    return (u1.id_usuario < u2.id_usuario);
}

int main() {

    int n_testes;
    vector<t_usu_prob> u_probs;
    string limbo;

    int id_usu;
    t_prob prob;
    t_usu_prob usuario;

    u_probs.reserve(100);

    /*Leia o número de testes*/
    cin >> n_testes;
    getline(cin, limbo);
    getline(cin, limbo);

    while (n_testes--) {

        u_probs.clear();

        for (int i = 0; i < N_USUARIOS; ++i) {
            usuario.id_usuario = i + 1;
            u_probs.push_back(usuario);
        }

        while (getline(cin, limbo), limbo.size() > 0) {
            stringstream stream_linha(limbo);
            stream_linha >> id_usu >> prob.id >> prob.minutos >> prob.status;

            if (!u_probs[id_usu - 1].probs[prob.id - 1].resolvido) {

                u_probs[id_usu - 1].participa = true;

                if (prob.status == 'I') {
                    u_probs[id_usu - 1].probs[prob.id - 1].minutos += INV_PENALIDADE;
                }

                else if (prob.status == 'C') {
                    u_probs[id_usu - 1].probs[prob.id - 1].minutos += prob.minutos;
                    u_probs[id_usu - 1].probs[prob.id - 1].resolvido = true;
                    ++u_probs[id_usu - 1].n_prob_res;
                    u_probs[id_usu - 1].n_minutos += u_probs[id_usu - 1].probs[prob.id - 1].minutos;
                }
            }
        }

        sort(u_probs.begin(), u_probs.end(), cmpUsuarioProblemas);

        for (int i = 0; i < N_USUARIOS; ++i) {
            usuario = u_probs[i];

            if (usuario.participa) {
                printf("%d %d %d\n", usuario.id_usuario, usuario.n_prob_res, usuario.n_minutos);
            }

            else break;
        }

        if (n_testes) cout << endl;
    }

    return 0;
}