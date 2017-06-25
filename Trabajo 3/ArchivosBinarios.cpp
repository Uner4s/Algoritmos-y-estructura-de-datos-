/*
*Universidad Santiago de Chile.
*Facultad de Ciencias.
*Departamento de Matemática y Ciencia de la Computación.
*Licenciatura en Ciencia de la Computación.


*Autor: Nicolas Perez Poblete.
*Proposito: Ingresar informacion al programa mediante un archivo binario y trabajar con los datos.
*Fecha: 5 de septiembre del 2012.
*Ide:Code Blocks 10.05.
*Compilador:GNU GCC Compiler.
*/

//Definicin de librerias.

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <windows.h>

using namespace std;

struct productos // Estructura donde se reciben los productos y su cantidad.
{
    char nomproducto[20]; // Variable char que recibe el nombre del producto.
    int  cantidad; // Variable entera que recibe la cantidad del producto.
    productos *next; // Variable tipo productos para formar una lista.
};

struct nodo // Estructura nodo.
{
    int numcamion; // Variable entera que recibe el numero del camion.
    int prioridad; // Variable tipo entera que recibe la preoridad del camion 1 Alta / 2 Media / Baja
    float ton; // toneladas
    int cong; // 1=si    2=no // Variable que recibe si es congelado o no.
    int pere; // 1 si / 2 no  Variable entero que recibe si es perecible o no.
    int cantidadT; // Cantidad total de productos.
    int cantidadp; // Cantidad diferentes de productos.
    productos *T; // Variable tipo productos para formar una lista.
    nodo *sig;
};

struct prodAux // Estructura donde se reciben los productos y su cantidad.
{
    char nomproducto[20]; // Variable char que recibe el nombre del producto.
    int  cantidad; // Variable entera que recibe la cantidad del producto.
};

struct aux // Estructura auxiliar para recibir los datosd del camion pero no los productos ni cantidad.
{
    int numcamion; // Variable entera que recibe el numero del camion.
    int prioridad; // Variable tipo entera que recibe la preoridad del camion 1 Alta / 2 Media / Baja
    float ton; // toneladas
    int cong; // 1=si    2=no // Variable que recibe si es congelado o no.
    int pere; // 1 si / 2 no  Variable entero que recibe si es perecible o no.
    int cantidadproductos; // Cantidad total de productos.
    int cant2; // Cantidad diferentes de productos.
};

struct auxnodo // Estructura auxiliar que recibe los datos del camion incluyendo los productos y su cantidad.
{
    int numcamion; // Variable entera que recibe el numero del camion.
    int prioridad; // Variable tipo entera que recibe la preoridad del camion 1 Alta / 2 Media / Baja
    float ton; // toneladas
    int cong; // 1=si    2=no // Variable que recibe si es congelado o no.
    int pere; // 1 si / 2 no  Variable entero que recibe si es perecible o no.
    int cantidadproductos; // Cantidad total de productos.
    int cant2; // Cantidad diferentes de productos.
    productos *Pr; // Variable tipo productos para formar una lista.
};

class lista // Clase tipo lista.
{
private:
    nodo *p; // Variable "p" principal como estructura nodo.

public:
    lista(); // constructor.
    ~lista(); // destructor.
    void ingresar(auxnodo I); // funcion donde se ingresan los datos.
    void mostrar(int &dia,int &hora,int &minuto,int &minutoaux,int &llegada);// funcion que muestra los datos de las tres listas creadas mas las horas y minutos de intervalos que se demoran.
};

void main2(lista &a, lista &b, lista &c); // Funcion donde se lee el archivo y se llaman las funciones ingresar a cada lista correspondiente.
void menu(); // Funcion que muestra el menu por pantalla.
void main3();// Funcion donde se leen las opciones del menu y se llama la funcion mostrar segun corresponda.
void cantidadcamiones(int &CanCamion); // Funcion que manda una variable por referencia y retorna la cantidad de camiones totales que llegaran.
void menuadios();// Funcion que contiene un menu que aparece cuando el usuario ingresa la opcion "salir".



