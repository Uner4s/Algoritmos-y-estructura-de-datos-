/* Universidad de Santiago
 * Facultad de Ciencia
 * Departamento de Matemática y Ciencia de la Computación
 * Licenciatura en Ciencia de la Computación
 *
 * Nombre: Nicolas Perez Poblete.
 * Proposito: Para un estudio cualitativo de la información se requiere realizar un
 * estudio de las palabras que aparecen en un texto, para ello lo contratan a usted como
 * especialista informático para que realice un programa que guarde por separado las palabras
 * significaticvas que aparecen en un archivo con su respectiva frecuencia
 * muestre los archivos originales y te muestre las frases ya creadas por el usuario.
 * Fecha:18 de Diciembre del 2012.
 *
 * IDE: Code::Blocks 12.05
 * Compilador: GNU GCC Compiler

*/


#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#define MAX 5000

using namespace std;

struct AVL
{
    char info[20];
    int frec;
    int bal;
    AVL *ri, *rd;
};

struct nodo
{
    char info[20];
    int frec;
    nodo *sig;
};

struct AVLaux
{
    char info[20];
};

struct Palabra0 // strtuct para sacar las palabras y su frecuencia.
{
    char pal[30]; //Variable de estructura tipo caracter.
    char caracteres[30];
    char Palabra[30];
    int Frecuencia;
    int freq;    // Variable tipo entero.
    int Frecucaracter;
};

#define izq 1
#define BA 0
#define der -1
#define FALSE 0
#define TRUE 1

int main2();
char* MayorElem(AVL *A);
void menu2();
void menu();
void menuadios();
void BorrarCaracteresNoAlfabeticos (char Quitar[30]);
void EliminarUnCaracter (char Quitar[30],int Pos);
void esta2(Palabra0 p2[MAX],char x[20],int i,int frecuencia,int i5); // Funcion que sirve para complementar la funcion que busca la palabra y su frecuencia.
void abrir_archivo();// Funcion base para que todo funcione.
void esta(Palabra0 p[MAX],int i,int i2); // Funcion que muestra por panatalla la palabra y su frecuencia pero no ordenados
int esta1(AVL *b, char x[50]);
void TransformarAMayus (char trans [30]); // Funcion que transforma letras minusculas a mayusculas.
void busqueda(AVL *a, char palabra[20]);
void inorden(AVL *a);
void postorden(AVL *A);
void preorden(AVL *A);
AVL *roteDer(AVL *a);
AVL *insertarAVL(AVL* a, char elem[20], int FREC);
AVL *insertar(AVL *a, AVL* p, int& MasAlto);
AVL *roteIzq(AVL *a);
AVL *eli(AVL *q, char nomb[30]);
AVL *eli2(char palabra[50],AVL *R);
AVL* eliALL(AVL *a, int var);

class lista
{
private:
    nodo* p;
public:
    lista();
    ~lista();
    void ingresa3(AVL *a); // funcion donde se ingresan los datos.
    void mostrar();
    void INGRE(AVL *a);
    void Mostrarmenor(int var);
    void Mostrarmayor(int var);
    void elimina(char nombre[50]);
    int menor();
    int mayor();
    AVL* eliALL(AVL *a, int var);
};


void lista::Mostrarmenor(int var)
{
    nodo *q=p;
    while(q)
    {
        if(q->frec==var){
            cout<<"      Palabra: "<<q->info<<"  Frecuencia: "<<q->frec<<endl;
            q=q->sig;
        }
        else
            q=q->sig;
    }
}

void lista::Mostrarmayor(int var)
{
    nodo *q=p;
    while(q)
    {
        if(q->frec==var){
            cout<<"      Palabra: "<<q->info<<"  Frecuencia: "<<q->frec<<endl;
            q=q->sig;
        }
        else
            q=q->sig;
    }
}

void lista::mostrar()   //función mostrar para lista.
{
    nodo*q=p;
    while (q)
    {
        cout<<"      Palabra: "<<q->info<<"     Frecuencia: "<<q->frec<<endl;
        q=q->sig;
    }
}

