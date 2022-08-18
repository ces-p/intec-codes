/*
Enunciado: Realizar un programa c++ que simule un juego de tic-tac-toe.
El jugador va a jugar contra un algoritmo y el algoritmo debe hacer jugadas
donde busca su victoria y intenta evitar su derrota.

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268
Elian Marte 1100103


Fecha: 06/07/2022
*/

#include <iostream>
using namespace std;

// esta matriz es la tabla del juego
char tablero[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

// esta funcion revisa si el jugador gano
bool gano()
{
    if (
        (tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X') ||
        (tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X') ||
        (tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X') ||
        (tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X') ||
        (tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[2][1] == 'X') ||
        (tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X') ||
        (tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X') ||
        (tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X'))
    {
        return true;
    }
    return false;
}

// esta funcion revisa si el algoritmo gano
bool perdio()
{
    if (
        (tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O') ||
        (tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O') ||
        (tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O') ||
        (tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O') ||
        (tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O') ||
        (tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O') ||
        (tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O') ||
        (tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O'))
    {
        return true;
    }
    return false;
}

// esta funcion realiza la jugada del jugador una vez sea su turno.
void jugadaUsuario()
{
    int fila;
    int columna;
    bool paso = false; // esta variable nos ayuda a saber si el jugador ingreso una jugada valida

    while (!paso)
    {
        while (true)
        {
            cout << "Ingrese la fila: ";
            cin >> fila;
            if (!cin.fail() && fila <= 3 && fila >= 1)
                break;
            else
            {
                cout << "Solo se aceptan numeros del 1 al 3  \n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        while (true)
        {
            cout << "Ingrese la columna: ";
            cin >> columna;
            if (!cin.fail() && columna <= 3 && columna >= 1)
                break;
            else
            {
                cout << "Solo se aceptan numeros del 1 al 3  \n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        if (tablero[fila - 1][columna - 1] == 'X' || tablero[fila - 1][columna - 1] == 'O')
        { // si la jugada ya fue hecha
            cout << "Casilla ocupada" << endl;
            continue;
        }
        paso = true;
    }
    tablero[fila - 1][columna - 1] = 'X';
}

// esta funcion realiza la jugada del algoritmo una vez sea su turno.
void jugadaCPU()
{
    int fila;
    int columna;
    bool paso = false; // esta variable nos ayuda a saber si el algoritmo ingreso una jugada
                       // en donde asegura su victoria o evita su derrota

    for (int i = 0; i < 3; i++)
    { // este for anulado busca una jugada en donde asegura su victoria
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O')
            {                        // si la casilla esta vacia
                tablero[i][j] = 'O'; // corre un simulacro en donde el algoritmo juega en esa posicion
                if (perdio())
                { // va a probar si con esta jugada gana el algoritmo
                    paso = true;
                    break;
                }
                tablero[i][j] = ' '; // si no gana, la casilla se vuelve a poner vacia
            }
        }
        if (paso)
        {
            break;
        }
    }
    if (!paso)
    { // si el algoritmo no encontro una jugada en donde asegura su victoria
        for (int i = 0; i < 3; i++)
        { // este for anulado busca una jugada en donde evita su derrota
            for (int j = 0; j < 3; j++)
            {
                if (tablero[i][j] != 'X' && tablero[i][j] != 'O')
                {
                    tablero[i][j] = 'X'; // corre un simulacro en donde el jugador juega en esa posicion
                    if (gano())
                    { // va a probar si con esta jugada el algoritmo pierde
                        tablero[i][j] = 'O';
                        paso = true;
                        break;
                    }
                    tablero[i][j] = ' '; // si no pierde, la casilla se vuelve a poner vacia
                }
            }
            if (paso)
            {
                break;
            }
        }
    }

    while (!paso)
    {                         // si no se encontro una jugada en donde asegura su victoria o evita su derrota
        fila = rand() % 3;    // selecciona una fila aleatoria
        columna = rand() % 3; // selecciona una columna aleatoria
        if (tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O')
        {                                 // revisa si la casilla esta vacia
            tablero[fila][columna] = 'O'; // si esta vacia, la pone en O
            paso = true;
        }
    }
}

// esta funcion imprime el tablero
void showTablero()
{
    cout << "Tablero:" << endl;
    cout << "  1   2   3" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << '|';
        for (int j = 0; j < 3; j++)
        {
            cout << " " << tablero[i][j] << " |";
        }
        cout << " " << i + 1 << endl;
        cout << "---------------------------------";
        cout << endl;
    }
}

int main()
{
    int jugadas = 0;
    cout << "Bienvenido al juego de Tic Tac Toe" << endl;
    showTablero();
    while (!gano() && !perdio())
    {                    // mientras no gane ni pierda
        jugadaUsuario(); // el jugador siempre juega primero
        jugadas++;
        showTablero();
        if (gano())
        {
            cout << "Ganaste!" << endl;
            break;
        }
        if (jugadas == 9)
        {
            cout << "Empataste!" << endl;
            break;
        }
        else
        {
            jugadaCPU();
            jugadas++;
            showTablero();
            if (perdio())
            {
                cout << "Perdiste!" << endl;
                break;
            }
        }
        if (jugadas == 9)
        {
            cout << "Empataste!" << endl;
            break;
        }
    }
    return 0;
}