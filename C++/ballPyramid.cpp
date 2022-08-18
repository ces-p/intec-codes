//ENUNCIADO DEL PROBLEMA
//Con un grupo de 10,000 bolas se forma una pirimide de base cuadrada, con una única bola en su vértice superior y un número cuadrado perfecto de ellas en cada capa.
//Cuántas capas pueden hacerse? Y cuántas bolas sobrarán?

#include <iostream>
using namespace std;

void capasTotal(){
    int bolas = 10000;
    int base = 0;
    int capas = 0;
    int sobras = 0;
    for(int i = 1; i < 100; i++){
        if(bolas < base){
            sobras = bolas;
            cout<<"El numero de capas es: "<<capas<<endl;
            cout<<"El numero de bolas sobrantes es: "<<sobras<<endl;
            break;
        }
        base = i*i;
        capas ++;
        bolas = bolas - base;
    }
    
}

int main(){
    cout<<"Con un grupo de 10,000 bolas se forma una pirimide de base cuadrada, con una única bola en su vértice superior y un número cuadrado perfecto de ellas en cada capa.\nCuántas capas pueden hacerse? Y cuántas bolas sobrarán?"<<endl;
    capasTotal();
    return 0;
}