void lista::INGRE(AVL *a)    // Funci�n que recorre el arbol IRD e ingresa a la lista
{
    if(a)
    {
        INGRE(a->ri);
        ingresa3(a);
        INGRE(a->rd);
    }
}

void lista::ingresa3(AVL *a)    //se ingresa a la lista con prioridad 1
{
    nodo *q, *r;
    q = new nodo; //se copian todos los datos
    strcpy(q->info,a->info);
    q->frec=a->frec;
    q -> sig = p;    // ingresa segun frecuencia
    if ( !p || p->frec < q->frec)
    {
        p = q;
    }
    else
    {
        r = p -> sig;
        while ( r && p->frec > q->frec) //Ciclo que ubica al nodo donde se va a insertar el dato
        {
            q -> sig = r;
            r = r -> sig;
        }
        q -> sig -> sig = q; // Inserción del nodo
        q -> sig = r;
    }
}

void lista::elimina(char nombre[50])           //función eliminar.
{
    nodo *r, *q;
    if ( p == NULL )        // eq. if (!p)
        cout<<endl<<"LISTA VACIA"<<endl;
    else
    {
        q = p;
        if ( strcmp(p ->info,nombre)== 0 )
        {
            p = p-> sig;
            delete q ;
        }
        else
        {
            do
            {
                r = q;
                q = q -> sig;
            }
            while ( q && strcmp(q->info,nombre));
            if ( q )
            {
                r -> sig = q -> sig;
                delete q;
            }
            else
                cout<<endl<<" La palabra  "<<nombre
                    <<"  No esta en la lista"<<endl;
        }
    }
}

lista::lista()
{
    p= NULL; // p nulo
}


lista::~lista()
{
    nodo *q;
    while (p)
    {
        q=p;
        p = p->sig;
        delete q;
    }

}


void inorden(AVL *a)    // Funci�n que recorre el arbol IRD
{
    if(a)
    {
        inorden(a->ri);
        cout <<"     Palabra: "<< a->info <<endl;
        inorden(a->rd);
    }
}


void preorden(AVL *A)
{
    if(A)
    {
        cout << A->info <<"\t";
        preorden(A->ri);
        preorden(A->rd);
    }
}

void postorden(AVL *A)
{
    if(A)
    {
        postorden(A->ri);
        postorden(A->rd);
        cout << A->info <<"\t";
    }
}

void busqueda(AVL *a, char palabra[20])
{
    if(a)
    {
        busqueda(a->ri,palabra);
        if(strcmp(palabra,a->info)==0)
        {
            cout<<"      La Palabra "<<palabra<<" si se encuentra y su Frecuencia es  "<<a->frec<<endl;
        }
        busqueda(a->rd,palabra);
    }

}


int lista::menor()   //busca la menor frecuencia de la lista.
{
    nodo*q;
    q=p;
    int var=q->frec;
    while (q)
    {
        if (var > q->frec)
        {
            var=q->frec;
        }
        q=q->sig;
    }
    return var;
}

int lista::mayor()   //busca la menor frecuencia de la lista.
{
    nodo*q;
    q=p;
    int var=q->frec;
    while (q)
    {
        if (var < q->frec)
        {
            var=q->frec;
        }
        q=q->sig;
    }
    return var;
}


AVL *roteIzqDer(AVL *a)
{
    a->ri=roteIzq(a->ri);
    return roteDer(a);
}
// Función que genera una rotación simple a la izquierda
AVL *roteIzq(AVL *a)
{
    AVL *q = a->rd;
    a->rd = q->ri;
    q->ri = a;
    return q;
}

// Función que genera una rotación doble derecha izquierda
AVL *roteDerIzq(AVL *a)
{
    a->rd=roteDer(a->rd);
    return roteIzq(a);
}



