/* Universidad de Santiago
 * Facultad de Ciencia
 * Departamento de Matemática y Ciencia de la Computación
 * Licenciatura en Ciencia de la Computación
 *
 * Nombre: Nicolas Perez Poblete.
 * Proposito: Generar tres tipos de frases, las cuales deben tener minimo 4 palabras distintas.
   muestre los archivos originales y te muestre las frases ya creadas por el usuario.
 * Fecha: 30 de Mayo, 2012
 *
 * IDE: Code::Blocks 10.05
 * Compilador: GNU GCC Compiler

*/

# include <iostream>
# include <fstream>
# include <conio.h>
# include <windows.h>
# include <string.h>


using namespace std;


// Programa Principal


void menu(); // Muestra el menu principal.
void archivos(); // muestra el menu de que tipo de archivos desea ver.
void articulos(); // funcion que muestra los articulos.
void sustantivos();// funcion que muestra los sustantivos.
void verbos(); // funcion que muestra los verbos.
void adjetivos(); // funcion que muestra los adjetivos.
void frases_creadas(); // funcion que muestra las frases ya creadas.
void tipo_frase(); // funcion que da a elegir el tipo de frase.
void primer_tipo(); // funcion que crea una frase del primer tipio.
void segundo_tipo(); // funcion que crea una frase del segundo tipo.
void tercer_tipo(); // funcion que crea una frase del tercer tipo.
void adios();    // Fuincion adios.


// Funcion main.
int main()

{
    ofstream archivo_20; // Archivo donde se guardan las palabras ya usadas.
    archivo_20.open("temporal.txt"); // Se abre el archivo dodne estan las palabras ya usadas.
    archivo_20.close();// se cierra el archivo.

    ifstream archivo_10; //
    ifstream archivo_11; //  ARCHIVOS DONDE SE GUARDAN LAS FRASES YA CREADAS POR TIPO.
    ifstream archivo_12; //

    archivo_10.open("primertipo.txt");  // Abre el archivo donde se encuentran las oraciones de primer tipo.
    archivo_11.open("segundotipo.txt"); // Abre el archivo donde se encuentran las oraciones de segundo tipo.
    archivo_12.open("tercertipo.txt");  // Abre el archivo donde se encuentran las oraciones de tercer tipo.

    char c,nombre[30];     //en c se guarda el caracter sacado del archivo y nombre guarda el nombre del archivo
    int a,b,e,cont=0,cant=6;// variables de tipo entera para manejarse dentro del int main.
    // variables utilizadas para el menu del programa. De ellas depende el funcionamiento o lo que se desea hacer.
    ifstream ent;          //define una variable de tipo archivo (para sacar datos)

    system("cls");
    do            // Es el que recibe las operaciones principales del menu.
    {
        menu();
        cin>>a;   // lee la priemra variable entera ingresada.
        if(a==1)
        {
            system("cls"); // limpia la pantalla.
            archivos();
            cin>>b; // lee un numero para mostrar los ARTICULOS,SUSTANTIVOS,VERBOS Y ADJETIVOS.
            if(b==1)
            {
                articulos(); // muestra automaticamente el archivo donde estan los articulos
            }
            if(b==2)
            {
                sustantivos();//muestra automaticamente el archivo donde estan los sustantivos

            }
            if(b==3)
            {
                verbos(); //muestra automaticamente el archivo donde estan los verbos.
            }
            if(b==4)
            {
                adjetivos(); //muestra automaticamente el archivo donde estan los  adjetivos.
            }
            if(b==5)
            {
                system("cls");  // limpia la pantalla.
                // El usuario retorna al menu anterior.
            }
        }
        if(a==2)
        {
            frases_creadas(); // muestra automaticamente  las frases ya creadas.

        }
        if(a==3)
        {
            system("cls");
            cout<<"     ********************************************************************"<<endl; //
            cout<<"     *                 Se pueden crear MAXIMO 6 FRASES                  *"<<endl; // Le recuerda al usuario que
            cout<<"     ********************************************************************"<<endl; // solo puede crear 6 frases.

            tipo_frase();// Llama a la funcion void donde se muestran los tiposd e frase que se pueden crear.
            cin>>e; // "e" Seria la opcion para el tipo de frase especifico.
            if(e==1)
            {
                if(cont<=cant)  // mientras contador menor o igual que cant, para que solo se puedan crear 6 frase.
                {
                    primer_tipo();// muestra las frases creada de primer tipo.
                    cont++;
                }
                else
                {
                    system("cls");
                    cout<<"     ********************************************************************"<<endl;
                    cout<<"     *         Debe reiniciar el programa para crear mas frases.        *"<<endl;// cuando ya se crearon la cantidad maxima
                    cout<<"     ********************************************************************"<<endl;// de frases aparece este mensaje.


                }
            }
            if(e==2)
            {
                if(cont<=cant)  // mientras contador menor o igual que cant, para que solo se puedan crear 6 frase.
                {
                    segundo_tipo();// muestra las frases creada de segundo tipo.
                    cont++;
                }
                else
                {
                    cout<<"     ********************************************************************"<<endl;
                    cout<<"     *         Debe reiniciar el programa para crear mas frases.        *"<<endl;// cuando ya se crearon la cantidad maxima
                    cout<<"     ********************************************************************"<<endl;// de frases aparece este mensaje.
                }


            }
            if(e==3)
            {
                if(cont<=cant) // mientras contador menor o igual que cant, para que solo se puedan crear 6 frase.
                {
                    tercer_tipo(); // muestra las frases creada de tercer tipo.
                    cont++;
                }
                else
                {
                    cout<<"     ********************************************************************"<<endl;
                    cout<<"     *         Debe reiniciar el programa para crear mas frases.        *"<<endl;// cuando ya se crearon la cantidad maxima
                    cout<<"     ********************************************************************"<<endl;// de frases aparece este mensaje.
                }
            }
            if(e==4)
            {
                system("cls");
            }

        }


        if(a==4) // cuando en el menu principal, el usuario escoge la opcion 4, el programa finaliza.
        {
            system("cls");  // limpia la pantalla.
            adios();// llama a una funcion void que trae consigo un mensaje de despedida.
            archivo_10.close(); // cierra el archivo que contiene las frases ya creadas de primer tipo.
            archivo_11.close(); // cierra el archivo que contiene las frases ya creadas de segundo tipo.
            archivo_12.close(); // cierra el archivo que contiene las frases ya creadas de tercer tipo.
            return 0;

        }
        if(a>4)   // cuando se ingresa un numero mayor a 4, el programa se mantiene en la misma pantalla.
        {
            system("cls");  // limpia la pantalla.
            cout<<" Ingrese un numero adecuado al menu. "<<endl; // ingresa un numero adecuado.
        }
    }


    while (a!=4);   // se mantiene si el numero ingresado es distinto de 4.
}

