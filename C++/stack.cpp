/*
Enunciado: Crear una estructura de datos Stack

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268
Elian Marte 1100103

Fecha: 24/05/2022
*/

#include <iostream>
#include <stack>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

void Push(NODE *&stack, int n)
{
    NODE *newNode = new NODE();
    newNode->data = n;
    newNode->next = stack;
    stack = newNode;
}
void Pop(NODE *&stack, int n)
{
    NODE *aux = stack;
    n = aux->data;
    stack = aux->next;
    delete aux;
}

void Show(NODE *stack)
{
    NODE *aux = stack;
    while (aux != NULL)
    {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << "" << endl;
}

int main(int argc, const char *argv[])
{
    NODE *stack = NULL;
    int dato;
    int opcion;

    cout << "Este es un programa para demostrar como funciona un pila" << endl;
    cout << "";

    do
    {
        cout << "" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Show" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese un numero: ";
            cin >> dato;
            Push(stack, dato);
            break;
        case 2:
            if(stack == NULL)
            {
                cout << "La pila esta vacia" << endl;
            }
            else
            {
                Pop(stack, dato);
                cout << "El numero eliminado es: " << dato << endl;
            }
            break;
        case 3:
            if(stack == NULL)
            {
                cout << "La pila esta vacia" << endl;
            }
            else
                Show(stack);
            break;
        case 4:
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (opcion != 4);

}