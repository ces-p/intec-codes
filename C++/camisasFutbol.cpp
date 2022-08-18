//ENUNCIADO DEL PROBLEMA

//Dos amigos juegan en el mismo equipo de fútbol americano. Cada uno de ellos tiene su propio número dorsal marcado en su camiseta. Un dia, su entrenador observa el sorprendente hecho de que el cuadrado de la suma de sus respectivos números es, precisamerrte, el número de cuatro cifras que se ve cuando están el uno junto al otro. Por ejemplo, estos números no pueden ser 17 y 23, dado que (17)^2 + (23)^2 != 1723

//Cuáles pueden ser sus números dorsales?

#include <iostream>
#include <math.h>
using namespace std;

bool numerosDorsales(int numero){
    int sum = 0;
    int temp = numero;
    while(temp != 0){
        sum += pow(temp%100, 2);
        temp /= 100;
    }
    if(sum == numero)
        return true;
    else
        return false;

}

int main(){
    cout<<"Cuáles pueden ser sus números dorsales?"<<endl;
    for(int i = 1000; i < 10000; i++){
        if(numerosDorsales(i))
            cout<<i<<endl;
    }
    return 0;
}