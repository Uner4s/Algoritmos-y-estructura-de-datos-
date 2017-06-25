#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;



struct camion{
    int numcamion;
    int priori;
    float ton;
    int cong;
    int pere;
    int cantidadproductos;
    int cantp;
};

struct productos{
    char nombreproducto[20];
    int cantidad;
};

int main(){
    ofstream arch("camioncitito.txt", ios::binary);
    ifstream arch1;
    int n=0,num;
    int k,i=0;
    int j,w=0;
    char an;
    camion a;
    camion c;
    camion e;
    productos b;
    productos d;

    cout<<"Cuantos camiones desea ingresar?"<<endl;
    cin>>num;
    k=num;
    cout<<"Cantidad de camiones:\t"<<num<<endl<<endl;
    while(i<k){
        n=n+1;
        cout<<"Camion "<<n<<endl;
        a.numcamion=n;
        cout<<"Ingrese la prioridad del camion (1-Alta / 2-Media / 3-Baja : ";
        cin>>a.priori;
        cout<<"Ingrese el tonelaje: ";
        cin>>a.ton;
        cout<<"Ingrese el estado de los productos (1-Congelados / 2-No congelados : ";
        cin>>a.cong;
        cout<<"Alimentos 1-Perecibles / 2- No perecibles : ";
        cin>>a.pere;
        cout<<" cantidad total "<<endl;
        cin>>a.cantidadproductos;
        cout<<"Cuantos productos diferentes trae el camion?: ";
        cin>>j;
        a.cantp=j;

        arch.write((char *)(&a),sizeof(camion));
        w=0;
        while(w<j){
            cout<<"Nombre del producto:  ";
            cin>>b.nombreproducto;
            cout<<"Cantidad de unidades: ";
            cin>>b.cantidad;
            arch.write((char *)(&b),sizeof(productos));
            w++;
        }

        i++;
        cout<<"Ciclo numero: "<<i<<endl;
    }
    arch.close();
    system("cls");
}