// Función para balancear el subárbol derecho de un arbol AVL (caso 2 ó caso 4)
AVL *balanceaDer(AVL *a)
{
    if(a->rd->bal == der) //Caso 2
    {
        a->bal = a->rd->bal = BA;
        a=roteIzq(a);
    }
    else //Caso 4
    {
        switch(a->rd->ri -> bal)
        {
        case izq:
            a->bal = BA;
            a->rd->bal = der;
            break;
        case BA:
            a->bal = a->rd->bal = BA;
            break;
        case der :
            a->bal = izq;
            a->rd->bal = BA;
            break;
        }
        a->rd->ri->bal = BA;
        a=roteDerIzq(a);
    }
    return a;
}

AVL *balanceaIzq(AVL *a)
{
    if(a->ri->bal == izq) //Caso 3
    {
        a->bal = a->ri->bal = BA;
        a=roteDer(a);
    }
    else //Caso 5
    {
        switch(a->ri->rd -> bal)
        {
        case izq:
            a->bal = BA;
            a->ri->bal = izq;
            break;
        case BA:
            a->bal = a->ri->bal = BA;
            break;
        case der :
            a->bal = der;
            a->ri->bal = BA;
            break;
        }
        a->ri->rd->bal = BA;
        a=roteIzqDer(a);
    }
    return a;
}

//funcion que genera una rotacion simple a la derecha
AVL *roteDer(AVL *a)
{
    AVL *q = a->ri;
    a->ri = q->rd;
    q->rd = a;
    return q;
}

//funcion para crear nuevo nodo en el arbol

AVL *insertarAVL(AVL* a, char elem [20], int FREC)
{
    AVL *p;
    int MasAlto;
    p = new AVL;
    p->ri = p->rd = NULL;
    strcpy(p->info,elem);
    p->frec=FREC;
    p->bal = BA;
    return insertar(a,p,MasAlto);
}



AVL *insertar(AVL *a, AVL* p, int& MasAlto)
{
    if (a == NULL)
    {
        MasAlto=TRUE;
        a=p;
    }
    else if(strcmp(a->info,p->info)==1)
    {
        a->ri = insertar(a->ri,p,MasAlto);
        if(MasAlto)
            switch(a->bal)
            {
            case izq :
                MasAlto = FALSE;
                a = balanceaIzq(a);
                break;
            case BA :
                a->bal = izq;
                break;
            case der :
                MasAlto = FALSE;
                a->bal = BA;
                break;
            }
    }
    else
    {
        a->rd = insertar(a->rd,p,MasAlto);
        if(MasAlto)
            switch(a->bal)
            {
            case izq :
                MasAlto = FALSE;
                a->bal = BA;
                break;
            case BA :
                a->bal = der;
                break;
            case der :
                MasAlto = FALSE;
                a = balanceaDer(a);
                break;
            }
    }
    return a;
}


