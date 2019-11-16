/* Problema #11926 - Multitasking
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
 */
#include <iostream>
#include <bitset>

#define MAX_INT 1000001

using namespace std;

int main() {

    int n, m, i, k;
    bool conflitou;
    int t_ini, t_fim, t_interv;
    bitset<MAX_INT> min_ocups;

    // Enquanto houver tarefas a serem lidas (únicas ou cíclicas)
    while (cin >> n >> m and (n > 0 or m > 0)) {

        conflitou = false;

        // Leia as tarefas executadas apenas uma vez
        for (i = 0; !conflitou and i < n; ++i) {
            cin >> t_ini >> t_fim;

            /* Há conflito se o início da tarefa atual colidir com a execução
             * de outra tarefa. Se o início da tarefa atual colidir com o minuto
             * de TÉRMINO de outra tarefa NÃO há conflito.*/

            /* Enquanto não houver conflito, tente marcar os minutos da
             * tarefa atual como ocupados */
            while (t_ini < t_fim) {

                // Se o minuto atual estiver ocupado, as tarefas conflitaram
                if(min_ocups[t_ini]) {
                    conflitou = true;
                    break;
                }

                else min_ocups.set(t_ini++);
            }
        }

        // Se conflitou, leia os dados restantes para evitar problema de entrada
        for (; i < n; ++i) cin >> t_ini >> t_fim;

        // Leia as tarefas cíclicas, executadas a cada x intervalo
        for (i = 0; i < m and !conflitou; ++i) {
            cin >> t_ini >> t_fim >> t_interv;

            /* Para cada execução de cada tarefa repetitiva*/
            for (int j = 0; !conflitou and (t_ini + j) < MAX_INT; j += t_interv) {

                /* Marque todos os minutos do início dessa execução dessa
                 * tarefa até o último minuto da execução */
                k = t_ini + j;

                while (k < (t_fim + j) and k < MAX_INT) {

                    // Se o minuto atual estiver ocupado, tarefas conflitaram
                    if (min_ocups[k]) {
                        conflitou = true;
                        break;
                    }

                    else min_ocups.set(k++);
                }
            }
        }

        // Se conflitou, leia os dados restantes para evitar problema de entrada
        for (; i < m; ++i) cin >> t_ini >> t_fim >> t_interv;

        cout << (conflitou ? "CONFLICT\n" : "NO CONFLICT\n");
        min_ocups.reset();
    }

    return 0;
}