//Funcion principal main.
int main()
{
    menu();  // Funcion que muestra el menu por pantalla.
    main3(); // Funcion donde se leen las opciones del menu y se llama la funcion mostrar segun corresponda.
    system("cls"); // Comando que limpia la pantalla.
    menuadios(); // Funcion que contiene un menu que aparece cuando el usuario ingresa la opcion "salir".
    return 0; // Se finaliza el programa.
}



void main3() // Funcion donde se leen las opciones del menu y se llama la funcion mostrar segun corresponda.
{
    int op,CanCAMION=0; // Variable que recibe la opcion del usuario y la Variable cantidad de camiones totales.
    lista a; // Se crea una variable tipo Lista.
    lista b; // Se crea una variable tipo Lista.
    lista c; // Se crea una variable tipo Lista.
    int dia;  //Variable que muestra el dia en el que descargan los camiones
    int hora; //Variable que muestra la hora en la que se descargan los camiones
    int minuto; //Variable que le suma minutos al tiempo dependiendo de la temporada
    int minutoaux;   //Variable que muestra los minutos en el que descargan los camiones
    int llegada;    //Variable donde se tiene el tiempo de llegada de los camiones dependiendo de la temporada

    main2(a,b,c); // Se mandan las tres variables Lista
    cantidadcamiones(CanCAMION); // Se manda la variable canCAMION para saber la cantidad de camiones totales.
    do // Ciclo do-While
    {
        system("cls"); // Comando que limpia la pantalla.
        menu(); // Funcion que muestra el menu por pantalla.
        cin>>op;// Se lee la opcion ingresada por el usuario.
        switch (op) // Switch para saber que hacer en cada caso.
        {
        case 1: // Caso de que op sea 1
            system("cls"); // Comando para limpiar la pantalla.
            cout<<"Cantidad de camiones totales: "<<CanCAMION<<endl; // Muestra por pantalla la cantidad de camiones totales.
            cout<<endl;// Se salta un espacio en pantalla.
            dia=1; // Variable dia = 1.
            hora=6;// Variable hora = 6
            minutoaux=30;// Variable minutoaux=30.
            minuto=12;//Variable minuto = 12.
            llegada=1;// Variable llegada = 1.
            cout<<"Dia: 1"<<endl; // Al principio siempre dice que es dia 1.
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 1 <-----------------------"<<endl;
            a.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista a, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");
            system("cls");
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 2 <-----------------------"<<endl;
            b.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista b, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");
            system("cls");
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 3 <-----------------------"<<endl;
            c.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista c, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");// Funcion que pausa la pantalla.
            break;
        case 2: // Caso de que op sea 2
            system("cls"); // Comando para limpiar la pantalla.
            cout<<"Cantidad de camiones totales: "<<CanCAMION<<endl; // Muestra por pantalla la cantidad de camiones totales.
            cout<<endl; // Se salta un espacio en pantalla.
            dia=1; // Variable dia = 1.
            hora=6; // Variable hora = 6
            minutoaux=30; // Variable minutoaux=30.
            minuto=36; //Variable minuto = 36.
            llegada=5; // Variable llegada = 5.
            cout<<"Dia: 1"<<endl; // Al principio siempre dice que es dia 1.
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 1 <-----------------------"<<endl;
            a.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista a, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");
            system("cls");
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 2 <-----------------------"<<endl;
            b.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista b, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");
            system("cls");
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 3 <-----------------------"<<endl;
            c.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista c, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");// Funcion que pausa la pantalla.
            break;
        case 3: // Caso de que op sea 3
            system("cls"); // Comando para limpiar la pantalla.
            cout<<"Cantidad de camiones totales: "<<CanCAMION<<endl; // Muestra por pantalla la cantidad de camiones totales.
            cout<<endl; // Se salta un espacio en pantalla.
            dia=1; // Variable dia = 1.
            hora=6; // Variable hora = 6
            minutoaux=30; // Variable minutoaux=30.
            minuto=49;  //Variable minuto = 49.
            llegada=10; // Variable llegada = 10.
            cout<<"Dia: 1"<<endl; // Al principio siempre dice que es dia 1.
            cout<<endl;  // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 1 <-----------------------"<<endl;
            a.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista a, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");
            system("cls");
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 2 <-----------------------"<<endl;
            b.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista b, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");
            system("cls");
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<endl; // Se salta un espacio en pantalla.
            cout<<"        ---------------------> Prioridad 3 <-----------------------"<<endl;
            c.mostrar(dia,hora,minuto,minutoaux,llegada);// Funcion mostrar de la lista c, muestra los camiones, horas de llegada, descarga y salida.
            system("pause");// Funcion que pausa la pantalla.
            break;

        case 4: // Caso de que op sea 4 no hace nada y vuelve al menu principal.
            break;
        }
    }
    while(op!=4);// Mientras la opcion principal no sea igual a 4.

}

