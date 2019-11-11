/* Problema #10172 - The Lonesome Cargo Distributor
 * Autor: Lucas Gomes Flegler
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n, s, q, casos;

    cin >> casos;

    for (; casos > 0; casos--)
    {
        // pilha e fila da transportadora e da estacao.
        queue<int> filaEstacao[100];
        stack<int> transportadora;

        cin >> n >> s >> q;

        for (int i = 0; i < n; i++)
        {
            int ncargas;
            cin >> ncargas;
            for (int j = 0; j < ncargas; j++)
            {
                int target;
                cin >> target;
                filaEstacao[i].push(target - 1);
            }
        }

        int pos = 0, tempo = 0;
        while (true)
        {
            // enquanto existir carga na transportadora, eh feito a descarga e 
            // adicionando a carga na fila da estacao.
            while (!transportadora.empty() && (transportadora.top() == pos || filaEstacao[pos].size() < q))
            {
                if (transportadora.top() != pos)
                {
                    filaEstacao[pos].push(transportadora.top());
                }
                transportadora.pop();
                tempo++;
            }

            // colcando a carga na transportadora e retirando da fila da estacao.
            while ((transportadora.size() < s) && !filaEstacao[pos].empty())
            {
                transportadora.push(filaEstacao[pos].front());
                filaEstacao[pos].pop();
                tempo++;
            }
            
            // verificando se a tranportadora esta vazia
            bool clear = transportadora.empty();
            for (int i = 0; i < n; i++)
            {
                clear &= filaEstacao[i].empty();
            }
            if (clear)
                break;
            
            pos = (pos + 1) % n;
            tempo += 2;
        }

        cout << tempo << endl;
    }

    return 0;
}
