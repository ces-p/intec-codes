//Enunciado: En una fiesta hay 99 personas. A cada una de ellas se le ha dado un numero
//entero comprendedo entre 1 y 99 acompañado de unas instrucciones. Las instrucciones dicen:
//A) si su numero es par, dividelo por 2
//B) si su numero es impar, multiplicalo por 3 y sumale 1
//C) repita las instrucciones anteriores con el numero que resulte hasta que sea igual a 4
//Encuentre al invitado que tenga la cadena mas larga.

/*
Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268
Elian Marte 1100103

Fecha: 18/05/2022
*/

#include <iostream>
#include <math.h>
using namespace std;

//number es el numero que se le asigna a cada persona
//counter es el numero que se va a ir sumando en cada iteracion para encontrar la longitud de la cadena de ese numero
int func(int number, int counter){
    if(number == 4){
        //si el numero es igual a 4, se rompe el ciclo y se retorna counter que sera la longitud de la cadena
        return counter;
    }else if(number % 2 == 0){
        //si el numero es par, se divide por 2 y se suma 1 al contador y se llama recursivamente a la funcion
        return func(number/2, counter+1); 
    }else{
        //si el numero es impar, se multiplica por 3 y se suma 1 y al contador tambien se suma 1 y se llama recursivamente a la funcion
        return func((number*3)+1, counter+1);
    }
}

//Show muestra la cadena de forma visual. Es la funcion func pero con una forma de mostrar los numeros en la cadena con cada ciclo
void Show(int number){
    if(number == 4){
        cout<< "4" << endl;
    }else if(number % 2 == 0){
        //el if else anidado es para quitar la "-> " una vez que se haya llegado al numero 4 porque 4 no va a apuntar a nada
        if(number/2 == 4){
            cout<< "4" << endl;
        }
        else{
        cout << number/2 << "-> ";
        Show(number/2);
        }
    }else{
        //el if else anidado es para quitar la "-> " una vez que se haya llegado al numero 4 porque 4 no va a apuntar a nada
        if((number*3)+1 == 4){
            cout<< "4" << endl;
        }
        else{
        cout << number*3+1 << "-> ";
        Show((number*3)+1);
        }
    }
}

int main(){
    //currentChain es la longitud de la cadena del numero actual en la iteracion (i)
    int currentChain = 0;
    //maxChain es la longitud de la cadena mas larga hasta el momento y finalmente sera la longitud de la cadena mas larga entre todas las cadenas de 1 a 99
    int maxChain = 0;
    //maxNumber es el numero que tiene la cadena mas larga hasta el momento y finalmente sera el numero que tiene la cadena mas larga entre todas las cadenas de 1 a 99
    int maxNumber = 1;

    cout << "Este programa analiza cual es el invitado del 1 al 99 que tiene la cadena mas larga" << endl;
    cout << endl;

    //Se hace un ciclo para analizar cada numero del 1 al 99
    for(int i = 1; i < 100; i++){
        //Se llama a la funcion func para obtener la longitud de la cadena del numero actual
        currentChain = func(i, 0);
        //Si la longitud de la cadena del numero actual es mayor que la longitud de la cadena mas larga hasta el momento, se actualiza la longitud de la cadena mas larga 
        if(currentChain > maxChain){
            maxNumber = i;
            maxChain = currentChain;
        }
    }

    //este pedazo muestra todas las cadenas de cada numero del 1 al 99

    /*for (int i = 1; i < 100; i++)
    {
        currentChain = func(i, 0);
        cout << "El invitado actual es " << i << " y su cadena es: " << currentChain << endl;
        if (currentChain > maxChain)
        {
            maxNumber = i;
            maxChain = currentChain;
        }
    }
    */

    cout << "El invitado que tiene la cadena mas larga es el numero: " << maxNumber << " y su cadena es de: " << maxChain << endl;
    //se llama a la funcion Show para mostrar la cadena de forma visual
    cout << "La cadena es: " << maxNumber << "-> ";
    Show(maxNumber);
    return 0;
}