void abrir_archivo() // primera funcion y la fundamental.
{
    ifstream h; // sacaremos informacion del archivo principal.
    ofstream ArchivoColado; // archivo para uso propio, para po.
    ofstream archivo;  //

    Palabra0 p[MAX],p2[MAX]; // definicion de una variable de eestructura.
    // definicion de una variable de eestructura.
    int i=0,i2,frecuencia=0,i5=0,cont=0,variable1=0,respuesta=0 ,contX2; // definicion de variables de tipo entero.
    char x[20], trans[30],Quitar[30],nombre[30]; // definicion de variables tipo caracter
    archivo.open("Palabras.txt"); // se abre un archivo creado por nosotros.
    ArchivoColado.open("asd.txt"); // se abre otro archivo creado por nosotros.




    while (respuesta==0)
    {
        cout<<"Ingrese el nombre del archivo que desea abrir:"<<endl;
        cin>>nombre;
        h.open(nombre);
        if(h.fail()) // si al abrir el archivo de texto falla, avisa.
        {
            cout<<"\n\n\n------------> EL ARCHIVO NO EXISTE <------------"<<endl;
            cout<<" Ingrese el nombre correcto del archivo. "<<endl;
            system("pause");
        }
        else
        {
            respuesta++;
            cout<<endl;
            cout<<" ****** ARCHIVO ABIERTO CON EXITO ****** "<<endl;
        }
    }




    while(!h.eof()) // mientras se pasen datos desde el archivo a la variable. lee hasta el final del archivo.
    {
        contX2=0;
        h>>trans; // las palabras pasan a la variable trans.
        TransformarAMayus(trans); // se envia a la funcion de transformacion a mayusculas.
// copia la palabra en otra variable.
        while(contX2!=20)
        {
            strcpy(Quitar,trans);
            BorrarCaracteresNoAlfabeticos(Quitar);
            strcpy(trans,Quitar);
            contX2++;
        }// se envia a una funcion que le quita las cariables que no son letras al principio y al final.
        strcpy(p[i].pal,Quitar); // copia la palabra ya limpia en otra variable.
        i++;// i=i+1;
    }

    cout<<"\n"<<endl;
    for(i2=0; i2<i; i2++) // ciclo que envia cada palabra para contar su frecuencia.
        esta(p,i,i2); // funcion que cuenta la frecuencia ed cada palabra.

    i2=0;

    while(i2<i) // ciclo para traer una sola ves la palabra con su frecuencia.
    {
        strcpy(x,p[i2].pal); // copia la palabra en una variable auxiliar.
        frecuencia=p[i2].freq;// copia su frecuencia en una variable auxiliar.
        esta2(p2,x,i,frecuencia,i5); // se envia a la funcion para traer solo una ves la palabra y no las veces que aparece en el archivo.
        i5++; // i5 = i5+1;
        i2++; // i2 = i2+1;
    }

    cont=0;
    variable1=0;
    while(cont<i5) // ciclo para mostrar las palabras y su frecuencia.
    {
        if(p2[cont].pal!=0 && p2[cont].freq!=0 ) // mientras los espacios de las estructuiras no contengan basura.
        {
            variable1++;

            if(variable1==1)
            {
                archivo<<p2[cont].pal<<" "<<p2[cont].freq;// guarda en el archivo creado la palabra y su frecuencia.
                ArchivoColado<<p2[cont].pal<<" "; // guarda en otro archivo creado una palabra.
            }
            else
            {
                archivo<<" "<<p2[cont].pal<<" "<<p2[cont].freq;// guarda en el archivo creado la palabra y su frecuencia.
                ArchivoColado<<" "<<p2[cont].pal; // guarda en otro archivo creado una palabra.
            }

            cont++; // cont=cont+1;
        }
        else
            cont++; // cont=cont+1;
    }


    archivo.close(); // se cierra un archivo.
    ArchivoColado.close(); // se cierra un archivo.
    h.close();// se cierra un archivo.
}


void esta(Palabra0 p[MAX],int i,int i2) // funcion para contar la frecuencia de cada palabra.
{
    int i3=0,cont=0,i4=0; // definicion de variables de tipo entero.
    while(i3<i) // ciclo
    {
        if(strcmp(p[i2].pal,p[i3].pal)==0) // comapra una palabra con las demas del archivo apra saber cuantas veces se repite.
        {
            p[i3].freq++; // la frecuencia de la palabra se aumenta si se encuentra una igual.
            i3++;
        }
        else
            i3++;
    }
}


void esta2(Palabra0 p2[MAX],char x[20],int i,int frecuencia,int i5) // funcion para devolver una sola ves la palabra y su frecuencia.
{
    int i3=0,i2=0,cont=0; // definicion de variables de tipo entero.

    while(i2<i)
    {
        if(strcmp(x,p2[i2].pal)==0)// compara palabras, si son iguales no se muestran ya que basta solo una ves.
        {
            cont++; // cont=cont+1;
            i2++;  // i2=i2+1;
        }
        else
            i2++; // i2=i2+1;

    }
    if(cont==0)
    {
        strcpy(p2[i5].pal,x); // se agrega la palabra a una estructura nueva si el contador es igual a 0.
        p2[i5].freq=frecuencia; // se copia la frecuencia de la palabra si el contador es igual a 0;

    }
}


