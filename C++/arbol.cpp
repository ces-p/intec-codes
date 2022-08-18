// Arboles
/*
Enunciado: Realizar un programa C++ que permita establecer las operaciones en un árbol binario de búsqueda

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268
Elian Marte 1100103

Fecha: 09/06/2022
*/

#include <iostream>

#include <stdlib.h>
using namespace ::std;

struct Nodo
{
    int dato;
    Nodo *derecha;
    Nodo *izquierda;
    Nodo *padre; // para identificar quien es el padre de cada nodo
};

// Esta función se encarga de crear un nuevo nodo
Nodo *crearNodo(int n, Nodo *padre) // es una función de tipo puntero
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;         // al campo dato en el nuevo nodo se le asigna el valor de n
    nuevo_nodo->derecha = NULL;   // el hijo derecho es nulo por el momento porque es un nodo nuevo y fresco
    nuevo_nodo->izquierda = NULL; // el hijo izquierdo es nulo por el momento porque es un nodo nuevo y fresco
    nuevo_nodo->padre = padre;    // indicar quien es el padre

    return nuevo_nodo;
}

// Esta función se encarga de insertar un nuevo nodo en el arbol
void insertarNodo(Nodo *&arbol, int n, Nodo *padre)
{

    if (arbol == NULL) // Esta condición es por si el arbol está vacío
    {
        Nodo *nuevo_nodo = crearNodo(n, padre); // se crea un nuevo nodo y para esto se llama la función crear nodo
        arbol = nuevo_nodo;                     // se le asigna a arbol el nuevo nodo, por lo que esta sería la raíz
    }
    // Esta condición es por si el arbol ya contiene nodos
    else
    {
        int valor_raiz = arbol->dato; // esto es para buscar el valor de la raíz
        if (n < valor_raiz)
        {
            insertarNodo(arbol->izquierda, n, arbol);
            /*si el numero que queremos insertar es menor que el valor de la raíz,
            entonces el valor se va a insertar por el lado izquierdo llamando a la misma función*/
        }
        else
        {
            insertarNodo(arbol->derecha, n, arbol);
            /*si el numero que queremos insertar es menor que el valor de la raíz,
            entonces el valor se va a insertar por el lado derecho llamando a la misma función*/
        }
    }
}
// Esta funcion es para mostrar un arbol
void mostrarArbol(Nodo *arbol, int contador)
{
    if (arbol == NULL) // si el arbol esta vacio
    {
        return;
    }
    else // si el arbol no esta vacio
    {
        mostrarArbol(arbol->derecha, contador + 1); // se llama a la funcion nuevamente, pero se van imprimiendo los nodos por la derecha
        for (int i = 0; i < contador; i++)          // se usa para dar separacion
        {
            cout << "   "; // espacios de separacion
        }
        cout << arbol->dato << endl;                  // imprimir el elemento de cada nodo
        mostrarArbol(arbol->izquierda, contador + 1); // imprimir toda la parte izquierda del arbol
    }
}

// Esta funcion es para buscar un elemento en el arbol
bool buscarElemento(Nodo *arbol, int n)
{
    if (arbol == NULL) // si no hay elementos en el arbol
    {
        return false;
    }
    else if (arbol->dato == n) // si el nodo del arbol en el que vamos es igual al dato
    {
        return true;
    }
    else if (n < arbol->dato) // si el dato es menor que el nodo en el que vamos
    {
        return buscarElemento(arbol->izquierda, n); // se busca hacia la izquierda, llamando la funcion nuevamente
    }
    else // si el dato es mayor que el nodo en el que vamos
    {
        return buscarElemento(arbol->derecha, n); // se busca havia la derecha, llamando la funcion nuevamente
    }
}
// Esta funcion identifica el menor numero a la izquierda del nodo derecho
Nodo *minimo(Nodo *arbol)
{
    if (arbol == NULL) // identifica si el arbol esta vacio
    {
        return NULL;
    }
    if (arbol->izquierda) // si el arbol tiene hijo a la izquierda
    {
        return minimo(arbol->izquierda); // se llama la funcion nuevamente para encontrar la parte mas izquierda
    }
    else // esto es en caso de que no tenga hijo izquierdo
    {
        return arbol;
    }
}
// Esta funcion es para reemplazar un nodo por el otro
void reemplazar(Nodo *arbol, Nodo *nuevo_nodo) // toma como parametros el arbol y el nuevo nodo por el cual queremos reemplazar
{
    if (arbol->padre) // verifica si el nodo que queremos cambiar tiene padre
    {
        // esto es para identificar si el nodo que queremos cambiar es el hijo izquierdo de su padre

        if (arbol->dato == arbol->padre->izquierda->dato) // si el dato que vamos a cambiar es igual al dato del hijo izquierdo del padre del dato que vamos a cambiar
        {
            arbol->padre->izquierda = nuevo_nodo; // el dato que queremos cambiar va a tomar el valor de su hijo y toma posesion como el hijo izquierdo del padre
        }
        else if (arbol->dato == arbol->padre->derecha->dato) // si el dato que vamos a cambiar es igual al dato del hijo derecho del padre del dato que vamos a cambiar
        {
            arbol->padre->derecha = nuevo_nodo; // el dato que queremos cambiar va a tomar el valor de su hijo y toma posesion como el hijo derecho del padre
        }
    }
    if (nuevo_nodo) // verifica si el nuevo nodo existe
    {
        nuevo_nodo->padre = arbol->padre; // asignarle el nuevo padre al hijo que cambiamos
    }
}
// Esta funcion es para borrar el nodo
void borrar(Nodo *nodo)
{
    nodo->izquierda == NULL;
    nodo->derecha == NULL;

    delete nodo;
}