void menu()   // Esta funcion muestra el menu principal.
{
    cout<<"        **************************************************************"<<endl;
    cout<<"        *xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x      Usted ingreso al creador de frases mas hermoso.     x*"<<endl;
    cout<<"        *x      -----------------------------------------------     x*"<<endl;  // MENU PRINCIPAL.
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x   1.- Ver archivos originales.                           x*"<<endl;
    cout<<"        *x   2.- Ver las frases ya realizadas.                      x*"<<endl;
    cout<<"        *x   3.- Crear una nueva frase.                             x*"<<endl;
    cout<<"        *x   4.- Salir del programa.                                x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*"<<endl;
    cout<<"        **************************************************************"<<endl;
}

void archivos() // muestra el menu donde estan los archivos originales que se abren automaticamente dependieno del numero que esoja.
{
    cout<<"        **************************************************************"<<endl;
    cout<<"        *xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x      Seleccione un archivo.                              x*"<<endl;
    cout<<"        *x      ----------------------                              x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x   1.- Articulos.                                         x*"<<endl;  // MENU ARCHIVOS.
    cout<<"        *x   2.- Sustantivos.                                       x*"<<endl;
    cout<<"        *x   3.- Verbos.                                            x*"<<endl;
    cout<<"        *x   4.- Adjetivos.                                         x*"<<endl;
    cout<<"        *x   5.- Regresar al menu anterior.                         x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*"<<endl;
    cout<<"        **************************************************************"<<endl;
}

void tipo_frase() // funcion donde se encuentra el menu para seleccionar el tipo de frase.
{
    cout<<"        **************************************************************"<<endl;
    cout<<"        *xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x      Seleccione el tipo de frase.                        x*"<<endl;
    cout<<"        *x      ----------------------------                        x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x   1.- Articulo + Sustantivo + Verbo + Adjetivo.          x*"<<endl; // MENU TIPO DE FRASE.
    cout<<"        *x   2.- Adjetivo + Verbo + Articulo + Sustantivo.          x*"<<endl;
    cout<<"        *x   3.- Verbos + Articulos + Sustantivos + Adjetivos.      x*"<<endl;
    cout<<"        *x   4.- Volver al menu principal.                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*"<<endl;
    cout<<"        **************************************************************"<<endl;
}