void cantidadcamiones(int &CanCamion) // Funcion que muestra la cantidad de camiones.
{
    ifstream Archivo; // ifstream para leer datos del archivo.
    aux z; // Variable z tipo aux que es una estructura.
    prodAux Q;  // Variable Q tipo prodAux que es una estructura.
    auxnodo I;  // Variable I tipo auxnodo que es una estructura.
    productos *A,*R; // Dos variables tipo Productos para formar una lista auxiliarb.
    I.Pr = NULL; // Variable I que su espacio producto queda en NULL.
    char nombre[50];//variable tipo caracter.
    nombre[0]=1;//asignacion.
    int ca=0; // Variable tipo entero que es para descargar cantidad especifica de productos.
    //a.menu();
    Archivo.open("camion2.txt", ios::binary); // Se abre el archivo "Camion" por defecto.

    while(Archivo.read((char*)(&z),sizeof(aux))) // Mientras el Archivo no llegue hasta el final.
    {
        ca=0;// variable ca inicializada en 0.
        R = new productos;
        R = NULL;// R queda en NULL.
        if(z.cant2!=0) // Mientras la cantidad de productos diferentes sea distinta de 0.
        {
            while(z.cant2>ca)// ciclo que es para que el camion decargue su cantidad de productos exacta.
            {
                Archivo.read((char*)(&Q),sizeof(prodAux));
                A=new productos;// new nodo.
                strcpy(A->nomproducto,Q.nomproducto);// copia el nombre reibido en la Variable auxiliar nombre.
                A->cantidad=Q.cantidad; // copia la cantidad del produto recibida en la variable auxiliar.
                A->next=R;// A siguiente igual a variable producto R.
                R=A; // R=A
                ca++;// ca = ca+1.
            }
        }
        CanCamion++;// Contador de camiones +1
    }
    Archivo.close();// Se cierra el archivo de los camiones.
}



