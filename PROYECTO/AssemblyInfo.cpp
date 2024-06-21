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
 
struct Persona
{
    string Nombres;
    int DNI;
    char Sexo;
};

struct Cliente
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




    delete[] DatosCliente;

    return 0;
}
}


void RegistroDatos()
{
    Usuario* DatosCliente;
    int CantidadPersona = 1; 

    cout << "\n\t\tBienvenido a la libreria " << endl;
    cout << "\t\tIngrese sus datos: " << endl;
    cout << "\t\t----------------------------------" << endl;

    DatosCliente = new Cliente[CantidadPersona];

    for (int i = 0; i < CantidadPersona; i++)
    {
        cout << "\t\tNombre   : ";
        cin >> DatosCliente[i].Nombres;
        cin.ignore();
        getline(cin, DatosCliente[i].Nombres);

        cout << "\t\tApellidos  : ";
        cin >> DatosCliente[i].Apellidos;
        cin.ignore();
        getline(cin, DatosCliente[i].Apellidos);

        cout << "\t\tEdad    : ";
        cin >> DatosCliente[i].Edad;

        do
        {
            cout << "\t\tDNI    : ";
            cin >> DatosCliente[i].DNI;

            if (DatosCliente[i].DNI < 10000000 || DatosCliente[i].DNI>100000000)
            {
                cout << "\t\t [" << DatosCliente[i].DNI << "] ingresado no valido, porfavor ingrese denuevo..." << endl;

            }

        } while (DatosCliente[i].DNI < 10000000 || DatosCliente[i].DNI>100000000);

        cout << "\t\tDireccion  : ";
        cin.ignore();
        getline(cin, DatosCliente[i].Direccion);

        do
        {
            cout << "\t\tSexo    : ";
            cin >> DatosCliente[i].Sexo;

            DatosCliente[i].Sexo = toupper(DatosCliente[i].Sexo);

            if (!(DatosCliente[i].Sexo == 'F' || DatosCliente[i].Sexo == 'M'))
            {
                cout << "\t\t [" << DatosCliente[i].Sexo << "] ingresado no valido, porfavor ingrese denuevo..." << endl;

            }

        } while (!(DatosCliente[i].Sexo == 'F' || DatosCliente[i].Sexo == 'M'));


        do
        {
            cout << "\t\tCelular  : ";
            cin >> DatosCliente[i].Celular;

            if (DatosCliente[i].Celular < 100000000 || DatosCliente[i].Celular>1000000000)
            {
                cout << "\t\t [" << DatosCliente[i].Celular << "] ingresado no valido, porfavor ingrese denuevo..." << endl;

            }

        } while (DatosCliente[i].Celular < 100000000 || DatosCliente[i].Celular>1000000000);


        cout << "\t\t----------------------------------" << endl;
    }




}

void MenuInicio() {

    int OpcionProceso;


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




}


void VentaLibros()
{

}

void RecojoLibros()
{

}

