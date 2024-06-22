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
#include <regex> // Para usar expresiones regulares

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

struct Admin
{
    Persona DatosAdmin;
    int Codigo;
};

struct Libros
{
    int LibroCodigo;
    string Titulo;
    string Tipo; //Comic o manga
    float Costo;
    float Precio;
    string Local;//Sani o sanmi

};

/*Si hay 10 libros
del mismo título, cada uno tiene un código distinto.Puede tener en cuenta agregar algún otro dato
que considere necesario*/

void MenuInicio();
void RegistroDatos();
void MenuDeProceso(int CantidadCliente, Cliente** MatrizCliente);
void InicioSesionAdmin();
void CompraLibros(int CantidadCliente, Cliente** MatrizCliente);
void RecojoLibros(int CantidadCliente, Cliente** MatrizCliente);
void VentaLibros();

int main()
{

    MenuInicio();


    return 0;
}



void RegistroDatos()
{
    string pattern = R"((\w+)(\.?)(\w*)@(\w+)(\.(\w+))+)";
    // Crear un objeto regex con el patrón
    regex reg(pattern);

    int CantidadCliente = 1;
    Cliente** MatrizCliente;

    MatrizCliente = new Cliente*[CantidadCliente];

    for (int i = 0; i < CantidadCliente; i++)
    {
        MatrizCliente[i] = new Cliente[8];
    }
   
    cout << "\n\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t:   Ingrese sus datos                                                                    : " << endl;
    cout << "\t\t------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < CantidadCliente; i++)
    {
        cout << "\t\tNombre   : ";
        cin.ignore();
        getline(cin, MatrizCliente[i]->DatosCliente.Nombres); 
       
        cout << "\t\tApellidos  : ";
        cin.ignore();
        getline(cin, MatrizCliente[i]->DatosCliente.Apellidos);

        do
        {
            cout << "\t\tEdad    : ";
            cin >> MatrizCliente[i]->Edad;
            if (MatrizCliente[i]->Edad < 1 || MatrizCliente[i]->Edad>100)
            {
                cout << "\n\t\t [" << MatrizCliente[i]->Edad << "] ingresado no valido, porfavor ingrese denuevo..." << endl;
                cout << endl;

            }
        } while (MatrizCliente[i]->Edad < 1 || MatrizCliente[i]->Edad>100);

        do
        {
            cout << "\t\tDNI    : ";
            cin >> MatrizCliente[i]->DNI;

            if (MatrizCliente[i]->DNI < 10000000 || MatrizCliente[i]->DNI>100000000)
            {
                cout << "\n\t\t [" << MatrizCliente[i]->DNI << "] ingresado no valido, porfavor ingrese denuevo..." << endl;
                cout << endl;
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
                cout << "\n\t\t [" << MatrizCliente[i]->DatosCliente.Sexo << "] ingresado no valido, porfavor ingrese denuevo..." << endl;
                cout << endl;

            }

        } while (!(MatrizCliente[i]->DatosCliente.Sexo == 'F' || MatrizCliente[i]->DatosCliente.Sexo == 'M'));


        do
        {
            cout << "\t\tCelular  : ";
            cin >> MatrizCliente[i]->Celular;

            if (MatrizCliente[i]->Celular < 100000000 || MatrizCliente[i]->Celular>1000000000)
            {
                cout << "\n\t\t [" << MatrizCliente[i]->Celular << "] ingresado no valido, porfavor ingrese denuevo..." << endl;
                cout << endl;

            }

        } while (MatrizCliente[i]->Celular < 100000000 || MatrizCliente[i]->Celular>1000000000);

        do
        {
            cout << "\t\tCorreo   : ";
            cin >> MatrizCliente[i]->DatosCliente.Correo;
            if (!regex_match(MatrizCliente[i]->DatosCliente.Correo, reg))
            {
                cout << "\n\t\t [" << MatrizCliente[i]->DatosCliente.Correo << "] ingresado no valido, porfavor ingrese denuevo..." << endl;
                cout << endl;

            }
        } while (!regex_match(MatrizCliente[i]->DatosCliente.Correo, reg));

        cout << "\t\t------------------------------------------------------------------------------------------" << endl;
    }

    MenuDeProceso(CantidadCliente, MatrizCliente);

}

