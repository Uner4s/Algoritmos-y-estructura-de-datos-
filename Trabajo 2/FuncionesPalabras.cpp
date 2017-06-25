/* Universidad de Santiago
 * Facultad de Ciencia
 * Departamento de Matemática y Ciencia de la Computación
 * Licenciatura en Ciencia de la Computación
 *
 * Nombre: Nicolas Perez Poblete.
 * Proposito:

 * Fecha: 21 de Julio del 2012
 *
 * IDE: Code::Blocks 10.05
 * Compilador: GNU GCC Compiler

*/

// Definicion de librerias.


#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#define MAX 500

using namespace std;



struct Palabra0 // strtuct para sacar las palabras y su frecuencia.
{
    char pal[30]; //Variable de estructura tipo caracter.
    char caracteres[30];
    char Palabra[30];
    int Frecuencia;
    int freq;    // Variable tipo entero.
    int Frecucaracter;
};


void menu(); // Funcion que muestra un menu al principio.
void mostrarTexto();  // Funcion que muestra el texto entero dentro de un archivo.
void PorPalabra (Palabra0 Tex[200], int Largo);  // Funcion que muestra las palabras de menor a mayor.
void esta2(Palabra0 p2[MAX],char x[20],int i,int frecuencia,int i5); // Funcion que sirve para complementar la funcion que busca la palabra y su frecuencia.
void abrir_archivo();// Funcion base para que todo funcione.
void esta(Palabra0 p[MAX],int i,int i2); // Funcion que muestra por panatalla la palabra y su frecuencia pero no ordenados
int colocar(Palabra0 *v, int b, int t);// Funcion que sirve apra colocar las palabras en una estructura y ordenarlas mediante Qucicksort.
void palabrasPorCaracter(); // Funcion que muestra las palabras ordenadas segun cantidad de caracteres.
void TransformarAMayus (char trans[30]); // Funcion funcion que transforma las letras a mayusculas cuando pasan al programa desde el archivo.
void BorrarCaracteresNoAlfabeticos ( char Quitar [30] ); // Funcion que limpia los caracteres que no son letras al principio y al final de la palabra.
void EliminarUnCaracter (char Quitar[30], int Pos); // Funcion que elimina caracteres no alfabeticos.
void menuAdios(); // Funcion que muestra el adios cuando el usuario sale dfel programa.
void Quicksort(Palabra0* v, int b, int t);// Funcion que ordena palabras segun su tamaño.
void BuscaPalabraPorCaracteres (); // busca una palabra segun la cantidad que ingrese el usuario.
void BuscaPalabra ( Palabra0 *v, int principio, int fin );
int BusquedaBinaria ( Palabra0 *v, int principio, int fin, char Palabra[30]);



