#include "pch.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <string> 

using namespace std;
 

struct Usuario
{
    string Nombres;
    string Apellidos;
    string Direccion;
    int DNI;//último numero dni por ejemplo "78475745" recoge el "5" entonces lo recoge a partir de las 5pm 
    //o estara disponible a las 5pm la hora de envio.
    int Edad;
    char Sexo;
    int Celular;


};

struct Libros
{
    string LibroNombre;
    string LibroAutor;
    string Local;
    int LibroCodigo;
    int Precio;

};

int main()
{

    int OpcionProceso;
    Usuario* DatosUsuario;
    int CantidadPersona = 1;

    cout << "\n\t\tBienvenido a la libreria " << endl;
    cout << "\t\tIngrese sus datos: " << endl;
    cout << "\t\t----------------------------------" << endl;

    DatosUsuario = new Usuario[CantidadPersona];

    for (int i = 0; i < CantidadPersona; i++)
    {
        cout << "\t\tNombre   : ";
        cin >> DatosUsuario[i].Nombres;
        cin.ignore();
        getline(cin, DatosUsuario[i].Nombres);

        cout << "\t\tApellidos  : ";
        cin >> DatosUsuario[i].Apellidos;
        cin.ignore();
        getline(cin, DatosUsuario[i].Apellidos);

        cout << "\t\tEdad    : ";
        cin >> DatosUsuario[i].Edad;

        cout << "\t\tDNI  : ";


        cout << "\t\tDireccion  : ";
        cin.ignore();
        getline(cin, DatosUsuario[i].Direccion);

        cout << "\t\tSexo    : ";
        cin >> DatosUsuario[i].Sexo;

        cout << "\t\tCelular  : ";
        do
        {

            cin >> DatosUsuario[i].Celular;

        } while (DatosUsuario[i].Celular < 100000000 || DatosUsuario[i].Celular>1000000000);


        cout << "\t\t----------------------------------" << endl;
    }

    cout << "\n\t\tBienvenido al la libreria UPC!!" << endl;
    cout << "\t\tIngrese el proceso que desee realizar" << endl;
    cout << "\t\t-----------------------------------------------" << endl;
    cout << "\t\tOpcion 1 --> Venta de libros : " << endl;
    cout << "\t\tOpcion 2 --> Venta de libros : " << endl;
    cout << "\t\t-----Su elección ->"; cin >> OpcionProceso;



	


    switch (OpcionProceso)
    {
    case 1:


        break;

    case 2:


        break;



    default:

        cout << "Elección inválida, por favor intente nuevamente" << endl;

        break;
    }






    delete[] DatosUsuario;

    return 0;
}

void RegistroDatos()
{





}

void VentaLibros()
{

}

void RecojoLibros()
{

}

