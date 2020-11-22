#include<iostream>
#include<cstdlib>
#include<string.h>
#include<queue>
#define maxchar 20

using namespace std;

struct nodo{

    int codigo;     
    char nombres[maxchar]; 
    char apellidos[maxchar];
    char direccion[maxchar];
    char Dui[maxchar];
    char Nit[maxchar];
    int telefono;
    float aperturadinero;
    float saldonuevo;
    float retiro;
    struct nodo *siguiente;

};

struct segurovida{
    int codigo;
    char nombres[maxchar];
    char apellidos[maxchar];
    char direccion[maxchar];
    char dui[maxchar];
    char nit[maxchar];
    char nombreEmpresa[maxchar];
    int tiempodeTrabajo;
    float  sueldo;
    float descuento;
    float totalseguro;
    int telefono;
    float integrantesFamilia;

    struct segurovida *siguiente;
};
struct Cremesas{
 char nombres[maxchar];
 char apellidos[maxchar];
 char Dui[maxchar];
 float retiro;
};


typedef struct segurovida SeguroLista;
typedef struct nodo PLista;
typedef struct Cremesas Rem;
void registrar_clientes();
void actualizar_clientes();
void mostrar_clientes();
void registrar_clientesSeguro();
void mostrar_clientesSeguro();
void consultacuenta_clientes();
void consultacuenta_clientesseguro();

PLista *lista;
SeguroLista *listaseguro;
queue<Rem>remesa;

/*-------------------------- FUNCION REGISTRAR CLIENTE CUENTA BANCARIA ---------------- */
void registrar_clientes(){
    float aperturadinero;
    PLista *t,*q = new(struct nodo);

    cout<<"\n\n\t\t[  Registro de Nuevo Cliente  ]\n";
    cout<<"\t\t-------------------------------------";
    cout<<"\n\t Datos del Cliente ";
    cin.ignore();cout<<"\n\n\t  Codigo de Cliente:";cin>>q->codigo;
    cin.ignore();cout<<"Nombres del Cliente:";cin.getline(q->nombres,maxchar);
    cout<<"Apellidos del Cliente:";cin.getline(q->apellidos,maxchar);
    cout<<"Direccion del Cliente:";cin.getline(q->direccion,maxchar);
    cout<<"Dui del Cliente:";cin.getline(q->Dui,maxchar);
    cout<<"Nit del Cliente:";cin.getline(q->Nit,maxchar);
    cout<<"Telefono del Cliente:";cin>>q->telefono;
    cout<<"Aperturar cuenta con $:";cin >>q->aperturadinero;
    if(aperturadinero>=25) cout << " Usted aperturo su cuenta con $ ";

    system("cls");

    q->siguiente = NULL;

    if(lista==NULL){

        lista = q;

    } else {

        t = lista;

        while(t->siguiente!=NULL){

                t = t->siguiente;
        }

        t->siguiente = q;

    }
}

/*---------------------------- FUNCION ACTUALIZAR DATOS DE CLIENTE CUENTA BANCARIA ---------------------- */
void actualizar_clientes(){

    int cod=0;
    int x = 0;
    PLista *q;
    q=lista;

    cout<<"\n\n\n\t Actualizar registro de Cliente";
    cout<<"\n\n\t   Ingrese el Codigo del Cliente:"; cin>>cod;

    while(q!=NULL){

            if(q->codigo==cod){
                system("cls");
                cout<<"\n\t Datos del Cliente  ";
                cout<<"\n\t--------------------";
                cout<<"\n\n\t  Codigo del Cliente : "<<q->codigo<<endl;
                cout<<"\n\t Nombres del Cliente : "<<q->nombres<<endl;
                cout<<"\t Apellidos del Cliente : "<<q->apellidos<<endl;
                cout<<"\t Direccion del Cliente : "<<q->direccion<<endl;
                cout<<"\t Telefono del Cliente : "<<q->telefono<<endl;
                cout<<"\t  Saldo Actual $"<<q->aperturadinero<<endl;

                cout<<"\n\t\t[    Especifique campos a Actualizar   ]\n";
                cout<<"\t\t-------------------------------------------\n\n";
                cout<<" 1. Nombres                       "<<endl;
                cout<<" 2. Apellidos                     "<<endl;
                cout<<" 3. Direccion                     "<<endl;
                cout<<" 4. Telefono                      "<<endl;
                cout<<" 5. Saldo                         "<<endl;
                cout<<" 6. Salir                         "<<endl;

                cout<<"\n Ingrese opcion : ";
                cin>>x;

                switch(x){

                    case 1: cout<<"\n\n\t Ingrese Nombres del Cliente :";
                            cin.ignore(); cin.getline(q->nombres,maxchar);
                            break;

                    case 2: cout<<"\n\n\t Ingrese Apellidos del Cliente :";
                            cin.ignore(); cin.getline(q->apellidos,maxchar);
                            break;

                    case 3: cout<<"\n\n\t Ingrese Direccion del Cliente :";
                            cin.ignore(); cin.getline(q->direccion,maxchar);
                            break;

                    case 4: cout<<"\n\n\t Ingrese Telefono del Cliente :";
                            cin>>q->telefono;
                            break;
                    case 5: cout<<"\n\n\t Ingrese Nuevo Saldo en Cuenta $";
                            cin>>q->aperturadinero;

                    default: cout<<"\n Ingrese una opcion valida...\n"; break;

                }
                cout<<"\n\n\t Registro Actualizado...!!!!!\n";

                return;

            }else {


                q=q->siguiente;

        }

    }
    if(q==NULL)
        cout<<"\n\t Codigo Incorrecto...!!\n";
}