void adios() // Funcion de adios cuando se finaliza el programa.
{
    cout<<"        **************************************************************"<<endl;
    cout<<"        *xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x      PROGRAMA FINALIZADO.                                x*"<<endl;
    cout<<"        *x      --------------------                                x*"<<endl; // MENU DESPEDIDA.
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                       Vuelva pronto.     x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *x                                                          x*"<<endl;
    cout<<"        *xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*"<<endl;
    cout<<"        **************************************************************"<<endl;

}


void articulos() // funcion que muestra los articulos dentro de un archivo.
{

    char nombre[10],c;// variable de tipo char.
    ifstream archivo_1; // sacara datos del archivo donde estan los articulos.

    archivo_1.open("articulos.txt");    // abre el archivo articulos automaticamente.
    if (archivo_1.fail())      // chequea que el archivo exista .
    {
        cout<<"\n\n\n              Archivo no existe";
        system("PAUSE");
        exit (1);       //  aborta el programa si el archivo no existe
    }
    cout <<endl<<"El contenido del archivo " << nombre <<" es:\n\n  ";
    cout<<endl;
    cout<<"*********************************"<<endl;
    while(!archivo_1.eof()) // hasta que llega al final, muestra los componentes del archivo.
    {
        archivo_1.get(c); // el archivo pasa caracteres a la variable c.

        cout<< c ; // se muestran los caracteres que juntos generan palabras.
    }
    cout<<"*********************************"<<endl;
    archivo_1.close();
    system("PAUSE");
    system("cls");  // limpia la pantalla.

}

void sustantivos() // funcion que muestra los sustantivos dentro de un archivo.
{

    char nombre[10],c; // variable de tipo char.
    ifstream archivo_2;// sacara datos del archivo donde estan los sustantivos.

    archivo_2.open("sustantivos.txt");    // abre el archivo sustantivos automaticamente
    if (archivo_2.fail())      // chequea que el archivo exista .
    {
        cout<<"\n\n\n              Archivo no existe";
        system("PAUSE");
        exit (1);       //  aborta el programa si el archivo no existe
    }
    cout <<endl<<"El contenido del archivo " << nombre <<" es:\n\n  ";
    cout<<endl;
    cout<<"*********************************"<<endl;
    while(!archivo_2.eof()) // hasta que llega al final, muestra los componentes del archivo.
    {
        archivo_2.get(c);// el archivo pasa caracteres a la variable c.
        cout << c; // se muestran los caracteres que juntos generan palabras.
    }
    cout<<"*********************************"<<endl;
    archivo_2.close();
    system("PAUSE");
    system("cls"); // limpia la pantalla.


}


void verbos() // funcion que muestra los verbos dentro de un archivo.
{

    char nombre[10],c;// variable de tipo char.
    ifstream archivo_3;// sacara datos del archivo donde estan los verbos..

    archivo_3.open("verbos.txt");    // abre el archivo verbos automaticamente.
    if (archivo_3.fail())      // chequea que el archivo exista .
    {
        cout<<"\n\n\n              Archivo no existe";
        system("PAUSE");
        exit (1);       //  aborta el programa si el archivo no existe
    }
    cout <<endl<<"El contenido del archivo " << nombre <<" es:\n\n  ";
    cout<<endl;
    cout<<"*********************************"<<endl;
    while(!archivo_3.eof()) // hasta que llega al final, muestra los componentes del archivo.
    {
        archivo_3.get(c);// el archivo pasa caracteres a la variable c.
        cout << c; // se muestran los caracteres que juntos generan palabras.
    }
    cout<<endl;
    cout<<"*********************************"<<endl;
    archivo_3.close(); //cierra el archivo 3.
    system("PAUSE");
    system("cls");  // limpia la pantalla.
}

void adjetivos() // funcion que muestra los adjetivos dentro de un archivo.
{

    char nombre[10],c;// variable de tipo char.
    ifstream archivo_4; // sacara datos del archivo donde estan los adjetivos..

    archivo_4.open("adjetivos.txt");    // abre el archivo adjetivos automaticamente.
    if (archivo_4.fail())      // chequea que el archivo exista .
    {
        cout<<"\n\n\n              Archivo no existe";
        system("PAUSE");
        exit (1);       //  aborta el programa si el archivo no existe
    }
    cout <<endl<<"El contenido del archivo " << nombre <<" es:\n\n  ";
    cout<<endl;
    cout<<"*********************************"<<endl;
    while(!archivo_4.eof()) // hasta que llega al final, muestra los componentes del archivo.
    {
        archivo_4.get(c);// el archivo pasa caracteres a la variable c.
        cout << c;
    }
    cout<<endl;
    cout<<"*********************************"<<endl;
    archivo_4.close();
    system("PAUSE");

    system("cls");  // limpia la pantalla.
}


