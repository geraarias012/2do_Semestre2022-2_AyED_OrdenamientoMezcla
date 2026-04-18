#include <iostream>
#include <stdlib.h>
#define max 5
using namespace std;

class ordenamiento
{
private:
    int datos[max];
public:
    void llenado();
    void mostrar(string);
    void mezcla_sort(int,int);
    void mezcla(int, int,int);
    ordenamiento();
    ~ordenamiento();
};
ordenamiento::ordenamiento(){}
ordenamiento::~ordenamiento(){}
void ordenamiento::llenado(){
    int dato;
    for(int i=0;i<=max;i++){
        cout<<"igrese el numero ["<<i<<"]: ";
        cin>>dato;
        datos[i]=dato;
    }
}
void ordenamiento::mostrar(string estado){
    cout<<"los valores "<<estado<<" del arrego son:{";
    for(int i=0;i<max;i++){
        cout<<datos[i]<<", ";
    }
    cout<<datos[max]<<"}"<<endl;
}


void ordenamiento::mezcla_sort(int izquierda,int derecha)
{
    int medio;
    if(izquierda<derecha){
        medio=(izquierda+derecha)/2;
        mezcla_sort(izquierda,medio);
        mezcla_sort(medio+1,derecha);
        mezcla(izquierda,medio,derecha);
    }
}
void ordenamiento::mezcla(int izquierda,int medio,int derecha)
{
    int h,i,j,k,datosAux[max];
    h=izquierda;
    i=izquierda;
    j=medio+1;
    while( (h<=medio) && (j<=derecha) )
    {
        if(datos[h]<=datos[j])
        {
            datosAux[i]=datos[h];
            h++;
        }
        else
        {
            datosAux[i]=datos[j];
            j++;
        }
        i++;
    }
    if(h>medio)
    {
        for(k=j;k<=derecha;k++)
        {
            datosAux[i]=datos[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=medio;k++)
        {
            datosAux[i]=datos[k];
            i++;
        }
    }
    for(k=izquierda;k<=derecha;k++){
        datos[k]=datosAux[k];
    }
}
int main()
{
    ordenamiento obj1;
    obj1.llenado();
    obj1.mostrar("DESORDENADOS");
    obj1.mezcla_sort(0,max);
    obj1.mostrar("ORDENADOS");

    return 0;
}
