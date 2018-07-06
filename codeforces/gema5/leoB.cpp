#include <iostream>
using namespace std;

int n, x;
int v[10000];

int counting(){
    int aux;
    int counter=0;
    for (int i = n-1; i >= 0; i--){ // i percorre da ultima posicao até a primeira
        aux = v[i];                 // aux é a posição atual
        int j = i - 1;              // i começa na posição anterior ao aux
        while(aux < x && j>=0){     // enquanto aux for menor que o target, e j estiver dentro do array
            if (aux + v[j] > x){    // se a soma de aux com o valor d aposição j for > x, anda com J
                j--;
            }else{                  // se a posição for menor ou igual, soma em aux e anda com j
                aux = aux + v[j];
                j--;
            }
        }
        if (aux == x){              
            counter++;
        }
    }

    return counter;
}


int main(){
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << counting() << endl;
}