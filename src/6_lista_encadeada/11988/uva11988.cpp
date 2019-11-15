/* Problema #11988 - Broken Keyboard (a.k.a. Beiju Text)
 * Autores:
 *  Antônio Carlos Durães da Silva
 *  Carlos Guilherme Felismino Pedroni
 *  Lucas Gomes Fleger
 */
#include <iostream>
#include <list>

#define MAX_N_CHAR_LIN 100500

using namespace std;

int main() {
    list<char> lista_char;
    string linha_str;

    /* OTIM: Rserve o tamanho máximo de caracteres para evitar alocações
     * denecesárias a medida que a string aumentar*/
    linha_str.reserve(MAX_N_CHAR_LIN);

    /* Enquanto houver linhas a serem processadas*/
    while (getline(cin, linha_str) and !linha_str.empty()) {

        /* Defina o iterador da lista para o começo dela*/
        auto it = lista_char.begin();

        /* Para cada caractere na string de entrada*/
        for (char letra: linha_str) {

            /* Se o char for 'home', aponte para o início da lista*/
            if (letra == '[') it = lista_char.begin();

            /* Se o char for 'end', aponte para o fim da lista*/
            else if (letra == ']') it = lista_char.end();

            /* Senão, é um caractere legível, insira onde o iterador está
             * apontado (sempre no início ou no fim). IMPORTANTE: A cada
             * inserção, o iterador avança automaticamente*/
            else lista_char.insert(it, letra);
        }

        for (char letra: lista_char) cout << letra;
        cout << endl;
        lista_char.clear();
    }

    return 0;
}