void frases_creadas() // funcion que muestra las frases ya creadas.
{

    int a; // variable entera.  ( numero escogido en un menu )
    char c; // variable de caracter.

    cout<<"         ¿ Que tipo de frase creada desea ver ? ."<<endl; // pregunta que archivo desea ver.( donde estan las frases creadas).
    cout<<endl;
    cout<<endl;
    cout<<" 1.- Primer tipo.     "<<endl; // ver frases primer tipo.
    cout<<endl;
    cout<<" 2.- Segundo tipo.    "<<endl; // ver frases segundo tipo.
    cout<<endl;
    cout<<" 3.- Tercer tipo.     "<<endl; // ver frases tercer tipo.

    ifstream archivo_10; // ARCHIVOS DE LOS CUALES SACAREMOS DATOS.
    ifstream archivo_11;
    ifstream archivo_12;

    archivo_10.open("primertipo.txt");  // se abre el archivo donde estan las frases de primer tipo creadas.
    archivo_11.open("segundotipo.txt"); // se abre el archivo donde estan las frases de segundo tipo creadas.
    archivo_12.open("tercertipo.txt"); // se abre el archivo donde estan las frases de tercer tipo creadas.

    cin>>a;

    if(a==1)
    {
        cout<<"*********************************"<<endl;
        while(!archivo_10.eof()) // hasta que llega al final, muestra los componentes del archivo.
        {
            archivo_10.get(c); // pasa los datos a la variable "c" para que los muestre.
            cout << c; // muestra por pantalla las frases.
        }
        cout<<"*********************************"<<endl;
        archivo_10.close(); // cierra el archivo donde estan las frases de primer tipo.
        system("PAUSE");
        system("cls");  // limpia la pantalla.
    }
    if(a==2)
    {
        cout<<"*********************************"<<endl;
        while(!archivo_11.eof()) // hasta que llega al final, muestra los componentes del archivo.
        {
            archivo_11.get(c); // pasa los datos a la variable "c" para que los muestre.
            cout << c; // muestra por pantalla las frases.
        }
        cout<<"*********************************"<<endl;
        archivo_11.close();// cierra el archivo donde estan las frases de segundo tipo.
        system("PAUSE");
        system("cls");  // limpia la pantalla.
    }
    if(a==3)
    {
        cout<<"*********************************"<<endl;
        while(!archivo_12.eof()) // hasta que llega al final, muestra los componentes del archivo.
        {
            archivo_12.get(c); // pasa los datos a la variable "c" para que los muestre.
            cout << c; // muestra por pantalla las frases.
        }
        cout<<"*********************************"<<endl;
        archivo_12.close(); // cierra el archivo donde estan las frases de tercer tipo.
        system("PAUSE");
        system("cls");  // limpia la pantalla.
    }


}


