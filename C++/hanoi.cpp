#include <iostream>

using namespace std;

struct Stack
{
    int data;
    Stack *next;
};
void Show(Stack *stack)
{
    Stack *aux = stack;
    while (aux != NULL)
    {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << "" << endl;
}
void Push(Stack *&stack, int n)
{
    Stack *newNode = new Stack();
    newNode->data = n;
    newNode->next = stack;
    stack = newNode;
    
}
int topNumInStack(Stack *stack){
    return stack->data;
}

//deletes the top number in the stack
void Pop(Stack *&stack)
{
    Stack *aux = stack;
    stack = aux->next;
    delete aux;
    
}



 
//solve the tower of hanoi puzzle and display the steps it took
void hanoi(int n, Stack *&A, Stack *&B, Stack *&C, int &pasos)
{
   if(n == 1){
        Push(C, topNumInStack(A));
        Pop(A);
        pasos++;
        cout << "Torre 1: ";
        Show(A);
        cout << "Torre 2: ";
        Show(B);
        cout << "Torre 3: ";
        Show(C);
        cout << "" << endl;

   }
   else{
        hanoi(n-1, A, C, B, pasos);
        Push(C, topNumInStack(A));
        Pop(A);
        pasos++;
        cout << "Torre 1: ";
        Show(A);
        cout << "Torre 2: ";
        Show(C);
        cout << "Torre 3: ";
        Show(B);
        cout << "" << endl;
        
        hanoi(n-1, B, A, C, pasos); 
   } 
}

    
 

int main()
{
    cout << "Este programa muestra la solucion del juego de las torres de hanoi paso por paso" << endl;
    Stack *A = NULL; //torre 1
    Stack *B = NULL; //torre 2
    Stack *C = NULL; //torre 3
   
    int pasos = 0;
    int n = 0;
    cout << "Inserte numero de discos: ";
    cin >> n;
    for(int i = n; i > 0; i--)
    {
        Push(A, i);
    }
    
    cout << "Torre 1: ";
    Show(A);
    cout << "Torre 2: ";
    Show(B);
    cout << "Torre 3: ";
    Show(C);
    cout << "" << endl;

    hanoi(n, A, B, C, pasos);
    cout << "Pasos: " << pasos << endl;
    
    return 0;
}

#include <iostream>

using namespace std;

// solve the tower of hanoi puzzle and display the steps it took
void Torres_Hanoi(int n, int torre1, int torre3, char torre2, int &pasos)
{

    if (n == 1)
    {
        cout << "Mueve disco 1 de torre " << torre1 << " a torre " << torre3 << endl;
        pasos++;
    }
    else
    {
        Torres_Hanoi(n - 1, torre1, torre2, torre3, pasos);
        cout << "Mueve disco " << n << " de torre " << torre1 << " a torre " << torre3 << endl;
        pasos++;
        Torres_Hanoi(n - 1, torre2, torre3, torre1, pasos);
    }
}

int main()
{
    int n, torreA = 1, torreB = 2, torreC = 3, contador = 0;
    cout << "Bienvenidos a nuestras torres de Hanoi" << endl;
    cout << endl;
    cout << "Cuantos discos utilizara? ";
    cin >> n;
    cout << endl;
    Torres_Hanoi(n, torreA, torreC, torreB, contador);
    cout << endl;
    cout << "Se ha completado el recorrido en " << contador << " pasos en total" << endl;
    return 0;
}