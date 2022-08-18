/*
Enunciado: Programa que resuelve el caso para beginners de Master Mind

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Elian Marte 1100103
Cesar Portillo 1100268

Fecha: 19/05/2022
*/

#include <iostream>
#include <typeinfo>
using namespace std;

int main(int argc, const char *argv[])
{
    //clave_oculta es la clave secreta que se creara por un usuario
    //jugadas es el intento que algun otro usuario va a hacer para adivinar la clave oculta
    //intentos es el numero de intentos que el usuario ha hecho para adivinar la clave oculta
    //pistas es una pista que se le da al usuario en cada intento para ayudarlo a adivinar la clave oculta
    int clave_oculta[4], jugadas[4], intentos;
    char pistas[4];

    cout << "Bienvenidos a nuestro Master Mind" << endl;
    cout << endl;
    cout << "Inserte una clave oculta para ser adivinada" << endl;
    cout << endl;

    // Se plantea la clave
    for (int x = 0; x < 4; x++)
    {
        cout << "Introduzca un numero: " << endl;
        cin >> clave_oculta[x];
        if (clave_oculta[x] < 1 || clave_oculta[x] > 6)
        {
            cout << "El numero debe estar entre 1 y 6" << endl;
            cout << endl;
            x--;
        }
        for (int y = 0; y < x; y++)
        {
            if (clave_oculta[x] == clave_oculta[y])
            {
                cout << "El numero no debe repetirse" << endl;
                cout << endl;
                x--;
                break;
            }
        }
    }

    /*
    cout << "La clave es: ";
    cout << "";
    for (int x = 0; x < 4; x++)
    {
        cout << clave_oculta[x];
    }
    cout << endl;
    */

    intentos = 0;

    for (int z = 0; z < 10; z++)
    {
        intentos++;
        cout << endl;
        cout << "INSERTE UN INTENTO " << endl;
        cout << endl;
        // El usuario ingresa su intento
        for (int c = 0; c < 4; c++)
        {
            cout << "";
            cout << "Introduzca un numero: " << endl;
            cin >> jugadas[c];
            if (jugadas[c] < 1 || jugadas[c] > 6)
            {
                cout << "El numero debe estar entre 1 y 6" << endl;
                cout << "";
                c--;
            }
            for (int n = 0; n < c; n++)
            {
                if (jugadas[c] == jugadas[n])
                {
                    cout << "El numero no debe repetirse" << endl;
                    cout << endl;
                    c--;

                    break;
                }
            }
        }
        cout << endl;
        cout << "Su Intento Fue: ";
        cout << "";
        for (int m = 0; m < 4; m++)
        {
            cout << jugadas[m];
        }
        cout << endl;
        // Comprobacion entre arrays
        for (int i = 0; i < 4; i++)
        {
            //'X' No esta en el arreglo
            pistas[i] = 'X';
            for (int j = 0; j < 4; j++)
            {
                if (jugadas[i] == clave_oculta[j] && (i == j))
                {
                    //'C' Significa que esta en la misma posicion
                    pistas[i] = 'C';
                }
                else if (jugadas[i] == clave_oculta[j] && (i != j))
                {
                    //'F' Significa que esta el numero pero no en la misma posicion
                    pistas[i] = 'F';
                }
            }
        }
        cout << endl;

        cout << "Resultado: ";
        // Imprime las pistas
        for (int a = 0; a < 4; a++)
        {
            cout << pistas[a];
        }

        cout << endl;
        // Revisa si ganaste
        if (pistas[0] == 'C' && pistas[1] == 'C' && pistas[2] == 'C' && pistas[3] == 'C')
        {
            cout << endl;
            cout << "Felicidades, has ganado en " << intentos << " intentos" << endl;
            cout << endl;
            z = 10;
        }
        else if (intentos == 10)
        {
            cout << endl;
            cout << "Lo siento, has perdido" << endl;
            z = 10;
        }
    }
    return 0;
}