void primer_tipo() // funcion que crea una frase del primer tipo.
{

    char art[20],sus[20],verb[20],adj[20],sexo,sexo2,sexo3,sexo4,num,num2,num3,num4,P,Le; // declaracion de variables de tipo char.
    int cont=0,cont2=0,cont3=0,Numero; // declaracion de variables de tipo int.

    ofstream archivo_20;
    archivo_20.open("temporal.txt",ofstream::app);

    //LAS VARIABLES "sexo" SE REFIEREN AL GENERO MASCULINO O FEMENINO.

    cout<<endl;

    cout<<" Ingrese el tipo de articulo. ( No vuelva a repetir el articulo)"<<endl;// Te permite escoger el articulo a utilizar.
    cout<<endl;
    cout<<"******************"<<endl; //
    cout<<"* 1.- Las        *"<<endl; //
    cout<<"* 2.- Los        *"<<endl; //
    cout<<"* 3.- Unos       *"<<endl; // TODOS LOS ARTICULOS QUE SE PUEDEN OCUPAR EN ESTE TIPO DE FRASE.
    cout<<"* 4.- Unas       *"<<endl; //
    cout<<"* 5.- El         *"<<endl; //
    cout<<"* 6.- La         *"<<endl; //
    cout<<"******************"<<endl; //


    cin>>Numero; // Lee el numero con el cual se elige el tipo de articulo que se desea ocupar.

    ofstream archivo_10; // para guardar las palabras utilizadas.
    archivo_10.open("primertipo.txt",ofstream::app);// archivo donde quedaran las frases.



    ifstream archivo_1;                // Sacara datos del archivo que contiene los articulos.
    archivo_1.open("articulos1.txt");  // Abre el archivo donde se encuentran los articulos.
    ifstream archivo_2;                //Sacara datos del archivo que contiene los sustantivos.
    archivo_2.open("sustantivos1.txt");//Abre el archivo donde se encuentran los sustantivos.
    ifstream archivo_3;                // Sacara datos del archivo que contiene los verbos.
    archivo_3.open("verbos1.txt");     //Abre el archivo donde se encuentran los verbos.
    ifstream archivo_4;                //Sacara datos del archivo que contiene los adjetivos.
    archivo_4.open("adjetivos1.txt");  //Abre el archivo donde se encuentran los adjetivos.




    if(Numero==1)  // si es 1, Lee el primer articulo del archivo.
    {
        while(!archivo_1.eof() && cont!=1 )
        {
            archivo_1>>art; // Lee el primer articulo.
            archivo_1>>num; // lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
            archivo_20<<art<<endl;
        }
    }
    if(Numero==2)  // si es 2, Lee el segundo articulo del archivo.
    {
        while(!archivo_1.eof() && cont!=2 )
        {
            archivo_1>>art;// Lee el segundo articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
            archivo_20<<art<<endl;
        }
    }
    if(Numero==3)  // si es 3, Lee el tercer articulo del archivo.
    {
        while(!archivo_1.eof() && cont!=3 )
        {
            archivo_1>>art; // Lee el tercer articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
            archivo_20<<art<<endl;
        }
    }
    if(Numero==4)  // si es 4, Lee el cuarto articulo del archivo.
    {
        while(!archivo_1.eof() && cont!=4 )
        {
            archivo_1>>art; // lee el cuarto articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
            archivo_20<<art<<endl;
        }
    }
    if(Numero==5)   // si es 5, Lee el quinto articulo del archivo.
    {
        while(!archivo_1.eof() && cont!=5 ) // archivo de los articulos pasa datos hasta que llegue al final o hasta que contador sea distinto de 5.
        {
            archivo_1>>art;// lee el quinto  articulo dentro del archivo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
            archivo_20<<art<<endl;
        }
    }
    if(Numero==6)  // si es 6, Lee el sexto articulo del archivo.
    {
        while(!archivo_1.eof() && cont!=6 )
        {
            archivo_1>>art;//lee un articulo dentro del archivo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
            archivo_20<<art<<endl;
        }
    }

    while(!archivo_2.eof() && sexo2!=sexo)  // lee un sustantivo hasta que su "sexo" ( masculino o femenino) sea igual al del articulo.
    {
        archivo_2>>sus; // lee el sustantivo.
        archivo_2>>sexo2; // lee si es masculino o femenino.
        archivo_2>>num2;// lee pluralidad o singularidad.
        archivo_2>>Le; // lee si termina en vocal o consonante.
        archivo_20<<sus<<endl;
    }
    while(!archivo_3.eof() && num3!=num)
    {
        archivo_3>>verb; // lee un verbo dentro del archivo.
        archivo_3>>num3;// lee pluralidad o singularidad.
        archivo_20<<verb<<endl;

    }
    while(!archivo_4.eof() && cont3==0)
    {
        archivo_4>>adj; // lee un adjetivo.
        cont3++; // contador le suma 1 para salirse.
        archivo_20<<adj<<endl;

    }

    if(num=='P' && Le=='V')  // si el articulo es singular y el sustantivo termina en vocal.
    {
        system("cls");  // limpia la pantalla.
        cout<<"La frase de tipo   *--Articulo + Sustantivo + Verbo + Adjetivo--*   es: "<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<art<<" "<<sus<<"s"<<" "<<verb<<" "<<adj<<endl; // al sustantivo le agrega una "s".
        archivo_10<<art<<" "<<sus<<"s"<<" "<<verb<<" "<<adj<<endl;// guarda la misma frase en un archivo.
        archivo_20<<art<<" "<<sus<<" "<<verb<<" "<<adj<<endl;//archivo donde se guardan las variables originales para despues comaprarlas para la repeticion.


    }
    if(num=='P' && Le=='C' && sexo2=='M')  // si el articulo es plural, el sustantivo termina en consonante y es masculino:
    {
        system("cls");  // limpia la pantalla.
        cout<<"La frase de tipo   *--Articulo + Sustantivo + Verbo + Adjetivo--*   es: "<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<art<<" "<<sus<<"es"<<" "<<verb<<" "<<adj<<endl;// al sustantivo le agrega un "es" al final.
        archivo_10<<art<<" "<<sus<<"es"<<" "<<verb<<" "<<adj<<endl; // guarda la misma frase en un archivo.
        archivo_20<<art<<" "<<sus<<" "<<verb<<" "<<adj<<endl;//archivo donde se guardan las variables originales para despues comaprarlas para la repeticion.

    }

    if(num=='S') // si el articulo es singular.
    {
        system("cls");  // limpia la pantalla.
        cout<<"La frase de tipo   *--Articulo + Sustantivo + Verbo + Adjetivo--*   es: "<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<art<<" "<<sus<<" "<<verb<<" "<<adj<<endl; //escribe en singular todas las palabras con sentido.
        archivo_10<<art<<" "<<sus<<" "<<verb<<" "<<adj<<endl; // guarda la frase en un archivo.
        archivo_20<<art<<" "<<sus<<" "<<verb<<" "<<adj<<endl;//archivo donde se guardan las variables originales para despues comaprarlas para la repeticion.

    }
}

