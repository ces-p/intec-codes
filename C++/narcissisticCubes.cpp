#include  <iostream>
using namespace std;
#include <math.h>

//narcissitic cubes
/*
Enunciado: hacer un programa que imprima los cubos narcisistas en el rango 100-999
Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268

Fecha: 23/02/2022
*/

bool narcissisticCubes(int n){
    int sum = 0;
    int temp = n;
    while(temp != 0){
        sum += pow(temp%10, 3);
        temp /= 10;
    }
    if(sum == n)
        return true;
    else
        return false;
}

int main(){
    for(int i = 100; i < 1000; i++){
        if(narcissisticCubes(i))
            cout << i << endl;
    }
    return 0;

}