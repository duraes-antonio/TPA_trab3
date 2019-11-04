#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;

const bool Contem( std::vector<int>& Vec, const int& Element ) 
{
    if (std::find(Vec.begin(), Vec.end(), Element) != Vec.end())
        return true;
    return false;
}
int main() {
    vector <int> princesa(3);
  	vector <int> princepe(2);
    int a, b, c, x, y;
    int saida;
    while(cin >> a >> b >> c >> x >> y, a) {
        princesa.clear();
        princepe.clear();
        saida = 53;
        princesa.push_back(a);
    	princesa.push_back(b);
    	princesa.push_back(c);
    	princepe.push_back(x);
    	princepe.push_back(y);  
    	sort(princesa.begin(),princesa.end());  //ordena os valores
    	sort(princepe.begin(),princepe.end());  //ordena os valores
        std::vector<int> todaEntrada(princesa);
        todaEntrada.insert(todaEntrada.end(), princepe.begin(), princepe.end()); //Adiciona todas as entradas em um vetor
        if(princepe[0] > princesa[2]){  //verifica se todas as cartas do principe são maiores do que as da princesa
            for (int i = 1; i <= 52 && i < saida; ++i)
                if(!Contem(todaEntrada, i))
                    saida = i;
        }
        if(princepe[1] > princesa[2]){ // verifica se a maior carta do principe é maior que todas da princesa
             for (int i = princesa[2] + 1; i <= 52 && i <saida; ++i)
                if (!Contem(todaEntrada, i))
                    saida = i;     
        }
        if(princepe[0] > princesa[1]){ // verifica se o primeiro do principe é maior do que duas cartas da princesa
            for (int i = princesa[1] + 1; i <= 52 && i < saida; ++i)
                if (!Contem(todaEntrada, i))
                    saida = i;
        }
        if(saida == 53){
            saida = -1;
        }
        cout << saida << '\n';
    }
}