void main2(lista &a, lista &b, lista &c)
{
    ifstream Archivo; // ifstream para leer datos del archivo.
    aux z;  // Variable z tipo aux que es una estructura.
    prodAux Q; // Variable Q tipo prodAux que es una estructura.
    auxnodo I;  // Variable I tipo auxnodo que es una estructura.
    productos *A,*R; // Dos variables tipo Productos para formar una lista auxiliar.
    I.Pr = NULL;  // Variable I que su espacio producto queda en NULL.
    char nombre[50];//variable tipo caracter.
    nombre[0]=1;//asignacion.
    int ca=0; // Variable tipo entero que es para descargar cantidad especifica de productos.
    //a.menu();
    Archivo.open("camion2.txt", ios::binary); // Se abre el archivo "Camion" por defecto.

    while(Archivo.read((char*)(&z),sizeof(aux))) // Mientras el Archivo no llegue hasta el final.
    {
        ca=0; // variable ca inicializada en 0.
        R = new productos;
        R = NULL; // R queda en NULL.
        if(z.cant2!=0) // Mientras la cantidad de productos diferentes sea distinta de 0.
        {
            while(z.cant2>ca) // ciclo que es para que el camion decargue su cantidad de productos exacta.
            {
                Archivo.read((char*)(&Q),sizeof(prodAux));
                A=new productos; // new nodo.
                strcpy(A->nomproducto,Q.nomproducto); // copia el nombre reibido en la Variable auxiliar nombre.
                A->cantidad=Q.cantidad; // A siguiente igual a variable producto R.
                A->next=R; // A siguiente igual a variable producto R.
                R=A; // R=A.
                ca++; // ca = ca+1.
            }
        }
        I.numcamion=z.numcamion; // Recibe el numero del camion.
        I.prioridad=z.prioridad; // Recibe la preoridad de los productos del camion.
        I.ton=z.ton; // Recibe el tonelaje total del camion.
        I.cong=z.cong; // Recibe si son congelados o no congelados los productos del camion.
        I.pere=z.pere; // Recibe si son perecibles o no perecibles los productos del camion.
        I.Pr=R; // El espacio como lista Pr se traspasan todos los datos de R.
        I.cantidadproductos=z.cantidadproductos; // Recibe la cantidad de productos totales que trae el camion.
        I.cant2=z.cant2; // Recibe la cantidad de productos diferentes que trae el camion.

        R=NULL;// R igual a NULL.
        A=NULL; // A igual a NULL.

        if(I.prioridad==1) // Si la preoridad de los productos del camion es igual a 1.
            a.ingresar(I); // Se llama la funcion ingresa de la primera lista prioridad 1.
        if(I.prioridad==2) // Si la preoridad de los productos del camion es igual a 2.
            b.ingresar(I); // Se llama la funcion ingresa de la segunda lista prioridad 2.
        if(I.prioridad==3) // Si la preoridad de los productos del camion es igual a 3.
            c.ingresar(I); // Se llama la funcion ingresa de la tercera lista prioridad 3.
    }
    Archivo.close();
}

void lista::mostrar(int &dia,int &hora,int &minuto,int &minutoaux,int &llegada) // Muestra cada lista con las horas de llegada, descarga e ida de los camiones.
{
    nodo *q;// Variable q como nodo proncipal.
    q=NULL;// q igual a NULL.
    productos *r;// Variable r tipo productos.
    r=NULL;// r igual a NULL.
    q=p;
    int n=0;

    while(q) // Mientras q sea distinto de NULL.
    {
        if(hora>=8){    //Si la hora es igual o mayor a 8
            hora=6; //La hora pasa a ser 6
            minutoaux=30;   //Los minutos auxiliares a 30
            dia++;  //Avanza un dia
            cout<<endl;// Se salta un espacio en la pantalla.
            cout<<"***************************************************************************"<<endl;
            cout<<endl;
            cout<<"Dia: "<<dia<<endl;    //Muestra el dia
        }
        cout<<endl;// Se salta un espacio en la pantalla.
        cout<<"***************************************************************************"<<endl;
        if((minutoaux+llegada)<10)
            cout<<" Descarga desde "<<"0"<<hora<<":"<<"0"<<minutoaux+llegada<<" hasta las";   //Muestra la hora a la que llega el camion
        else
            cout<<" Descarga desde "<<"0"<<hora<<":"<<minutoaux+llegada<<" hasta las";
        if(minutoaux+minuto>=60){   //Si la suma de los minutos auxiliares mas los minutos es igual o mayor a 60
            minutoaux+=minuto;  //Los minutos auxiliares pasa a ser la suma de estos mas los minutos
            minutoaux-=60;  //A los minutos auxiliares se le resta 60
            hora++; //Se le suma  una hora
        }
        else{   //Si no son iguales o mayores a 60
            minutoaux+=minuto;      //Minutos auxiliares pasa a ser la suma de estos con minutos
        }
        cout<<endl;// Se salta un espacio en la pantalla.
        if(minutoaux<10)
            cout<<"  0"<<hora<<":"<<"0"<<minutoaux<<endl;  //Imprime la hora a la que se va el camion
        else
            cout<<"  0"<<hora<<":"<<minutoaux<<endl;//Imprime la hora a la que se va el camion
        cout<<endl;
        cout<<" Numero del Camion:  "  <<q->numcamion<<endl; // Muestra el numero del camion.
        cout<<" Prioridad  | Alta = 1 | Media = 2 | Baja = 3 |:  "<<q->prioridad<<endl;// Muestra la preoridad de los productos del camion.
        cout<<" Tonelaje:  " <<q->ton<<endl; // Muestra el tonelaje total del camion.
        cout<<" Congelados | Si = 1 | No = 2 |:  " <<q->cong<<endl; // Muestra si los productos son congelados o no congelados.
        cout<<" Perecible  | Si = 1 | No = 2 |:  "<<q->pere<<endl; // Muestra si los productos son perecibles o no perecibles.
        cout<<" Cantidad de productos Totales:  "<<q->cantidadT<<endl; // Muestra la cantidad de productos totales del camion.
        cout<<" Cantidad de productos diferentes: "<<q->cantidadp<<endl;// Muestrala cantidad de productos diferentes que trae el camion.
        cout<<endl;// Se salta un espacio en la pantalla.
        r=q->T;

        while(r){
            cout<<"Producto: "<<r->nomproducto<<" | Cantidad: "<<r->cantidad<<endl; // Muestra el producto y su cantidad.
            n++;// n = n +1.
            r=r->next;//r igual a r->sig
        }
        q=q->sig;// q igual a q-> sig
    }
    q=NULL;// q igual a NULL.
}