// Esta funcion es para eliminar hijos, verificar y reemplazar el nodo
void eliminarNodo(Nodo *nodoEliminar)
{
    if (nodoEliminar->izquierda && nodoEliminar->derecha) // si el nodo tiene dos hijos
    {
        Nodo *menor = minimo(nodoEliminar->derecha); // esto es para buscar el nodo a eliminar por su hijo derecho
        nodoEliminar->dato = menor->dato;            // esto es para reemplazar el nodo que queremos borrar con el elemento mas a la izquierda
        eliminarNodo(menor);                         // eliminar el nodo mas a la izquierda del hijo derecho
    }
    else if (nodoEliminar->izquierda) // si el nodo tiene un solo hijo a la izquieda
    {
        reemplazar(nodoEliminar, nodoEliminar->izquierda); // el hijo toma el lugar del padre, llamando a la funcion reemplazar
        borrar(nodoEliminar);
    }
    else if (nodoEliminar->derecha) // si el nodo tiene un solo hijo a la derecha
    {
        reemplazar(nodoEliminar, nodoEliminar->derecha); // el hijo toma el lugar del padre llamando a la funcion reemplazar
        borrar(nodoEliminar);                            // se elimina el hijo que ya tomo posicion como padre, llamando a la funcion destruirNodo
    }
    else // si el nodo no tiene hijos
    {
        reemplazar(nodoEliminar, NULL); // se reemplaza el nodo por null
        borrar(nodoEliminar);           // se elimina el nodo
    }
}

// Esta funcion es para buscar y finalmente eliminar un nodo del arbol
void eliminar(Nodo *&arbol, int n) // esta funcion toma como parámetros el arbol y el elemento a eliminar
{
    if (arbol == NULL) // esto es en dado caso que esté vacío nuestro arbol
    {
        return;
    }
    else if (n < arbol->dato) // si el elemento es menor que el dato en el arbol por donde vamos
    {
        eliminar(arbol->izquierda, n); // esto busca por la izquierda por el hecho que el elemento es menor
    }
    else if (n > arbol->dato) // si el elemento es mayor que el dato en el arbol por donde vamos
    {
        eliminar(arbol->derecha, n); // esto busca por la derecha por el hecho que el elemento es mayor
    }
    else
    {
        eliminarNodo(arbol); // esto llama la función previa para eliminar el nodo cuando se encuentra el valor
    }
}

Nodo *arbol = NULL;

main(int argc, const char *argv[])
{
    int desicion, num, contador = 0;

    cout << "Bienvenidos a nuestro programa de arboles binarios de busqueda" << endl;
    cout << endl;
    cout << "Aqui estan las operaciones que se pueden realizar " << endl;
    cout << endl;

    do
    {
        cout << "1.Insertar un nuevo nodo" << endl;
        cout << "2.Eliminar un nodo" << endl;
        cout << "3.Desplegar el arbol" << endl;
        cout << "4.Buscar un elemento en el arbol" << endl;
        cout << "5.Salir" << endl;

        cout << "Que desea hacer? ";
        cin >> desicion;
        cout << endl;

        switch (desicion)
        {
        case 1:
            cout << "Inserte un numero: ";
            cin >> num;
            insertarNodo(arbol, num, NULL);
            cout << endl;
            cout << "Se ha agregado el numero " << num << " al arbol" << endl;
            cout << endl;
            system("pause");
            break;

        case 2:
            cout << "Inserte el numero a eliminar: ";
            cin >> num;
            eliminar(arbol, num);
            cout << endl;
            system("pause");
            break;

        case 3:
            cout << "Aqui puede ver el arbol completo: " << endl;
            cout << endl;
            mostrarArbol(arbol, contador);
            cout << endl;
            system("pause");
            break;

        case 4:
            cout << "Escriba el numero a buscar: ";
            cin >> num;
            cout << endl;
            if (buscarElemento(arbol, num) == true)
            {
                cout << "El numero " << num << " se encuentra en el arbol" << endl;
                cout << endl;
                cout << "Aqui puede ver donde se encuentra: ";
                cout << endl;
                mostrarArbol(arbol, contador);
            }
            else
            {
                cout << "El numero " << num << " no se encuentra en el arbol" << endl;
                cout << endl;
                cout << "Aqui puede ver que no se encuentra: ";
                cout << endl;
                mostrarArbol(arbol, contador);
            }
            cout << endl;
            system("pause");
            break;

        case 5:
            cout << "Se ha finalizado " << endl;
            cout << endl;
            system("pause");
            break;
        }
        system("cls");

    } while (desicion != 5);
}