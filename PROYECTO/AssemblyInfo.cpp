#include "pch.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <string> 
#include <chrono>
#include <iomanip>


using namespace std;

struct Persona
{
    string Nombres;
    string Apellidos;
    char Sexo;
    string Correo;

};

struct Cliente
{
    Persona DatosCliente;
    string Direccion;
    int Edad;
    int DNI; //último numero dni por ejemplo "78475745" recoge el "5" entonces lo recoge a partir de las 5pm 
    //o estara disponible a las 5pm la hora de envio.
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

void MenuInicio();

int main()
{

    MenuInicio();


    return 0;
}

void MenuInicio() {

    cout << "\n\t\t ䷃ ䷃";
    cout << "\n\t\tBienvenido a la libreria Crisol " << endl;

}

void RegistroDatos()
{
    int CantidadCliente = 1;
    Cliente** MatrizCliente;  

    cout << "\t\tIngrese sus datos: " << endl;
    cout << "\t\t----------------------------------" << endl;

    MatrizCliente = new Cliente*[CantidadCliente];

    for (int i = 0; i < CantidadCliente; i++)
    {
        cout << "\t\tNombre   : ";
        cin.ignore();
        getline(cin, MatrizCliente[i]->DatosCliente.Nombres);  
       
        cout << "\t\tApellidos  : ";
        cin.ignore();
        getline(cin, MatrizCliente[i]->DatosCliente.Apellidos);

        cout << "\t\tEdad    : ";
        cin >> MatrizCliente[i]->Edad; 

        do
        {
            cout << "\t\tDNI    : ";
            cin >> MatrizCliente[i]->DNI;

            if (MatrizCliente[i]->DNI < 10000000 || MatrizCliente[i]->DNI>100000000)
            {
                cout << "\t\t [" << MatrizCliente[i]->DNI << "] ingresado no valido, porfavor ingrese denuevo..." << endl;

            }

        } while (MatrizCliente[i]->DNI < 10000000 || MatrizCliente[i]->DNI>100000000);

        cout << "\t\tDireccion  : ";
        cin.ignore();
        getline(cin, MatrizCliente[i]->Direccion);

        do
        {
            cout << "\t\tSexo    : ";
            cin >> MatrizCliente[i]->DatosCliente.Sexo;

            MatrizCliente[i]->DatosCliente.Sexo = toupper(MatrizCliente[i]->DatosCliente.Sexo);

            if (!(MatrizCliente[i]->DatosCliente.Sexo == 'F' || MatrizCliente[i]->DatosCliente.Sexo == 'M'))
            {
                cout << "\t\t [" << MatrizCliente[i]->DatosCliente.Sexo << "] ingresado no valido, porfavor ingrese denuevo..." << endl;

            }

        } while (!(MatrizCliente[i]->DatosCliente.Sexo == 'F' || MatrizCliente[i]->DatosCliente.Sexo == 'M'));


        do
        {
            cout << "\t\tCelular  : ";
            cin >> MatrizCliente[i]->Celular;

            if (MatrizCliente[i]->Celular < 100000000 || MatrizCliente[i]->Celular>1000000000)
            {
                cout << "\t\t [" << MatrizCliente[i]->Celular << "] ingresado no valido, porfavor ingrese denuevo..." << endl;

            }

        } while (MatrizCliente[i]->Celular < 100000000 || MatrizCliente[i]->Celular>1000000000);

        do
        {
            cout << "\t\tCorreo   : ";
            cin >> MatrizCliente[i]->DatosCliente.Correo;
            if (MatrizCliente[i]->DatosCliente.Correo!="@")
            {
                cout << "\t\t [" << MatrizCliente[i]->DatosCliente.Correo << "] ingresado no valido, porfavor ingrese denuevo..." << endl;

            }
        } while (MatrizCliente[i]->DatosCliente.Correo != "@");

        cout << "\t\t----------------------------------" << endl;
    }



}

void MenuDeProceso() {

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

void LimpiarMemoria(int CantidadCliente, Cliente** MatrizCliente) {

    for (int i = 0; i < CantidadCliente; i++)
    {
        delete[] MatrizCliente[i];

    }
    
    delete[] MatrizCliente;
}