void segundo_tipo()
{
    char art[20],sus[20],verb[20],adj[20],sexo,sexo2,sexo3,sexo4,num,num2,num3,num4,P,Le; // Declaracion de variables char.
    int cont=0,cont2=0,cont3=0,Numero; // Declaracion de variables numericas.

    //LAS VARIABLES "sexo" SE REFIEREN AL GENERO MASCULINO O FEMENINO.

    ofstream archivo_11; // se guardaran datos en el archivo.
    archivo_11.open("segundotipo.txt",ofstream::app); // abre el archivo donde se guardan las frases de segundo tipo.
    cout<<endl;


    ofstream archivo_20;
    archivo_20.open("temporal.txt");

    cout<<" Ingrese el tipo de articulo. ( No vuelva a repetir el articulo )"<<endl; // Se puede escoger el tipo de articulo a utilizar
    cout<<endl;
    cout<<"******************"<<endl; //
    cout<<"* 1.- Las        *"<<endl; //
    cout<<"* 2.- Los        *"<<endl; //
    cout<<"* 3.- Unos       *"<<endl; // TODOS LOS ARTICULOS QUE SE PUEDEN OCUPAR EN ESTE TIPO DE FRASE.
    cout<<"* 4.- Unas       *"<<endl; //
    cout<<"* 5.- El         *"<<endl; //
    cout<<"* 6.- La         *"<<endl; //
    cout<<"******************"<<endl; //

    cin>>Numero; //Lee el numero ingresado para trabajar.


    ifstream archivo_3;// sacara datos del archivo que tiene los verbos.
    archivo_3.open("verbos1.txt");// abre el archivo que contiene los verbos.
    ifstream archivo_1;// sacara datos del archivoque contiene los articulos.
    archivo_1.open("articulos1.txt");// abre el archivo que contiene los articulos.
    ifstream archivo_2;// sacara datos del archivo que contiene los sustantivos.
    archivo_2.open("sustantivos1.txt");// abre el archivo que contiene los sustantivos.
    ifstream archivo_4;// sacara datos del archivo que contiene los adjetivos.
    archivo_4.open("adjetivos1.txt");// abre el archivo que contiene los adjetivos.


    while(!archivo_4.eof() && cont==0) // se sale cuando toma la primera palabra.
    {
        archivo_4>>adj;// Lee el primer adjetivo del archivo.
        archivo_4>>num4;// lee pluralidad o singularidad.
        archivo_4>>sexo4;// lee si es masculino o femenino.
        cont++;
    }

    if(Numero==1)
    {
        while(!archivo_1.eof() && cont!=2 )  // archivo de los articulos pasa datos hasta que llegue al final o hasta que contador sea distinto de 5.
        {
            archivo_1>>art;// Lee el primer articulo del archivo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==2)
    {
        while(!archivo_1.eof() && cont!=3 ) //lee el archivo hasta que una de las dos condiciones falle.
        {
            archivo_1>>art;// Lee el segundo articulo del archivo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==3)
    {
        while(!archivo_1.eof() && cont!=4 ) //lee el archivo hasta que una de las dos condiciones falle.
        {
            archivo_1>>art;// Lee el tercer articulo del archivo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==4)
    {
        while(!archivo_1.eof() && cont!=5 ) //lee el archivo hasta que una de las dos condiciones falle.
        {
            archivo_1>>art;// Lee el cuarto articulo del archivo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==5)
    {
        while(!archivo_1.eof() && cont!=6 ) //lee el archivo hasta que una de las dos condiciones falle.
        {
            archivo_1>>art;// Lee el quinto articulo del archivo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==6)
    {
        while(!archivo_1.eof() && cont!=7 ) //lee el archivo hasta que una de las dos condiciones falle.
        {
            archivo_1>>art;// Lee el sexto articulo del archivo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    while(!archivo_3.eof() && num3!=num)  // mientras se pasen datos y la singularidad o pluralidad del articulo sea distinta a la del verbo.
    {
        archivo_3>>verb;// Lee el verbo adecuado al articulo escogido.
        archivo_3>>num3;// lee pluralidad o singularidad.
    }
    while(!archivo_2.eof() && sexo2!=sexo) //mientras se pasen datos y el sexo del articulo sea distinto al del sustantivo.
    {
        archivo_2>>sus;// lee un sustantivo adecuado al articulo.
        archivo_2>>sexo2;// lee si es masculino o femenino.
        archivo_2>>num2;// lee pluralidad o singularidad.
        archivo_2>>Le;// verifica si termina con vocal o consonante.

    }

    if(num=='P' && Le=='V') // si el articulo es plural y el sustantiovo termina en vocal.
    {
        system("cls");  // limpia la pantalla.
        cout<<" La frase de tipo   *--Adjetivo + Verbo + Articulo + Sustantivo--*  es:"<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<"¿"<<adj<<"s"<<" "<<verb<<" "<<art<<" "<<sus<<"s"<<"?"<<endl; //se le agrega una "s" al adjetivo y al sustantivo.
        archivo_11<<"¿"<<adj<<"s"<<" "<<verb<<" "<<art<<" "<<sus<<"s"<<"?"<<endl;// se guarda la frase realizada.
        archivo_20<<adj<<" "<<verb<<" "<<art<<" "<<sus<<endl;//archivo donde se guardan las variables originales para despues comaprarlas para la repeticion.
    }
    if(num=='P' && Le=='C')  // si el articulo es plural y el sustantivo termina en consonante.
    {
        system("cls");  // limpia la pantalla.
        cout<<" La frase de tipo   *--Adjetivo + Verbo + Articulo + Sustantivo--*  es:"<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<"¿"<<adj<<"s"<<" "<<verb<<" "<<art<<" "<<sus<<"es"<<"?"<<endl;// se le agrega una "s" al adjetivo y al sustantivo un "es" al final.
        archivo_11<<"¿"<<adj<<"s"<<" "<<verb<<" "<<art<<" "<<sus<<"es"<<"?"<<endl;// se guarda en un archivo.
        archivo_20<<adj<<" "<<verb<<" "<<art<<" "<<sus<<endl;//archivo donde se guardan las variables originales para despues comaprarlas para la repeticion.
    }

    if(num=='S') // si el articulo es singular.
    {
        system("cls");  // limpia la pantalla.
        cout<<" La frase de tipo   *--Adjetivo + Verbo + Articulo + Sustantivo--*  es:"<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<"¿"<<adj<<" "<<verb<<" "<<art<<" "<<sus<<"?"<<endl; // se escribe toda la frase en singular con sentido gramatical.
        archivo_11<<"¿"<<adj<<" "<<verb<<" "<<art<<" "<<sus<<"?"<<endl;// se guarda en el archivo.
        archivo_20<<adj<<" "<<verb<<" "<<art<<" "<<sus<<endl;//archivo donde se guardan las variables originales para despues comaprarlas para la repeticion.
    }



}

void tercer_tipo()
{
    char art[20],sus[20],verb[20],adj[20],sexo,sexo2,sexo3,sexo4,num,num2,num3,num4,P,Le; // variables tipo char.
    int cont=0,cont2=0,cont3=0,Numero; // variables tipo entero.


    //LAS VARIABLES "sexo" SE REFIEREN AL GENERO MASCULINO O FEMENINO.

    ofstream archivo_20;
    archivo_20.open("temporal.txt");

    ofstream archivo_12; // vamos a guardar datos en el archivo 12.
    archivo_12.open("tercertipo.txt",ofstream::app); // se abre el archivo donde guardamos las frases de tercer tipo.
    cout<<endl;
    cout<<" Ingrese el tipo de articulo. ( No vuelva a repetir el articulo )"<<endl; // Se ingresa el tipo de articulo que se desea ocupar.
    cout<<endl;
    cout<<"******************"<<endl; //
    cout<<"* 1.- Las        *"<<endl; //
    cout<<"* 2.- Los        *"<<endl; //
    cout<<"* 3.- Unos       *"<<endl; // TODOS LOS ARTICULOS QUE SE PUEDEN OCUPAR EN ESTE TIPO DE FRASE.
    cout<<"* 4.- Unas       *"<<endl; //
    cout<<"* 5.- El         *"<<endl; //
    cout<<"* 6.- La         *"<<endl; //
    cout<<"******************"<<endl; //

    cin>>Numero;


    ifstream archivo_3;// sacara datos del archivo que tiene los verbos.
    archivo_3.open("verbos1.txt");// abre el archivo que contiene los verbos.
    ifstream archivo_1;// sacara datos del archivoque contiene los articulos.
    archivo_1.open("articulos1.txt");// abre el archivo que contiene los articulos.
    ifstream archivo_2;// sacara datos del archivo que contiene los sustantivos.
    archivo_2.open("sustantivos1.txt");// abre el archivo que contiene los sustantivos.
    ifstream archivo_4;// sacara datos del archivo que contiene los adjetivos.
    archivo_4.open("adjetivos1.txt");// abre el archivo que contiene los adjetivos.


    if(Numero==1)
    {
        while(!archivo_1.eof() && cont!=1 ) // archivo de los articulos pasa datos hasta que llegue al final o hasta que contador sea distinto de 5.
        {
            archivo_1>>art; // lee el primer articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==2)
    {
        while(!archivo_1.eof() && cont!=2 )
        {
            archivo_1>>art;// lee el segundo articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==3)
    {
        while(!archivo_1.eof() && cont!=3 )
        {
            archivo_1>>art;// lee el tercer articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==4)
    {
        while(!archivo_1.eof() && cont!=4 )
        {
            archivo_1>>art;// lee el cuarto articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==5)
    {
        while(!archivo_1.eof() && cont!=5 )
        {
            archivo_1>>art;// lee el quinto articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }
    if(Numero==6)
    {
        while(!archivo_1.eof() && cont!=6 )
        {
            archivo_1>>art;// lee el sexto articulo.
            archivo_1>>num;// lee pluralidad o singularidad.
            archivo_1>>sexo;// lee si es masculino o femenino.
            cont++;
        }
    }

    while(!archivo_3.eof() && num3!=num)  // mientras el archivo pasa datos y el numero del verbo sea distino al del articulo(numero=pluralidad o singularidad).
    {
        archivo_3>>verb;// lee un verbo adecuado al articulo.
        archivo_3>>num3;// lee pluralidad o singularidad.
    }
    while(!archivo_2.eof() && sexo!=sexo2) // mientras el archivo pasa datos y el genero del articulos es diferente al de los sustantivos.
    {
        archivo_2>>sus; // lee un sustantivo adecuado al articulo.
        archivo_2>>sexo2;// lee si es masculino o femenino.
        archivo_2>>num2;// lee pluralidad o singularidad.
        archivo_2>>Le;// verifica si termina con vocal o consonante.

    }
    while(!archivo_4.eof() && sexo!=sexo4) // mientras arcivo pasa datos y el
    {
        archivo_4>>adj; //lee un adjetivo adecuado al articulo.
        archivo_4>>sexo4;// lee si es masculino o femenino.
        archivo_4>>num4;// lee pluralidad o singularidad.

    }

    if(num=='P' && Le=='V')  //si el articulo es plural y el sustantivo termina en vocal.
    {
        system("cls");  // limpia la pantalla.
        cout<<"La frase de tipo   *--Verbos + Articulos + Sustantivos + Adjetivos--*  es: "<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<verb<<" "<<art<<" "<<sus<<"s"<<" "<<adj<<"s"<<endl; //se le agrega una "s" al sustantivo y al adjetivo.
        archivo_12<<verb<<" "<<art<<" "<<sus<<"s"<<" "<<adj<<"s"<<endl;// se guarda en el archivo.
        archivo_20<<verb<<" "<<art<<" "<<sus<<" "<<adj<<endl; // guarda las palabras.
    }
    if(num=='P' && Le=='C')  //si el articulo es plural y el sustantivo termina en consonante.
    {
        system("cls");  // limpia la pantalla.
        cout<<"La frase de tipo   *--Verbos + Articulos + Sustantivos + Adjetivos--*  es: "<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<verb<<" "<<art<<" "<<sus<<"es"<<" "<<adj<<"s"<<endl;// Al sustantivo se le agrega un "es" y al adjetivo una "s".
        archivo_12<<verb<<" "<<art<<" "<<sus<<"es"<<" "<<adj<<"s"<<endl;// se guarda en el archivo.
        archivo_20<<verb<<" "<<art<<" "<<sus<<" "<<adj<<endl; //archivo donde se guardan las variables originales para despues comaprarlas para la repeticion.
    }

    if(num=='S')// si el articulo es singular.
    {
        system("cls");  // limpia la pantalla.
        cout<<"La frase de tipo   *--Verbos + Articulos + Sustantivos + Adjetivos--*  es: "<<endl;// RECUERDA DE QUE TIPO ES LA FRASE
        cout<<endl;
        cout<<verb<<" "<<art<<" "<<sus<<" "<<adj<<endl;// se escribe todo en singular con sentido gramatical.
        archivo_12<<verb<<" "<<art<<" "<<sus<<" "<<adj<<endl;// se guarda en el archivo.
        archivo_20<<verb<<" "<<art<<" "<<sus<<" "<<adj<<endl;//archivo donde se guardan las variables originales para despues comaprarlas para la repeticion.
    }
}
