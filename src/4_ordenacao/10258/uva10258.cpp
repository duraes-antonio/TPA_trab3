/* Problema #10258 - Contest Scoreboard?
 * Autor: Antônio Carlos Durães da Silva
 */
#include <iostream>
#include <algorithm>
#include <sstream>

#define INV_PENALIDADE 20
#define N_USUARIOS 100
#define N_PROBLEMAS 10


using namespace std;

typedef struct problema {
    int minutos;
    char status;
    bool resolvido;
} t_prob;

typedef struct usuario_problema {
    int id = -1;
    int n_prob_res = 0;
    int n_minutos = 0;
    bool participa = false;

    t_prob probs[N_PROBLEMAS]{};
} t_usu_prob ;

bool cmpUsuarioProblemas(usuario_problema u1, usuario_problema u2) {

    if (u1.participa != u2.participa)
        return u1.participa > u2.participa;

    if (u1.n_prob_res != u2.n_prob_res)
        return u1.n_prob_res > u2.n_prob_res;

    if (u1.n_minutos != u2.n_minutos)
        return u1.n_minutos < u2.n_minutos;

    return (u1.id < u2.id);
}

int main() {

    int n_testes, id_usu, id_prob;

    t_usu_prob u_probs[N_USUARIOS];
    string limbo;

    t_prob prob;

    /*Leia o número de testes*/
    cin >> n_testes;
    getline(cin, limbo);
    getline(cin, limbo);

    while (n_testes--) {

        for (int i = 0; i < N_USUARIOS; ++i) {
            t_usu_prob temp_usuario;
            temp_usuario.id = i + 1;
            u_probs[i] = temp_usuario;
        }

        while (getline(cin, limbo), !limbo.empty()) {
            stringstream stream_linha(limbo);
            stream_linha >> id_usu >> id_prob >> prob.minutos >> prob.status;

            if (!u_probs[id_usu - 1].probs[id_prob - 1].resolvido) {
                u_probs[id_usu - 1].participa = true;

                if (prob.status == 'I') {
                    u_probs[id_usu - 1].probs[id_prob - 1].minutos += INV_PENALIDADE;
                }

                else if (prob.status == 'C') {
                    u_probs[id_usu - 1].probs[id_prob - 1].minutos += prob.minutos;
                    u_probs[id_usu - 1].probs[id_prob - 1].resolvido = true;
                    ++u_probs[id_usu - 1].n_prob_res;
                    u_probs[id_usu - 1].n_minutos += u_probs[id_usu - 1].probs[id_prob - 1].minutos;
                }
            }
        }

        sort(u_probs, u_probs + N_USUARIOS, cmpUsuarioProblemas);

        for (int i = 0; i < N_USUARIOS; ++i) {

            if (u_probs[i].participa) {
                printf("%d %d %d\n", u_probs[i].id, u_probs[i].n_prob_res, u_probs[i].n_minutos);
            }

            else break;
        }

        if (n_testes) cout << endl;
    }

    return 0;
}