int main() // Funcion principal main.
{

    ifstream Archivo2;
    cout<<endl;
    cout<<"                         -----*  BIENVENIDO AL PROGRAMA  *----- "<<endl;
    cout<<endl;
    cout<<endl;

    Palabra0 Tex[200];
    char palabra1[30],Prueba[30]; // variables tipo caracter.
    int a,clave=0,clave2=0; // variables tipo entero que son escenciales.
    int Largo=0,f=0;
    abrir_archivo();
    system("pause");
    system("cls");
    Archivo2.open("Palabras.txt");
    system("cls");
    clave++;
    clave2++;
    while(!Archivo2.eof()){
        Archivo2>>Prueba;
        Archivo2>>f;
        Largo++;
    }
    PorPalabra(Tex,Largo);
    system("cls");

    do
    {
        system("cls"); // limpia la pantalla cada ves que se devuelve al principio.


        menu();// Llamado a la funcion menu.
        cin>>a; // lee la varibale ingresada por el usuario para el uso del programa.

        if(a==1) // opcion ingresada por el usuario.
        {
            // Mostrar palabras con su frecuencia.
          BuscaPalabra(Tex, 0 , Largo);

        }
        if(a==2)// opcion ingresada por el usuario.
        {
            //Muestra el texto.
            cout<<endl;

            BuscaPalabraPorCaracteres ();
            system("pause"); // pausa la ejecucion del programa hasta que se apriete una tecla.


        }
        if(a==3)// opcion ingresada por el usuario.
        {
            if(clave2>0) // clave2 tiene que ser mayor a 0 para que el programa funcione en optimas condiciones.
            {
                cout<<endl;
                cout<<"Las palabras ordenadas de menor a mayor:"<<endl;
                cout<<endl;
                PorPalabra (Tex, Largo);
                // pausa la ejecucion del programa hasta que se apriete una tecla.
            }
            else
                cout<<"Seleccione la primera opcion del menu "<<endl;
            system("pause");

        }

        if(a==4)// opcion ingresada por el usuario.
        {
            // Mostrar palabras segun cantidad de caracteres y su frecuencia.
            if(clave>0) // clave tiene que ser mayor a 0 para que el programa funcione en optimas condiciones.
            {
                cout<<endl;
                cout<<" Las palabras ordenadas por cantidad de caracteres de mayor a menor "<<endl;
                palabrasPorCaracter();
                system("pause");// pausa la ejecucion del programa hasta que se apriete una tecla.


            }
            else
            {
                cout<<" Primero debe seleccionar la primera opcion del menu.  "<<endl;
                cout<<" Intentelo mas tarde "<<endl;
                system("pause");// pausa la ejecucion del programa hasta que se apriete una tecla.
            }


        }

        if(a==5)// opcion ingresada por el usuario.
        {
            // Muestra la frecuencia de una palabra.
            cout<<endl;
            mostrarTexto();
            // pausa la ejecucion del programa hasta que se apriete una tecla.
        }
        if(a==6)// opcion ingresada por el usuario.
        {
            system("cls"); // limpia la pantalla
            menuAdios();
            return 0;

        }
        if(a>6)   // cuando se ingresa un numero mayor a 4, el programa se mantiene en la misma pantalla.
        {
            system("cls");  // limpia la pantalla.
            cout<<" Ingrese un numero adecuado al menu. "<<endl; // ingresa un numero adecuado.
        }
    }


    while (a!=7);   // se mantiene si el numero ingresado es distinto de 4.
}


