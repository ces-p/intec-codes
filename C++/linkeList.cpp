//Lista Enlazada Simple
/*
 Enunciado: Realizar un programa C++ que simule una lista enlazada simple
 
 Participantes:
 Frederick Fermin Guzman 1100364
 Hamlet Daniel Santana Cruz 1099895
 Cesar Portillo 1100268
 Elian Marte 1100103

 Fecha: 25/05/2022
 */

#include <iostream>
using namespace ::std;

struct nodo{
    int dato;
    nodo* next;
} *primero, *ultimo;

void agregarNodo(){
    nodo* nuevo = new nodo();
    cout << "Añadir dato: ";
    cin >> nuevo->dato;
    nodo* aux = new nodo();
    nodo* anterior = new nodo();
    aux = primero;
    anterior= NULL;

    
    if(primero==NULL)
    {
        primero = nuevo;
        primero -> next = NULL;
        ultimo = nuevo;
        
    }else{

            if (nuevo->dato<aux->dato) {
                primero=nuevo;
                nuevo->next=aux;
            }else{
                while (aux != NULL && nuevo->dato > aux->dato) {
                        anterior = aux;
                        aux = aux -> next;
                }
                if (aux == NULL) {
                    ultimo->next=nuevo;
                    ultimo=nuevo;
                    nuevo->next=NULL;
                }else{
                    anterior->next=nuevo;
                    nuevo->next=aux;
                }

            }
    }
    cout<<"Nodo Ingresado correctamente"<<endl;
}
    



void eliminarNodo(){
    nodo* aux = new nodo();
    aux = primero;
    nodo* anterior = new nodo();
    anterior = NULL;
    bool encontrado = false;
    int buscarDato = 0;
    
    cout<<"Ingrese el dato que desea eliminar de la lista: ";
    cin>> buscarDato;
    if (primero != NULL) {
        while (aux != NULL && encontrado != true) {
            if (aux->dato==buscarDato) { //indica si se encontro el nodo
                if(aux==primero){          //Si se va a borrar el primer elemento
                    primero = primero->next;
                }else if (aux==ultimo){    //Si se borra el ultimo
                    anterior->next = NULL;
                    ultimo = anterior;
                }else{                      //Si se borra numeros entre el primero y el utlimo
                    anterior->next=aux->next;
                }
                cout<<"El elemento fue eliminado con exito"<<endl;
                encontrado = true;
            }
            
            anterior = aux;
            aux = aux -> next;
        }
        
        if (!encontrado) {
            cout<<"El elemento no es parte de la lista"<<endl;
        }
    }else{
        cout<<"La lista esta vacia"<<endl;
    }
}
void buscar(){
    nodo* aux = new nodo();
    aux = primero;
    bool encontrado = false;
    int buscarDato = 0;
    int lugar = 1;
    cout<<"Ingrese el dato que desea buscar de la lista: ";
    cin>> buscarDato;
    if (primero != NULL) {
        while (aux != NULL && encontrado != true) {
            
            if (aux->dato==buscarDato) { //indica si se encontro el nodo
                cout<<"El dato se ha encontrado en la posicion "<<lugar<<endl;
                encontrado=true;
            }
            aux = aux -> next;
            lugar++;
        }
        if (!encontrado) {
            cout<<"El elemento no es parte de la lista"<<endl;
        }
    }else{
        cout<<"La lista esta vacia"<<endl;
    }
}

void show(){
    nodo* aux3 = new nodo();
    aux3 = primero;
    if (primero==NULL) {
        cout<<"La Lista se encuentra vacia"<<endl;
        cout<<""<<endl;
    }else{
        cout<<""<<endl;
        while (aux3!=NULL) {
            cout<<aux3->dato<<endl;
            aux3 = aux3 -> next;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int otroElemento=1;
    int opcion;
    int salir=0;
    
    while (salir!=1) {
        cout<<"-------------------------------------"<<endl;
        cout<<"1.Agregar elemento a la lista"<<endl;
        cout<<"2.Eliminar elemento a la lista"<<endl;
        cout<<"3.Mostrar elementos de la lista"<<endl;
        cout<<"4.Revisar si hay un elemento en la lista"<<endl;
        cout<<"5.Salir"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"Que accion desea Realizar: ";
        cin>>opcion;
        
        switch(opcion)
        {
            case 1:
                agregarNodo();
                cout<<"Desea agregar otro elemento"<<endl;
                cout<<"1.Si"<<endl;
                cout<<"2.No"<<endl;
                cin>>otroElemento;
                while (otroElemento!=1 && otroElemento!=2) {
                    cout<<"Ingrese una opcion valida: ";
                    cin>>otroElemento;
                    cout<<"";
                }
                while (otroElemento==1) {
                agregarNodo();
                cout<<"Desea agregar otro elemento"<<endl;
                cout<<"1.Si"<<endl;
                cout<<"2.No"<<endl;
                cin>>otroElemento;
                    while (otroElemento!=1 && otroElemento!=2) {
                        cout<<"Ingrese una opcion valida: ";
                        cin>>otroElemento;
                        cout<<"";
                    }
                }
            break;
            
            case 2:
                eliminarNodo();
                cout<<"Desea eliminar otro elemento"<<endl;
                cout<<"1.Si"<<endl;
                cout<<"2.No"<<endl;
                cin>>otroElemento;
                while (otroElemento!=1 && otroElemento!=2) {
                    cout<<"Ingrese una opcion valida: ";
                    cin>>otroElemento;
                    cout<<"";
                }
                while (otroElemento==1) {
                eliminarNodo();
                cout<<"Desea Eliminar otro elemento"<<endl;
                cout<<"1.Si"<<endl;
                cout<<"2.No"<<endl;
                cin>>otroElemento;
                    while (otroElemento!=1 && otroElemento!=2) {
                        cout<<"Ingrese una opcion valida: ";
                        cin>>otroElemento;
                        cout<<"";
                    }
                }
            break;
                
            case 3:
                cout<<"Lista: "<<endl;
                show();
            break;
            
            case 4:
                buscar();
            break;
            case 5:
                salir = 1;
            break;
            
            default:
                cout<<"Opcion no valida, volviendo al menu"<<endl;
                cout<<""<<endl;
        }
    }
     
    return 0;
}