void TransformarAMayus (char trans [30]) // Funcion que transforma letras minusculas a mayusculas.
{
    int i; // definicion de variables de tipo entero.
    int Numero; // definicion de variables de tipo entero.

    for (i=0; trans[i]!='\0'; i++)// ciclo hasta que llegue al final del arreglo.
    {
        Numero = trans[i]; // numero pasa a ser una letra pero no como tal, si no como codigo.

        if( Numero<=122 && Numero>=97) // mientras el codigo no este fuera del rango de las letras.
        {
            trans[i]=char (Numero-32); // la transforma en mayuscula.
        }

        else
        {
            switch(trans[i]) // es un switch para letras especiales. a Todas las transforma en mayusculas.
            {

            case '\240': //á
                trans[i] = char(-75);
                break;

            case '\202': //é
                trans[i] = char(-112);
                break;

            case '\241': //í
                trans[i] = char(-42);
                break;

            case '\242': //ó
                trans[i] = char(-32);
                break;

            case '\243': //ú
                trans[i] = char(-23);
                break;

            case -92: //ñ
                trans[i] = char(-91);
                break;

            case -91: //Ñ
                trans[i] = char(-91);
                break;

            case -75: //Á
                trans[i] = 'A';
                break;

            case -112: //É
                trans[i] = char(-112);
                break;

            case -42: //Í
                trans[i] = char(-42);
                break;

            case -32: //Ó
                trans[i] = char(-32);
                break;

            case -23: //Ú
                trans[i] = char(-23);
                break;
            }
        }
    }
}


int main2()
{
    lista H;
    ifstream Archivo2;
    ifstream Archivo1;
    cout<<endl;
    cout<<"                         -----*  BIENVENIDO AL PROGRAMA  *----- "<<endl;
    cout<<endl;
    cout<<endl;

    lista F;
    Palabra0 Tex[200];
    char palabra1[30],Prueba[30], palabra[20], x[20], comparacion[20],nombre[30], Quitar [30],contX2,trans[30]; // variables tipo caracter.
    int clave=0,clave2=0; // variables tipo entero que son escenciales.
    int Largo=0,f=0,contX=0, op,op2;
    abrir_archivo();
    system("pause");
    system("cls");

    AVL *a;
    AVLaux k;
    ifstream arc;
    a = NULL;

    int num, aux, FREC,var,respuesta=0 ;
    char elem[20];

    arc.open("Palabras.txt");

    //arc.open("arbol.txt",ios::binary);
    while (!arc.eof())//!arc.eof) //arc.read((int*)(&k),sizeof(AVLaux));
    {
        contX=0;
        contX2=0;
        Archivo1.open("Pal.txt");
        arc>>elem;
        arc>>FREC;


        while(!Archivo1.eof())
        {
            Archivo1>>comparacion;

            if(strcmp(elem,comparacion)==0)
                contX++;
        }
        Archivo1.close();
        if(contX==0)
        {

            a=insertarAVL(a,elem, FREC);//a = insertarAVL(a,elem,FREC);
        }

    }
    H.INGRE(a);



    do
    {
        system("cls");
        menu();
        cin>>op;

        switch (op)
        {
        case 1:

            system("cls");
            cout<<" ** Palabras ordenadas de Mayor a Menor Frecuencia: **  "<<endl;
            H.mostrar();
            system("pause");
            break;

        case 2:

            system("cls");
            do
            {
                cout<<"Ingrese la palabra que desea buscar, para salir ingrese una ',' (coma). "<<endl;
                cout<<endl;
                cin>>x;
                cout<<endl;
                strcpy(trans,x);
                TransformarAMayus(trans);
                strcpy(x,trans);
                if(x[0]!=',')
                {
                    if(esta1(a,x)==1)
                    {
                        strcpy(palabra,x);
                        busqueda(a,palabra);
                    }
                    else
                        cout<<" **  La palabra no se encuentra en el Arbol, intente con otra. **  "<<endl;
                }
            }
            while(x[0]!=',');
            system("pause");
            break;

        case 3:

            system("cls");
            cout<<"  **  Las palabras con menor frecuencia son:  **  "<<endl;
            cout<<endl;
            var=H.menor();
            H.Mostrarmenor(var);
            cout<<endl;
            menu2();
            cin>>op2;
            switch (op2)
            {
            case 1:
                do
                {
                    cout<<"  **  Ingrese la palabra que desea eliminar (Para salir ingrese una ',' (coma) ).  **  "<<endl;
                    cin>>x;
                    strcpy(trans,x);
                    TransformarAMayus(trans);
                    strcpy(x,trans);
                    if(x[0]!=',')
                    {
                        a=eli(a,x);
                        strcpy(nombre,x);
                        H.elimina(nombre);
                    }
                }
                while(x[0]!=',');
                system("pause");
                break;
            case 2:
                var=H.menor();
                a=H.eliALL(a,var);
                system("cls");
                cout<<"Todas las palabras con la menor frecuencia fueron eliminadas. Menor frecuencia Actualizada."<<endl;
                cout<<"                Volvera al menu principal para comprobar cambios."<<endl;
                system("pause");
                break;

            case 3:
                break;
            }
            break;

        case 4:

            system("cls");
            cout<<"*** Las palabras ordenadas Alfabeticamente que contiene el arbol (inorden): ***"<<endl;
            cout<<endl;
            inorden(a);
            system("pause");
            break;

        case 5:

            system("cls");
            cout<<"     *** La o las palabras con mayor frecuencia es(son): ***   "<<endl;
            cout<<endl;
            var=H.mayor();
            H.Mostrarmayor(var);
            system("pause");
            break;

        case 6:

            system("cls");
            menuadios();
            system("pause");
            break;
        }
    }while(op!=6);



    return 0;

}



