//ENUNCIADO DEL PROBTEMA

//Multiplicando los digitos de un número entero y continuando el proceso, nos encontramos con el sorprendente resultado de que la secuencia de productos llega siempre a un número de un solo dígito. Por ejemplo:
//715 -> 35 -> 15 -> 5
//88  -> 64 -> 24 -> 8
//27 -> 14-> 4

//Al número de productos necesarios para alcanzar un solo dígito se le llama persistencia de ese número entero. Es decir, 715 y 88 tienen persistencia 3, mientras que 27 tiene persistencia 2.

//Cuál es el único número entero de sólo dos digitos cuyo número persistente es mayor que 3?

#include <iostream>
using namespace std;

int Persist( int value )
{
    int count = 0;  
    while( value > 9 ) 
    {
        int temp = 1;
        do
        {
            temp *= (value % 10); 
            value /= 10;    
        } while(value > 0); 
            value = temp; 
            ++count;
    }
    return count;
}

int main(){
    for (int i = 10; i < 100; i++)
    {
        if(Persist(i) > 3)
        {
            cout<<i<<" es el único número entero de sólo dos digitos cuyo número persistente es mayor que 3" <<endl;
            break;
        }
    }
    return 0;
}