lista::lista()
{
    p= NULL; // p nulo
}

lista::~lista()
{
    nodo *q; // Variable q tipo nodo.
    while (p)// mientras p sea distinto de NULL.
    {
        q=p;
        p = p->sig;
        delete q;
    }
}

void menu()
{
    cout<<"           xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*******************  Supermercado El Cañuelin  ******************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x***********  1.- Cargar productos en temporada Alta.  ***********x"<<endl;
    cout<<"           x***********  2.- Cargar productos en temporada Media. ***********x"<<endl;
    cout<<"           x***********  3.- Cargar productos en temporada Baja.  ***********x"<<endl;
    cout<<"           x***********  4.- Salir del programa.                  ***********x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
}

void menuadios()
{
    cout<<"           xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*******************  Supermercado El Cañuelin  ******************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x**************************  GoodBye  ****************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           x*****************************************************************x"<<endl;
    cout<<"           xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
}
void lista::ingresar(auxnodo I) // funcion que ingresa los datos.
{
    nodo *q, *r; // dos variables tipo nodo.
    q = new nodo; // q igual a nuevo nodo.
    q->numcamion=I.numcamion; // se recibe el numero del camion.
    q->prioridad=I.prioridad; // recibe la prioridad del camion.
    q->ton=I.ton; // recibe las toneladas del camion.
    q->cong=I.cong;// recibe si es congelado o no congelado.
    q->pere=I.pere; // recibe si es perecible o no perecible.
    q->cantidadT=I.cantidadproductos; // recibe la cantidad de productos totales.
    q->cantidadp=I.cant2; // recibe la cantidad de productos diferentes.
    q->T=I.Pr; // el espacio de q de los productos recibe todos los productos de la variable auxiliar.
    q->sig=p;
    q -> sig = p;   // se supone menor
    I.Pr=NULL;
    if (!p||p->ton<q->ton )
        p=q;
    if(p->ton==q->ton && p->cantidadT<q->cantidadT)
        p=q;// p pasa a ser igual q.
    if(p->ton==q->ton && p->cantidadT==q->cantidadT && p->pere<q->pere)
        p=q;// p pasa a ser igual q.
    if(p->ton==q->ton && p->cantidadT<q->cantidadT)
        p=q;// p pasa a ser igual q.
    if(p->ton==q->ton && p->cantidadT==q->cantidadT && p->pere==q->pere && p->cong<q->cong)
        p=q;// p pasa a ser igual q.
    if(p!=q){ // mientras p sea distinto de q.
        r = p->sig; // r= a p siguiente.
        while ( r && r -> ton > q -> ton ){
            q->sig = r; // q siguiente es igual a r.
            r = r->sig; // r se salta al espacio siguiente.
        }
        if(!r || r->ton < q->ton || (r->ton == q->ton && r->cantidadT < q->cantidadT) || (r->ton == q->ton && r->cantidadT == q->cantidadT && r->pere < q->pere) || (r->ton == q->ton && r->cantidadT < q->cantidadT) || (r->ton == q->ton && r->cantidadT == q->cantidadT && r->pere == q->pere && r->cong < q->cong)){
            q->sig->sig = q; // q siguiente siguiente igual a q.
            q->sig = r; // q siguiente es igual a r.
        }
        if(q->sig!=r){
            while ( r && r->ton == q->ton && r->cantidadT > q->cantidadT ){
                q->sig = r; // q siguiente es igual a r.
                r = r->sig;
            }
            if(!r || r->ton < q->ton){
                q->sig->sig = q; // q siguiente siguiente igual a q.
                q->sig = r; // q siguiente es igual a r.
            }
            if(r->ton == q->ton && r->cantidadT < q->cantidadT && q->sig!=r){
                q->sig->sig = q; // q siguiente siguiente igual a q.
                q->sig = r; // q siguiente es igual a r.
            }
            if(r->ton == q->ton && r->cantidadT == q->cantidadT && r->pere < q->pere && q->sig!=r){
                q->sig->sig = q; // q siguiente siguiente igual a q.
                q->sig = r; // q siguiente es igual a r.
            }
            if(r->ton == q->ton && r->cantidadT < q->cantidadT){
                q->sig->sig = q; // q siguiente siguiente igual a q.
                q->sig = r; // q siguiente es igual a r.
            }
            if(r->ton == q->ton && r->cantidadT == q->cantidadT && r->pere == q->pere && r->cong < q->cong && q->sig!=r){
                q->sig->sig = q; // q siguiente siguiente igual a q.
                q->sig = r; // q siguiente es igual a r.
            }
            if(q->sig!=r){
                while ( r && r->ton == q->ton && r->cantidadT == q->cantidadT && r->pere > q->pere){
                    q->sig = r; // q siguiente es igual a r.
                    r = r->sig; // r se salta al espacio siguiente.
                }
                if( !r || r->ton < q->ton)
                    q->sig->sig = q; // q siguiente siguiente igual a q.
                    q->sig = r; // q siguiente es igual a r.
                }
                if(r->ton == q->ton && r->cantidadT < q->cantidadT && q->sig!=r){
                    q->sig->sig = q; // q siguiente siguiente igual a q.
                    q->sig = r; // q siguiente es igual a r.
                }
                if(r->ton == q->ton && r->cantidadT == q->cantidadT && r->pere < q->pere && q->sig!=r){
                    q->sig->sig = q; // q siguiente siguiente igual a q.
                    q->sig = r; // q siguiente es igual a r.
                }
                if(r->ton == q->ton && r->cantidadT < q->cantidadT && q->sig!=r){
                    q->sig->sig = q; // q siguiente siguiente igual a q.
                    q->sig = r; // q siguiente es igual a r.
                }
                if(r->ton == q->ton && r->cantidadT == q->cantidadT && r->pere == q->pere && r->cong < q->cong && q->sig!=r) {
                    q->sig->sig = q; // q siguiente siguiente igual a q.
                    q->sig = r; // q siguiente es igual a r.
                }
                if(q->sig!=r){
                    while ( r && r->ton == q->ton && r->cantidadT == q->cantidadT && r->pere == q->pere && r->cong > q->cong){
                        q->sig = r; // q siguiente es igual a r.
                        r = r->sig; // r se salta un espacio siguiente.
                    }
                    q->sig->sig = q; // q siguiente siguiente igual a q.
                    q->sig = r;// q siguiente igual a r.
                }
            }
        }
    }

