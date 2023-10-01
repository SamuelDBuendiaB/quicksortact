#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <ctime>
using namespace std;


int div(int x[], int inicio, int final){

    //Elemento mas a la derecha elejido
    int pivote = x[final];
    //elementos menores van a la izquierda
    //elementos mas grandes van a la derecha
    int cent = inicio;
    // si numero es menor se movera a la izquieda y se mueve el pivote 1 posicion
    for (int i = inicio; i < final; i++)
    {
        if (x[i] <= pivote)
        {
            swap(x[i],x[cent]);
            cent++;
        }
        
    }
    
    swap(x[cent],x[final]);
    return cent;

}

void quick(int x[], int inicio, int final){

    if (inicio >= final)
    {
        return;
    }
    //Reorganizacion de los elementos
    int pivote = div(x,inicio,final);
    //Recorre un arreglo con elementos menores al pivote
    quick(x,inicio,pivote -1);
    //Recorre un arreglo con elementos mayores
    quick(x, pivote +1, final);

}

int main ()
{
    int tam = 20; //cantidad de numeros random
    int x[tam]; 

    // darle a srand una forma de generar numeros mas random con el tiempo
    srand(static_cast<unsigned int>(time(0)));

    // generar numeros
    for (int i = 0; i < tam; ++i) {
        x[i] = rand() % 100; 
    }
     for (int i = 0; i < tam; ++i) {
        cout << x[i] << " ";
    }
    int n = sizeof(x)/sizeof(x[0]);

    //arreglo desordenado
    cout<<"Arreglo Desorganiado"<<endl;
    cout<<" "<<x<<endl;
    //Arreglo organizado
    quick(x, 0, n-1);
  cout<<"Arreglo Organiado"<<endl;
    for (int i = 0; i < n; i++)
    {
       cout<<" "<< x[i];
    }
    return 0 ;
}