AVL* eli(AVL* A, char x[50])  //elimina del arbol
{
    AVL *Z;
    char palmayor[50];
    if(strcmp(A->info, x)==0)
    {
        if(A->ri == NULL && A->rd==NULL)   // caso 1: El elemento se encuentra en una hoja
        {
            delete A;
            return NULL;
        }
        else if(A->ri == NULL)		// caso 2: La rama izquierda del dato es nula y en la rdecha
        {
            Z= A->rd;                              //             hay informaci@n
            delete A;
            return Z;
        }
        else
        {
            strcpy(palmayor,MayorElem(A->ri));     // Caso 3:  Que sea un arbol interno con rama izq. y rama der.
            strcpy(A->info, palmayor);
            A->ri = eli(A->ri,palmayor);
        }
    }
    else if (strcmp(A->info , x)==1)				// Parte recursiva para recorrer el arbol hasta encontrar elemento
        A->ri = eli(A->ri,x);
    else
        A->rd = eli(A->rd,x);

    return A;
}



char* MayorElem(AVL *A)  //busca mayor elemento del arbol
{
    while(A->rd)
        A=A->rd;
    return(A->info);
}

int esta1(AVL *b, char x[50])  //función determina si la palabra está en el árbol
{
    if (b)
    {
        if(!strcmp(x,b->info))
        {
            return 1;
        }
        else
        {
            if (strcmp(x,b->info)>0)
            {
                esta1(b->rd,x);
            }
            else
            {
                esta1(b->ri,x);
            }
        }
    }
    else
    {
        return 0;
    }
}