void InicioSesionAdmin() {



    cout << "\n\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t:   Ingrese sus datos                                                                    : " << endl;
    cout << "\t\t------------------------------------------------------------------------------------------" << endl;
    
    Admin** MatrizAdmin;
    MatrizAdmin = new Admin * [1];
    
    cout << "\t\tNombre   : ";
    cin.ignore();
    getline(cin, MatrizAdmin[i]->DatosAdmin.Nombres); 

    cout << "\t\tApellidos  : ";
    cin.ignore();
    getline(cin, MatrizAdmin[i]->DatosAdmin.Apellidos);  


}

void CompraLibros(int CantidadCliente, Cliente** MatrizCliente)
 {
    char OpcionModalidad;
   
    do
    {
        cout << "\n\t\t------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t:   Ingrese modalidad de compra                                                          : " << endl;
        cout << "\t\t:   Opcion (P) --> Presencial                                                            : " << endl;
        cout << "\t\t:   Opcion (W) --> Via WhatsApp                                                          : " << endl;
        cout << "\t\t: Ingresar opcion -> :"; cin >> OpcionModalidad;
        cout << "\t\t------------------------------------------------------------------------------------------" << endl;
        OpcionModalidad = toupper(OpcionModalidad);

        switch (OpcionModalidad)
        {
        case 'P':



            break;
        case 'W':
            cout << "\n\t\t------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t:   Contactar con el numero +51 1 6449191                                                : " << endl;
            cout << "\t\t------------------------------------------------------------------------------------------" << endl;


            break;
        default:

            if (!(OpcionModalidad=='P'|| OpcionModalidad =='W'))
            {
                cout << "\n\t\t[" << OpcionModalidad << "] ingresado no valido, porfavor ingrese deuevo...";
                cout << endl;
                system("pause");

            }
            break;
        }
        
    } while (!(OpcionModalidad == 'P' || OpcionModalidad == 'W'));
}

void RecojoLibros(int CantidadCliente, Cliente** MatrizCliente)
{

}
//Cliente

void VentaLibros()
{

}
//admin


void MenuInicio() {

    char OpcionMenuInicio;

    cout << "\n\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t: Bienvenido a la libreria Crisol                                                        :" << endl;
    cout << "\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t:  Porfavor elija una opcion              " << "\t\t\t\t\t\t :" << endl;
    cout << "\t\t:    Registro de Cliente (R)             " << "\t\t\t\t\t\t : " << endl;
    cout << "\t\t:    Inicio de sesion Admin (I)           " << "\t\t\t\t\t\t : " << endl;
    cout << "\t\t:    Cerrar ventana (C)                    " << "\t\t\t\t\t\t : " << endl;
    cout << "\t\t:  Ingresar opcion -> : " ;    cin >> OpcionMenuInicio;
    cout << "\t\t------------------------------------------------------------------------------------------" << endl;

    OpcionMenuInicio = toupper(OpcionMenuInicio);

    switch (OpcionMenuInicio)
    {
    case'R':
        RegistroDatos();
        break;
    case 'I':
        InicioSesionAdmin();
        break;
    case 'C':
        exit(0);
        break;
    default:
        cout << "\n\t\t[" << OpcionMenuInicio << "] ingresado no valido, porfavor ingrese deuevo...";
        cout<< endl;
        system("pause");
        system("cls");
        MenuInicio();
        break;
    }
} //listo
//listo


void MenuDeProceso(int CantidadCliente, Cliente** MatrizCliente) {

    int OpcionProceso;

    cout << "\n\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t: Bienvenido al la libreria UPC!!                                                    :" << endl;
    cout << "\t\t:   Ingrese el proceso que desee realizar                                              :" << endl;
    cout << "\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t:   Opcion 1 --> Compra de libro(s)                                                    : " << endl;
    cout << "\t\t:   Opcion 2 --> Recojo de libro(s)                                                    : " << endl;
    cout << "\t\t: Ingresar opcion -> :"; cin >> OpcionProceso;
    cout << "\t\t------------------------------------------------------------------------------------------" << endl;
    OpcionProceso = toupper(OpcionProceso);


    switch (OpcionProceso)
    {
    case 1:

        CompraLibros(CantidadCliente, MatrizCliente);

        break;

    case 2:

        RecojoLibros(CantidadCliente, MatrizCliente);

        break;



    default:

        cout << "\n\t\t[" << OpcionProceso << "] ingresado no valido, porfavor ingrese deuevo...";
        cout << endl;

        break;
    }




}




void LimpiarMemoria(int CantidadCliente, Cliente** MatrizCliente) {

    for (int i = 0; i < CantidadCliente; i++)
    {
        delete[] MatrizCliente[i];

    }
    
    delete[] MatrizCliente;
}

void FuncionContinuar(int CantidadCliente, Cliente** MatrizCliente) {
    
}