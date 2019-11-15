/* Problema #10258 - Contest Scoreboard?
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
 */
#include <iostream>
#include <algorithm>
#include <sstream>

#define INV_PENALIDADE 20
#define N_USUARIOS 100
#define N_PROBLEMAS 10

using namespace std;

typedef struct problema {
    int min;
    char status;
    bool resolvido;
} t_prob;

typedef struct usuario_problema {
    int id = -1;
    int n_prob_res = 0;
    int n_min = 0;
    bool participa = false;

    t_prob probs[N_PROBLEMAS]{};
} t_usu_prob;

bool cmpUsuarioProblemas(t_usu_prob u1, t_usu_prob u2) {
    if (u1.participa != u2.participa) return u1.participa > u2.participa;
    if (u1.n_prob_res != u2.n_prob_res) return u1.n_prob_res > u2.n_prob_res;
    if (u1.n_min != u2.n_min) return u1.n_min < u2.n_min;
    return (u1.id < u2.id);
}

int main() {

    int n_testes, id_u, id_p;

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
            stream_linha >> id_u >> id_p >> prob.min >> prob.status;

            if (!u_probs[id_u - 1].probs[id_p - 1].resolvido) {
                u_probs[id_u - 1].participa = true;

                if (prob.status == 'I') {
                    u_probs[id_u - 1].probs[id_p - 1].min += INV_PENALIDADE;
                } else if (prob.status == 'C') {
                    u_probs[id_u - 1].probs[id_p - 1].min += prob.min;
                    u_probs[id_u - 1].probs[id_p - 1].resolvido = true;
                    ++u_probs[id_u - 1].n_prob_res;
                    u_probs[id_u - 1].n_min += u_probs[id_u - 1].probs[id_p - 1].min;
                }
            }
        }

        sort(u_probs, u_probs + N_USUARIOS, cmpUsuarioProblemas);

        for (auto &equipe : u_probs) {
            if (!equipe.participa) break;
            printf("%d %d %d\n", equipe.id, equipe.n_prob_res, equipe.n_min);
        }

        if (n_testes) cout << endl;
    }

    return 0;
}