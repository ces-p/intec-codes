//ENUNCIADO DEL PROBLEMA
//- Hace algún tiempo Salvador compró 100 florero, para venderlos en un mercadillo. La semana pasada, después de haber vendido algunos de ellos en los dias anteriores, tenia los floreros ordenados en 6 filas, con el mismo número de unidades en cada una de ellas. En esa semana vendió 8 floreros y en la actualidad tiene los que le quedan, ordenados en 11 filas, con el mismo número de floreros en cada una.
//Cuántos floreros tiene Salvador para vender todavia?

#include <iostream>
using namespace std;

void numFlores()
{
    int flores = 0;
    int multiplesOF6[] = {6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90, 96};
    int mutiplesOF11[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    
    //what multiple of 6 when subtracted 8 is a multiple of 11?
    for (int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(multiplesOF6[i] - 8 == mutiplesOF11[j])
            {
                flores = mutiplesOF11[j];
                cout<<"El numero de floreros restantes puede ser : "<<flores<<endl;
            }
        }
    }
    

}

int main(){
    cout<< "Hace algún tiempo Salvador compró 100 florero, para venderlos en un mercadillo. La semana pasada, después de haber vendido algunos de ellos en los dias anteriores, tenia los floreros ordenados en 6 filas, con el mismo número de unidades en cada una de ellas. En esa semana vendió 8 floreros y en la actualidad tiene los que le quedan, ordenados en 11 filas, con el mismo número de floreros en cada una. Cuántos floreros tiene Salvador para vender todavia?"<<endl;
    numFlores();
    return 0;

}