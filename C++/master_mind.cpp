/*
Enunciado: Programa que resuelve el caso para beginners de Master Mind

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268

Fecha: 15/02/2022
*/

#include <iostream>
using namespace std;

//funcion para revisar si el numero input es valido
bool check_if_num_valid(int num, int array[], int num2, int max_of_arr){
    for(int i = 0; i < max_of_arr; i++){
        if(array[i] == num && num2 != i){
            cout << "No puede repetir numeros" << endl;
            return false;
        }
    }
    if(num < 1 || num > 6 ){
        cout << "El numero debe estar entre 0 y 6" << endl;
        cout << "";
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int clave_oculta[4] = {0,0,0,0}, jugadas[4] = {0,0,0,0}, intentos = 0;
    int max_of_arr = sizeof(clave_oculta)/sizeof(clave_oculta[0]);
    char pistas[max_of_arr];
    int x = 0;
    
    cout << "Bienvenidos a nuestro Master Mind" << endl;
    cout << "";
    cout << "Inserte una clave oculta de " << max_of_arr << " elementos para ser adivinada" << endl;
    cout << "";

//Se plantea la clave
    do {       
        cout << "Introduzca un numero: " << endl;
        cout << "";
        cin >> clave_oculta[x];
        if(clave_oculta[x] == 0){
            cout << "No puede ser 0" << endl;
            cout << "";
            x--;
        }
        else if(check_if_num_valid(clave_oculta[x], clave_oculta, x, max_of_arr) == false){
            x--;
        }
        x++;
    } while (x < max_of_arr);

        
/*
 Muestra la clave oculta para usos de prueba
        cout << "La clave es: " ;
        cout << "";
        for (int x = 0; x < max_of_arr; x++)
        {
            cout << clave_oculta[x]<<endl;
        }
*/
    
         // Se plantea el juego
         for (int z = 0; z < 10; z++)
        {
            intentos++;
            cout<<"";
            cout << "||    ||    INSERTE UN INTENTO   ||   ||" << endl;
            cout << "";
            //El usuario ingresa su intento
            for (int c = 0; c < max_of_arr; c++){
                cout<<"";
                cout << "Introduzca un numero: " << endl;
                cin >> jugadas[c];
                if(check_if_num_valid(jugadas[c], jugadas, c, max_of_arr) == false){
                            c--;
                }
            }
            //Comprobacion entre arrays
            for (int i =0; i < max_of_arr;i++)
            {
                //'X' No esta en el arreglo
                pistas[i]='X';
                for (int j =0; j < max_of_arr;j++)
                {
                        if (jugadas[i]==clave_oculta[j] && (i==j))
                        {
                            //'C' Significa que esta en la misma posicion
                            pistas[i]='C';
                        }
                        else if (jugadas[i]==clave_oculta[j] && (i!=j))
                        {
                            //'F' Significa que esta el numero pero no en la misma posicion
                            pistas[i]='F';
                        }
                }
                    
            }
            cout<<""<<endl;
            cout << "PISTAS: ";
            //Imprime las pistas
            for (int a = 0; a < max_of_arr; a++)
            {
                cout << pistas[a];
            }
            cout<<""<<endl;
            cout<<""<<endl;
            //Revisa si ganaste
            if(pistas[0] == 'C' && pistas[1] == 'C' && pistas[2] == 'C' && pistas[3] == 'C')
                {
                    cout<<"";
                    cout << "Felicidades, has ganado en " << intentos << " intentos" << endl;
                    z = 10;
                }
            else if (intentos == 10)
                {
                    cout<<"";
                    cout << "Lo siento, has perdido" << endl;
                    z = 10;
                }
        }
        return 0;
}