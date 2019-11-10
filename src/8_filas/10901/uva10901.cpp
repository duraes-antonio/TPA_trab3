#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 10004
int tempoChegada[MAXN];
int tempoSaida[MAXN];
queue<int> fila[2];

int main()
{
    int c;
    int n, t, m;
    int k;
    string lado;
    cin >> c;
    while ( c-- )
    {
        cin >> n >> t >> m;
        for (int i=0; i<m; i++)
        {//Insere nas filas de seu respectivo lado
            cin >> k >> lado;
            tempoChegada[i] = k;
            if (lado == "left") fila[0].push( i );
            else fila[1].push( i );
        }
        int tempoAtual = 0;
        int ladoAtual = 0;
        while ( !fila[0].empty() || !fila[1].empty() ) //Enquanto estiver carros em alguma das duas filas o loop continua
        {
            int proximo = fila[0].empty() ? tempoChegada[fila[1].front()] :
                       fila[1].empty() ? tempoChegada[fila[0].front()] :
                       min( tempoChegada[fila[0].front()], tempoChegada[fila[1].front()] );
            tempoAtual = max( tempoAtual, proximo );
            int cnt = 0;
            while ( !fila[ladoAtual].empty() && tempoChegada[fila[ladoAtual].front()]<=tempoAtual && cnt<n )
            {
                tempoSaida[ fila[ladoAtual].front() ] = tempoAtual + t;
                cnt++;
                fila[ladoAtual].pop();
            }
            tempoAtual += t; //Adicionar t ao tempoAtual
            ladoAtual = ladoAtual == 0? ladoAtual = 1: ladoAtual = 0; //Altera o lado
        }
        for (int i=0; i<m; i++) cout << tempoSaida[ i ] << endl;
        if (c) cout << endl;
    }   
    return 0;
}