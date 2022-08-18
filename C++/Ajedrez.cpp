/*
Enunciado: Realizar un programa c++ que con dos torres enemigas y una reina,
establezca todas las jugadas posibles, marcando con X donde sí se mueve y puede ser eliminada,
y una V donde puede moverse sin ser eliminada

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268
Elian Marte 1100103


Fecha: 29/06/2022
*/
#include <iostream>
using namespace std;

char tablero[8][8];
int reina_x, reina_y, torre1_x, torre1_y, torre2_x, torre2_y, x, y;

void llenar()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}

void imprimir()
{
    cout << "Tablero:" << endl;
    cout << "  1   2   3   4   5   6   7   8" << endl
         << "---------------------------------" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << '|';
        for (int j = 0; j < 8; j++)
        {
            cout << " " << tablero[i][j] << " |";
        }
        cout << " " << i + 1 << endl
             << "---------------------------------";
        cout << endl;
    }
}

void movimiento(int reina_x, int reina_y)
{
    int mx, my;
    bool paso = true;
    mx = reina_x + x;
    my = reina_y + y;
    if (mx == -1 || mx == 8 || my == -1 || my == 8)
        paso = false;
    else if (mx == torre1_x || mx == torre2_x || my == torre1_y || my == torre2_y)
        tablero[mx][my] = 'X';
    else
        tablero[mx][my] = 'V';

    if (paso == true)
        movimiento(mx, my);
}

int main()
{
    int opcion = 1;
    while (opcion == 1)
    {
        llenar();
        // Almacenar reina
        while (true)
        {
            imprimir();
            cout << "Ingrese la fila de la reina: ";
            cin >> reina_x;
            reina_x -= 1;
            cout << "Ingrese la columna de la reina: ";
            cin >> reina_y;
            reina_y -= 1;
            if (reina_x < 0 || reina_x > 7 || reina_y > 7 || reina_y < 0)
            {
                cout << "Esta fuera del tablero, intente de nuevo." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                tablero[reina_x][reina_y] = 'R';
                system("cls");
                break;
            }
        }

        // Almacenar primera torre
        while (true)
        {
            imprimir();
            cout << "Ingrese fila la primera torre: ";
            cin >> torre1_x;
            torre1_x -= 1;
            cout << "Ingrese la columna la primera torre: ";
            cin >> torre1_y;
            torre1_y -= 1;
            if (torre1_x < 0 || torre1_x > 7 || torre1_y > 7 || torre1_y < 0)
            {
                cout << "Esta fuera del tablero, intente de nuevo." << endl;
                system("pause");
                system("cls");
            }
            else if (tablero[torre1_x][torre1_y] != ' ')
            {
                cout << "Ya la posicion esta ocupada, intente de nuevo." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                tablero[torre1_x][torre1_y] = 'T';
                system("cls");
                break;
            }
        }

        // Almacenar segunda torre
        while (true)
        {
            imprimir();
            cout << "Ingrese la fila de la segunda torre: ";
            cin >> torre2_x;
            torre2_x -= 1;
            cout << "Ingrese la columna la segunda torre: ";
            cin >> torre2_y;
            torre2_y -= 1;
            if (torre2_x < 0 || torre2_x > 7 || torre2_y > 7 || torre2_y < 0)
            {
                cout << "Esta fuera del tablero, intente de nuevo." << endl;
                system("pause");
                system("cls");
            }
            else if (tablero[torre2_x][torre2_y] != ' ')
            {
                cout << "Ya la posicion esta ocupada, intente de nuevo." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                tablero[torre2_x][torre2_y] = 'T';
                system("cls");
                break;
            }
        }

        // Arriba izquierda
        x = -1;
        y = -1;
        movimiento(reina_x, reina_y);

        // Arriba
        x = -1;
        y = 0;
        movimiento(reina_x, reina_y);

        // Arriba derecha
        x = -1;
        y = 1;
        movimiento(reina_x, reina_y);

        // Derecha
        x = 0;
        y = 1;
        movimiento(reina_x, reina_y);

        // Abajo derecha
        x = 1;
        y = 1;
        movimiento(reina_x, reina_y);

        // Abajo
        x = 1;
        y = 0;
        movimiento(reina_x, reina_y);

        // Abajo izquierda
        x = 1;
        y = -1;
        movimiento(reina_x, reina_y);

        // Izquierda
        x = 0;
        y = -1;
        movimiento(reina_x, reina_y);

        imprimir();

        while (true)
        {
            cout << endl
                 << "Desea continuar? (1)Si (0)No ";
            cin >> opcion;
            if (opcion == 0 || opcion == 1)
                break;
            else
            {
                cout << "Las opciones son 0 o 1...\n";
                system("pause");
            }
        }
        system("cls");
    }
    cout << "Gracias!\n";
    system("pause");
}