void BorrarCaracteresNoAlfabeticos (char Quitar[30]) // Funcion para borrar caracteres no alfabeticos al principio y al final de la palabra.
{
    int i=0; // definicion de variables de tipo entero.
    int Numero;// definicion de variables de tipo entero.

    Numero = Quitar[i];

    if (!(Numero<=122 && Numero>=97) && !(Numero>=65 && Numero<= 90) && Quitar[i]!='\240' && Quitar[i]!='\202' && Quitar[i]!='\241' && Quitar[i]!='\242' && Quitar[i]!='\243' && Numero!=-75 && Numero!=-112 && Numero!=-42 && Numero!=-32 && Numero!=-23 && Numero!= -92 && Numero!=-91)
    {
        EliminarUnCaracter(Quitar,i); // Funcion que borra un caracter pero el del principio de la palabra.
    }

    i++; // i=i+1;

    while (Quitar[i]!='\0')// funcion para contar cantidadd de caracteres asi eliminar el caracter final.
    {
        i++;//i=i+1;
    }

    i--; // i=i-1.
    Numero=Quitar[i];// numero igual al codigo de el ultimo caracter.

    if ( !(Numero <=122 && Numero>=97) && !(Numero>=65 && Numero<= 90) && Quitar[i]!='\240'&& Quitar[i]!='\202' && Quitar[i]!= '\241' && Quitar[i]!='\242' && Quitar[i]!= '\243' && Numero!= -75 && Numero!=-112 && Numero!=-42 && Numero!=-32 && Numero!=-23 && Numero!=-92 && Numero!=-91)
    {
        EliminarUnCaracter(Quitar,i);// vuelve a elimianar caracter no alfabetico.
    }
}


void EliminarUnCaracter (char Quitar[30],int Pos)// Funcion para borrar un caracter en especifico.
{
    int i; // definicion de variables de tipo entero.

    for ( i=Pos; Quitar[i]!='\0'; i++)
    {
        Quitar[i]=Quitar[i+1];
    }
}


AVL* lista::eliALL(AVL *a, int var)   //función que elimina todas las palabras del arbol y lista con igual frecuencia al entero recibido
{
    nodo*q=p,*r;
    char x[50], nombre[30];
    while (q)
    {
        if (q->frec==var)
        {
            r=q->sig;
            a=eli2(q->info,a);
            strcpy(nombre,q->info);
            elimina(nombre);
            q=r;
            r=NULL;
        }
        else
        {
            q=q->sig;
        }
    }
    return a;
}


AVL *eli2(char palabra[50],AVL *R)  //define si está o no la palabra que se desea eliminar en caso de no estar avisa.
{
    char x[50];

    if (R  && esta1(R,palabra)==1){
        strcpy(x,palabra);
        R=eli(R,x);	// Elimina s@lo si el elemento se encuentra en el @rbol
    }
    else
    {
        cout << endl <<"EL ELEMENTO NO SE ENCUENTRA, NO PUEDE SER ELIMINADO";
        cin.get();
    }
    return R;
}

void menu()
{
     cout<<"        *******************************************************************"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X         Bienvenido al Programa                                X*"<<endl;
    cout<<"        *X      ----------------------------------------------------     X*"<<endl;  // MENU PRINCIPAL.
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X   1.- Mostrar de Mayor a Menor frecuencia de palabras.        X*"<<endl;
    cout<<"        *X   2.- Buscar una o mas palabras.                              X*"<<endl;
    cout<<"        *X   3.- Mostrar y eliminar palabras con la menor frecuencia.    X*"<<endl;
    cout<<"        *X   4.- Palabras ordenadas alfabeticamente.                     X*"<<endl;
    cout<<"        *X   5.- Mostrar palabras con la mayor frecuencia.               X*"<<endl;
    cout<<"        *X   6.- Salir del Programa.                                     X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *******************************************************************"<<endl;

}

void menuadios()
{
    cout<<"        *******************************************************************"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X          Hasta luego.                                         X*"<<endl;
    cout<<"        *X      ----------------------------------------------------     X*"<<endl;  // MENU Adios
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                             Vuelva pronto.    X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *******************************************************************"<<endl;

}

void menu2()
{
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X  1.- Eliminar una o varias Palabras.                          X*"<<endl;
    cout<<"        *X  2.- Eliminar todas las palabras con la menor Frecuencia.     X*"<<endl;
    cout<<"        *X  3.- Salir                                                    X*"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
}

int main()
{
    main2();

    return 0;
}
