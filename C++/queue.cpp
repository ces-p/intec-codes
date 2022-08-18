// Cola
/*
Enunciado: Realizar un programa C++ que simula con cola con prioridad

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268
Elian Marte 1100103

Fecha: 25/05/2022
*/


#include <iostream>
using namespace ::std;

struct nodo
{
    int dato;
    nodo *next;
} * temp, *temp2, *ultimo;

void agregarNodo(nodo *&stack, int prioridad)
{
    nodo *nuevo = new nodo();
    cout << endl;
    cout << "Inserte un dato: ";
    cin >> nuevo->dato;
    if (stack == NULL)
    {
        stack = nuevo;
        stack->next = NULL;
        ultimo = stack;
        cout << endl;
        cout << "Se ha insertado satisfactoriamente el numero " << nuevo->dato << endl;
    }
    else
    {
        temp = stack;
        temp2 = stack;
        ultimo = stack;
        int j = 0;
        while (ultimo->next != NULL)
        {
            ultimo = ultimo->next;
            j++;
        }
        if (prioridad == 0)
        {
            stack = nuevo;
            stack->next = temp;
        }
        else
        {
            for (int i = 0; i < prioridad; i++)
            {
                temp = temp->next;
                if (i == j || i >= 16)
                {
                    temp = ultimo->next;
                    i = prioridad;
                }
            }
            while (temp2->next != temp && temp2 != temp)
            {
                temp2 = temp2->next;
            }
            temp2->next = nuevo;
            nuevo->next = temp;
        }
        cout << endl;
        cout << "Se ha insertado satisfactoriamente el numero " << nuevo->dato << endl;
    }
}

void show(nodo *&stack)
{
    nodo *aux = new nodo();
    aux = stack;
    if (stack != NULL)
    {
        cout << "Su cola se ve asi: " << endl;
        cout << endl;
        while (aux != NULL)
        {
            cout << aux->dato << " ";
            aux = aux->next;
        }
        cout << endl;
    }
    else
    {
        cout << "La cola se encuentra vacia" << endl;
    }
}

void quitarNodo(nodo *&stack)
{
    nodo *aux = new nodo();
    aux = stack;
    int n;
    if (stack != NULL)
    {
        n = aux->dato;
        stack = aux->next;
        delete aux;
        cout << "Se ha eliminado el numero " << n << endl;
    }
    else
    {
        cout << "La cola se encuentra vacia" << endl;
    }
}

int main(int argc, const char *argv[])
{
    nodo *stack = NULL;
    int opcion;
    do
    {
        cout << "Bienvenido a nuestro programam de cola con prioridad" << endl;
        cout << endl;
        cout << "Que desea hacer? " << endl;
        cout << endl;

        cout << "1.Agregar un nuevo elemento con prioridad" << endl;
        cout << "2.Eliminar un elemento" << endl;
        cout << "3.Mostrar la cola" << endl;
        cout << "4.Salir" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 1:
            cout << "Inserte que prioridad le quiere dar a este elemento: ";
            int prioridad;
            int desicion;
            cin >> prioridad;
            agregarNodo(stack, prioridad);
            cout << endl;
            system("pause");
            break;

        case 2:
            quitarNodo(stack);
            cout << endl;
            system("pause");
            break;

        case 3:
            show(stack);
            cout << endl;
            system("pause");
            break;

        case 4:
            cout << "Se ha finalizado " << endl;
            cout << endl;
            system("pause");
            break;
        default:
            cout << "Opcion invalida" << endl;
            cout << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 4);
}