void abrir_archivo() // primera funcion y la fundamental.
{
    ifstream h; // sacaremos informacion del archivo principal.
    ofstream ArchivoColado; // archivo para uso propio, para po.
    ofstream archivo;  //

    Palabra0 p[MAX],p2[MAX]; // definicion de una variable de eestructura.
    // definicion de una variable de eestructura.
    int i=0,i2,frecuencia=0,i5=0,cont=0,variable1=0,respuesta=0; // definicion de variables de tipo entero.
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
        h>>trans; // las palabras pasan a la variable trans.
        TransformarAMayus(trans); // se envia a la funcion de transformacion a mayusculas.
        strcpy(Quitar,trans); // copia la palabra en otra variable.
        BorrarCaracteresNoAlfabeticos(Quitar); // se envia a una funcion que le quita las cariables que no son letras al principio y al final.
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


void menu()   // Esta funcion muestra el menu principal.
{
    cout<<"        *******************************************************************"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X         Bienvenido al Programa                                X*"<<endl;
    cout<<"        *X      ----------------------------------------------------     X*"<<endl;  // MENU PRINCIPAL.
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X   1.- Buscar una palabra.                                     X*"<<endl;
    cout<<"        *X   2.- Buscar palabras por cantidad de letras.                 X*"<<endl;
    cout<<"        *X   3.- Palabras ordenadas alfabeticamente.                     X*"<<endl;
    cout<<"        *X   4.- Mostrar descendendentemente palabras por caracter.      X*"<<endl;
    cout<<"        *X   5.- Mostrar texto entero, limpio y en mayusculas.           X*"<<endl;
    cout<<"        *X   6.- Salir del Programa.                                     X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *******************************************************************"<<endl;
}


void menuAdios()   // Esta funcion muestra el menu principal.
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


void mostrarTexto() // Funcion para mostrar el texto completo.
{
    ifstream Archivo; // se sacaran datos del texto original para mostrar.
    Palabra0 aux[500];
    char nombre[20],trans[30],var[40], Quitar[30];  // variable de tipo caracter.
    int i=0;

    cout<<" Ingrese el Nombre el Archivo para Mostrar el texto "<<endl;
    cin>>nombre;
    cout<<endl;


    Archivo.open(nombre);// se abre el archivo donde se encuentra el texto.

    if (Archivo.fail()) // si falla, el programa avisa el error.
    {
        cout<< "********* El Archivo no Existe ********** "<<endl;

    }
    else
    {
        cout<<" Este es el texto que contiene el archivo abierto "<<endl;
        cout<<endl;
        while( !Archivo.eof()) // mientras el programa lea el archivo hasta el final.
        {
            Archivo>>trans;
            TransformarAMayus(trans); // se envia a la funcion de transformacion a mayusculas.
            strcpy(Quitar,trans); // copia la palabra en otra variable.
            BorrarCaracteresNoAlfabeticos(Quitar); // se envia a una funcion que le quita las cariables que no son letras al principio y al final.
            strcpy(aux[i].pal,Quitar); // copia la palabra ya limpia en otra variable.

            cout<<" "<<aux[i].pal;// se muestra la palabra en pantalla.
            i++;
        }
        cout<<endl;
        system("pause");
    }
    Archivo.close(); // se cierra el archivo.
}




void palabrasPorCaracter() // Funcion que ordena las palabras por cantidad de caracteres mostrando su frecuencia tambien.
{
    ifstream archivo2; // se sacaran datos del archivo2.
    archivo2.open("Palabras.txt"); // se abre un archivo creado previamente por nosotros.

    int i=0,cont=0,cont2=0,freq1=0,freq2=0,auxiliar=0,numero; // variables de tipo enteras.
    char aux[40];// variables de tipo caracter.
    Palabra0 ordenadas[30]; // definicion de una variable de eestructura.


    while(!archivo2.eof()) // mientras el programa lea el archivo hasta el final.
    {
        archivo2>>ordenadas[i].pal; // se agrega a un espacio de la estructura la palabra.
        archivo2>>ordenadas[i].freq; // se agrega a un espacio de la estructura la frecuencia de la palabra.
        i++;// i = i+1;
    }
    cont=0;
    cont2=0;
    while(cont<i)
    {
        cont2=cont+1;
        while(cont2<i)
        {

            freq1=strlen(ordenadas[cont].pal);// se saca la cantidad de caracteres de una palabra.
            freq2=strlen(ordenadas[cont2].pal);// se saca la cantidad de caracteresd  la palabra siguiente.

            if(freq2>freq1)// se comparan la cantidad de letras, si es mayor, se intercambian de posicion.
            {

                strcpy(aux,ordenadas[cont].pal);// se copia la palabra con menor caracteres en una variable caracter auxiliar.
                auxiliar=ordenadas[cont].freq; // se copia la frecuencia de la palabras con menos caracteres en una variable auxiliar.
                strcpy(ordenadas[cont].pal,ordenadas[cont2].pal); // se copia la palabras con mas caracteres de los primeros
                ordenadas[cont].freq=ordenadas[cont2].freq; // se copia la frecuencia de la palabra con mas caracteres de los primeros.
                strcpy(ordenadas[cont2].pal,aux);// el auxiliar pasa a estar en la posicion de la otra palabra.
                ordenadas[cont2].freq=auxiliar;// el auxiliar entero pasa a estar dodne estaba la frecuencia de la otra paalbra.

            }


            cont2++; // cont2=cont2+1.
        }
        cont++; // cont=cont+1.

    }

    cont=0;
    cout<<endl;

    cout<<"Palabras ordenadas por cantidad de caracteres: "<<endl;

    cout<<endl;
    while(cont<i)
    {
        cout<<"Palabra: "<<ordenadas[cont].pal<<", Frecuencia: "<<ordenadas[cont].freq<<endl; // muestra en pantalla las palabras ordenadas por caracteres.
        cont++;
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


int colocar(Palabra0 *v, int b, int t) // funcion que coloca las paalbras en variables de comparacion.
{
    int i; // definicion de variables de tipo entero.
    int pivote,pivote2, valor_pivote; // definicion de variables de tipo entero.
    char temp[30];

    pivote = b;
    pivote2 = b;

    for (i=b+1;i<=t;i++)
    {
        if (strcmp(v[i].pal,v[pivote2].pal)<0)// compara si la palabra es menor a la de la estructura v que tomo lo valores por referencia.
        {
            pivote++; // si es asi pivote + 1.
            strcpy(temp , v[i].pal); // las palabras se intercambian de lugar utilizando una variable auxiliar.
            strcpy(v[i].pal , v[pivote].pal);
            strcpy(v[pivote].pal , temp);

        }
    }
    strcpy(temp , v[b].pal);
    strcpy(v[b].pal , v[pivote].pal);
    strcpy(v[pivote].pal , temp);

    return pivote;
}


void Quicksort(Palabra0* v, int b, int t)// Funcion recursiva apra ordenar por palabras segun su tamaño.
{
    int pivote; // definicion de variables de tipo entero.
    if(b < t)
    {
        pivote=colocar(v, b, t); // ordena de menor a mayor.
        Quicksort(v, b, pivote-1);// vuelve a llamarse pero con una palabra mayor.
        Quicksort(v, pivote+1, t);// se llama por tercera vez con una palabra aun mayor.
    }
}


void PorPalabra (Palabra0 Tex[200], int Largo) // funcion principal para ordenar por palabras de menor a mayor.
{
    ifstream ArchivoColado;// se sacaran datos del archivo colado.
    ifstream archivo; // Se sacaran datos del archivo.
    ArchivoColado.open("asd.txt");
    Palabra0 Ordenar[40]; // definicion de una variable de estructura.
    int i=0,cont=0,freq=0; // definicion de variables de tipo entero.
    char comparada[30];// definicion de variables tipo caracter.

    while(!ArchivoColado.eof()) // mientras el programa lea el archivo hasta el final.
    {
        ArchivoColado>>Ordenar[i].pal; //se ingresa la palabra del archivo creado por nosotros a un espacio de estructura.
        i++;// i=i+1;
        cont++; // cont=cont+1;
    }

    Quicksort(Ordenar,0 ,i-1); // se llama a la funcion QuicksSort.

    i=0;
    while(i<cont)
    {
        archivo.open("Palabras.txt"); // se abre el archivo palabras.
        while(!archivo.eof()) // mientras el programa lea el archivo hasta el final.
        {
            archivo>>comparada; // se agrega a una variable de tipo entero.
            archivo>>freq; // se lee la frecuencia de la palabra.


            if(strcmp(comparada,Ordenar[i].pal)==0) // se comparan con la palabra ordenada. si son iguales se agrega la frecuencia que aparece en el archivo,.
            {
                cout<<"Palabra: "<<Ordenar[i].pal<<", Frecuencia: "<<freq<<endl;// se muestra en pantalla la palabra y su frecuencia ordenadas alfabeticamente.
                strcpy(Tex[i].Palabra,Ordenar[i].pal);
                Tex[i].Frecuencia=freq;

                cont++;// cont=cont+1;
            }
        }
        i++; // i=i+1;
        archivo.close();// se cierra el archivo palabras pero dentro de un ciclo.

    }

    ArchivoColado.close();// se cierra el archivoColado.
    archivo.close(); // se cierra el archivo.
}




void BuscaPalabraPorCaracteres () // Busca palabras con la cantidad ingresada, si se ingresa un 3, se muestra una palabra con 3 caracteres y su frecuencia.
 {
    ifstream archivo;
    archivo.open("Palabras.txt"); //se abre el archivo creado en un principio.
    int fin=0;

    Palabra0 v[50]; // se define una variable Palabra0 que es la e estructura.

    while(!archivo.eof())// hasta que se dejen de pasar datos a la estructura.
    {
        archivo>>v[fin].caracteres; // aqui se guardan las palabras del archivo creado anteriormente.
        archivo>>v[fin].Frecucaracter;// aqui se guardan las frecuencias del archivo creado anteriormente.
        fin++; // fin = fin + 1.
    }


    archivo.close(); // se cierra el archivo.
    system ("CLS"); // se limpia la pantalla.

    int Cantidad; // variable de tipo entero.
    int i,respuesta=0; // variable de tipo entero.
    int ii;// variable de tipo entero.
    bool flag=false; // bool que segun lo que se haga se puede cambiar  a true como una asignacion de valor normalmente.

    do
    {
        cout << "Ingrese cantidad de caracteres de la/las palabra/s: ";
        cin >> Cantidad;
        cout << endl;

        for (i=0;i<fin;i++) // ciclo para buscar las palabras segun la cantidad que se ingrese.
        {
            ii=0;
            while(v[i].caracteres[ii]!='\0') // mientras no sea el final del arreglo.
            {
                ii++;
            }
            if(ii==Cantidad) // si la cantidad ingresada es igual a la cantidad de caracteres de la palabra:
            {
                cout<<"Palabra"<<": "<<v[i].caracteres<<" ,Frecuencia:"<< v[i].Frecucaracter<<" ."<< endl; // se muestra por panatalla la palabra y su frecuencia.
                flag=true;
            }
        }

        if (flag==false) // si el flag es falso.
            cout<<"No se han encontrado palabras con "<<Cantidad<<" de caracteres"<<endl; // no se encotnraron palabras con esa cantidad de caracteres.
        cout<<endl;


        cout<<"Para buscar otra palabra presione 1, para salir presione 2. "<<endl;// seguir o salir del buscador de palabras.
        cin>>respuesta;

        while(respuesta!= 1 && respuesta!=2){ // si se ingresa una opcion no valida, se repite el ciclo hasta que si.

            cout<<" Ingrese una opcion valida."<<endl;
            cout<<"Para buscar otra palabra presione 1, para salir presione 2. "<<endl;
            cin>>respuesta;
        }

    }
    while(respuesta!=2); // cuando respuesta sea igual a 2, se sale del ciclo de buscar.

    archivo.close();

}

 int BusquedaBinaria(Palabra0 *v,int principio,int fin,char Palabra[30])// busqueda binaria.
 {
     int m;                // el arreglo se llama por referencia, el principio al llamarla es 0, fin es la cantidad de palabras dentro de la estructura y palabra es la palabra que se busca.

     if(principio<=fin)// si 0 es menor o igual a fin.
     {
        m=(principio+fin)/2; // se saca la parte entera del medio de la estructura.

         //if( x < v[m] ) res = busqueda_dicotomica(v, principio, m-1, x);

        if(strcmp(v[m].Palabra,Palabra)>0) BusquedaBinaria(v,principio,m-1,Palabra);// compara las palabras seleccionadas, la del medio y la que se introdujo.

        else if(strcmp(v[m].Palabra, Palabra)<0) BusquedaBinaria(v,m+1,fin,Palabra);

        else if(strcmp(v[m].Palabra,Palabra)==0) return m;

     }else return -1;

 }


 void BuscaPalabra (Palabra0 *v, int principio, int fin ) // Busqueda binaria.
 {
    char Palabra[30]; // variable tipo caracter que es la palabra ingresada.
    int i;
    int Opcion;

    system ("CLS");// se limpia la pantalla.

    do // ciclo Do while.
    {
        cout << "Ingrese palabra que desee buscar: ";
        cin >> Palabra; // se lee la palabra ingresada.

        TransformarAMayus(Palabra);// se transforma a mayusculas todas las minusculas de la palabra ingresada.

        i=BusquedaBinaria(v , principio , fin , Palabra);// se ve que valor se retorna de la busqueda realizada.

        if (i>-1) // si es mayor a -1
                cout<< "Palabra" << ": " << v[i].Palabra<<" , Frecuencia: "<<v[i].Frecuencia<<" ." <<endl; // se encontro la palabra, se muestra en pantalla con su frecuencia.
        else // si no
                cout<<"No se ha encontrado la palabra"<<endl; // se anuncia que la palabra no se encontro.

        do// ciclo para seguir buscando o no.
        {

        cout<<endl<<"Ingrese 1 para seguir buscando o 2 si desea salir: ";
        cin>>Opcion ;
        cout<<endl;

        }while(Opcion!=1 && Opcion!= 2);// si es diferente la opcion ingresada a las que se puede se repite la pregunta.

    }while (Opcion==1); // para no salirsed el ciclo Opcion debe ser 1.

 }


