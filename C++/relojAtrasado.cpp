/*
Enunciado: Crear prograna que te diga cuantos minutos pierde el reloj en 24 horas dada la siguiente ecuacion 
Tiempo: n 
f(n) -> el numero en la secuecnia fibonacci que se encuentra en la posicion n
Timpo perdido: f(n)/2^n

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268

Fecha: 16/03/2022
*/
#include <iostream>
#include <cmath>
using namespace std;

double fibonacci(int n){
    if(n<3) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    double sum = 0;
    int n = 24;
    for(int i=1;i<=n;i++){
        sum += fibonacci(i)/(pow(2,i));
    }
    cout << "" << endl;
    cout<< "Este programa le va a decir cuanto tiempo pierde el reloj en " << n << " horas utilizando la ecuacion f(n) / 2^n donde n es el tiempo en horas y f(n) el numero de la secuencia fibonacci que se encuentra en la posicion n." << endl;
    cout << "" << endl;
    cout << "El reloj estara atrasado por " << sum << " minutos o " << sum*60 << " segundos en " << n << " horas" << endl;
}