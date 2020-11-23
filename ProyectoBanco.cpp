#include<iostream>
#include<cstdlib>
#include<string.h>
#include<queue>
#define maxchar 20

using namespace std;

/*--------------------- DEFINIENDO ESTRUCTURA NODO, LO CUAL CONTENDRA LA PILA  ------------ */
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

/*--------------------- DEFINIENDO ESTRUCTURA SEGURO DE VIDA, LO CUAL CONTENDRA LA PILA  ------------ */
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

/*--------------------- DEFINIENDO ESTRUCTURA DE REMESAS, LO CUAL CONTENDRA LA PILA  ------------ */
struct Cremesas{
 char nombres[maxchar];
 char apellidos[maxchar];
 char Dui[maxchar];
 float retiro;
};


typedef struct segurovida SeguroLista;
typedef struct nodo PLista;
typedef struct Cremesas Rem;

/*------------------- PROTOTIPOS DE FUNCIONES -------------------- */
void registrar_clientes();
void actualizar_clientes();
void mostrar_clientes();
void registrar_clientesSeguro();
void mostrar_clientesSeguro();
void consultacuenta_clientes();
void consultacuenta_clientesseguro();

/*------------------- CREACION DE PUNTEROS GLOBALES ----------------------- */
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

/*------------------------------ FUNCION MOSTRAR CLIENTES CUENTA BANCARIA -----------------------*/
void mostrar_clientes(){

    int i=1;
    PLista *q;
    q=lista;

    while(q!=NULL){

        cout<<"\n\t Datos del Cliente ["<<i<<"] ";
        cout<<"\n\t------------------------";
        cout<<"\n\n\t Codigo del Cliente  : "<<q->codigo<<endl;
        cout<<"\n\t   Nombres del Cliente : "<<q->nombres<<endl;
        cout<<"\t     Apellidos del Cliente : "<<q->apellidos<<endl;
        cout<<"\t     Direccion del Cliente : "<<q->direccion<<endl;
        cout<<"\t     Dui del Cliente : " <<q->Dui<<endl;
        cout<<"\t     Nit del Cliente : " <<q->Nit<<endl;
        cout<<"\t     Telefono del Cliente : "<<q->telefono<<endl;
        cout<<"\t     Saldo de cuenta $"<<q->aperturadinero<<endl;

        q=q->siguiente;

        i++;
    }

}

/*------------------------- FUNCION REGISTAR CLIENTE CUENTA SEGURO DE VIDA ------------------- */
void registrar_clientesSeguro(){
    float descuento;
    float sueldo;
    float integrantesFamilia;
    float totalseguro;
    float iva;

    SeguroLista *l,*p = new(struct segurovida);

    cout<<"\n\n\t\t[  Registro de Nuevo Cliente Seguro de Vida ]\n";
    cout<<"\t\t---------------------------------------------------";
    cout<<"\n\t Datos del Cliente ";
    cin.ignore();cout<<"\n\t  Codigo de Cliente:"; cin>>p->codigo;
    cin.ignore();cout<<"Nombres del Cliente:"; cin.getline(p->nombres,maxchar);
    cout<<"Apellidos del Cliente:"; cin.getline(p->apellidos,maxchar);
    cout<<"Direccion del Cliente:"; cin.getline(p->direccion,maxchar);
    cout<<"Dui del Cliente:"; cin.getline(p->dui,maxchar);
    cout<<"Nit del Cliente:"; cin.getline(p->nit,maxchar);
    cout<<"Telefono del Cliente:"; cin>>p->telefono;
    cout<<"Nombre de la Empresa:"; cin>>p->nombreEmpresa;
    cout<<"Tiempo de Trabajo en la Empresa (en meses):"; cin>>p->tiempodeTrabajo;
    cout<<"\n\t    Numero de integrantes familia:"; cin>>p->integrantesFamilia;
    cout<<"Sueldo:"; cin>>p->sueldo;
        p->totalseguro = (p->sueldo) / (p->integrantesFamilia);
        p->descuento = (p->sueldo) - 8;
    cin.ignore();
    cout<<"\t   Su tipo de seguro es: ";
    if ((p->sueldo)>=1500)
    {
        cout << "Tipo A.";
    }else if ((p->sueldo)>=1000)
    {
        cout << "Tipo B.";
    }else if ((p->sueldo)<1000)
    {
        cout << "Tipo C.";
    }


    p->siguiente = NULL;

    if(listaseguro==NULL){

        listaseguro = p;

    } else {

        l = listaseguro;

        while(l->siguiente!=NULL){

                l = l->siguiente;
        }

        l->siguiente = p;

    }
}

/*------------------------- FUNCION MOSTRAR CLIENTE CUENTA SEGURO DE VIDA ------------------- */
void mostrar_clientesSeguro(){

    int i=1;
    SeguroLista *p;
    p=listaseguro; 
    while(p!=NULL){

        cout<<"\n\t Datos del Cliente ["<<i<<"] ";
        cout<<"\n\t---------------------------";
        cout<<"\n\n\tCodigo del Cliente  : "<<p->codigo<<endl;
        cout<<"\n\tNombres del Cliente : "<<p->nombres<<endl;
        cout<<"\tApellidos del Cliente : "<<p->apellidos<<endl;
        cout<<"\tDireccion del Cliente : "<<p->direccion<<endl;
        cout<<"\tDui del Cliente : " <<p->dui<<endl;
        cout<<"\tNit del Cliente : " <<p->nit<<endl;
        cout<<"\tTelefono del Cliente : " <<p->telefono<<endl;
        cout<<"\tNombre de la Empresa :" <<p->nombreEmpresa<<endl;
        cout<<"\tTiempo de Trabajo Empresa :" <<p->tiempodeTrabajo<<endl;
        cout<<"\tSueldo :" <<p->sueldo<<endl;
        cout<<"\tIntegrantes Familia :" <<p->integrantesFamilia<<endl;
        cout<<"\t     Total de seguro: "<<p->totalseguro<<endl;
        p=p->siguiente;

        i++;
    }

}

/*------------------------- FUNCION CONSULTA CLIENTE CUENTA BANCARIA ------------------- */
void consultacuenta_clientes(){
    float saldonuevo;
    float extra;
    float aperturadinero;
    int codigo = 0;
    int x = 0;
    float retiro;
    PLista *q;
    q = lista;

    cout<<"\n\n\n\t Consulta Cuenta Actual Cliente";
    cout<<"\n\n\t   Ingrese el Codigo del Cliente:"; cin>>codigo;

    while(q!=NULL){

            if(q->codigo==codigo){
                system("cls");
                cout<<"\n\t Datos del Cliente  ";
                cout<<"\n\t--------------------";
                cout<<"\n\n\t  Codigo del Cliente : "<<q->codigo<<endl;
                cout<<"\n\t Nombres del Cliente : "<<q->nombres<<endl;
                cout<<"\t Apellidos del Cliente : "<<q->apellidos<<endl;
                cout<<"\t  Saldo Actual $"<<q->aperturadinero<<endl;

                cout<<"\n\t\t[    Actualizar Saldo Cuenta   ]\n";
                cout<<"\t\t----------------------------------------\n\n";
                cout<<" 1. Ingresar dinero en cuenta                      "<<endl;
                cout<<" 2. Retirar dinero de la cuenta                    "<<endl;
                cout<<" 3. Saldo                                            "<<endl;
                cout<<" 4. Salir                         "<<endl;

                cout<<"\n Ingrese opcion : ";
                cin>>x;

                switch(x){
                case 1: cout<<"\n\n\t Ingrese dinero a la cuenta $";
                        cin>>extra;
                        q->aperturadinero += extra;
                        cout << " Dinero en cuenta $"<< q->aperturadinero;
                        cout<<"\n\n\t Registro Actualizado...!!!!!\n";
                       
                break;
                case 2: cout<<"\n\n\t Retirar dinero de la cuenta $";
                        cin>>retiro;
                        if(retiro>q->aperturadinero){
                            cout << " No tiene suficientes fondos en su cuenta ";
                        }
                        else{
                            q->aperturadinero -= retiro;
                            cout << " Dinero en cuenta $" << q->aperturadinero;
                        }
                        cout<<"\n\n\t Registro Actualizado....!!!!\n";
                        
                break;
                case 3: cout<< "Su Saldo actual es $" << q->aperturadinero;
                break;
                default: cout<<"\n Ingrese una opcion valida...\n"; break;

                }
                return;

            }else {


                q=q->siguiente;

        }

    }
    if(q==NULL)
        cout<<"\n\t Codigo Incorrecto...!!\n";
}

/*------------------------- FUNCION CONSULTA CLIENTE CUENTA SEGURO DE VIDA ------------------- */
void consultacuenta_clientesseguro(){
    float saldonuevo;
    float extra;
    float aperturadinero;
    int codigo, x;
    float retiro;
    SeguroLista *p;
    p=listaseguro;

    cout<<"\n\n\n\t Consulta Cuenta Actual Cliente";
    cout<<"\n\n\t   Ingrese el Codigo del Cliente:"; cin>>codigo;

    while(p!=NULL){

            if(p->codigo==codigo){
                system("cls");
                cout<<"\n\t Datos del Cliente  ";
                cout<<"\n\t--------------------";
                cout<<"\n\n\t  Codigo del Cliente : "<<p->codigo<<endl;
                cout<<"\n\t Nombres del Cliente : "<<p->nombres<<endl;
                cout<<"\t Apellidos del Cliente : "<<p->apellidos<<endl;
                cout<<"\t  Sueldo $"<<p->sueldo<<endl;

                cout<<"\n\t\t[    Actualizar Saldo Cuenta   ]\n";
                cout<<"\t\t-------------------------------------------\n\n";
                cout<<" 1. Mostrar sueldo con descuento"<<endl;
                cout<<" 2. Actualizar cantidad de miembros en la familia"<<endl;
                cout<<" 3. Mostrar cantidad de seguro"<<endl;

    cout<<"\n Ingrese opcion : ";
                cin>>x;

                switch(x){
                    case 1:{
                        cout << "El sueldo con descuento es igual a $" << p->descuento;
                    } 
                    break;
                    case 2: {
                        cout << "Cantidad de miembros de familia: "; 
                        cin>> p->integrantesFamilia;
                        p->totalseguro = (p->sueldo) / (p->integrantesFamilia);
                        p->descuento = (p->sueldo) - 8;
                        cout<<"\n\t Registro Actualizado...!!!!!\n";
                    }
                    break;
                     case 3:{
                        cout << "La cantidad que corresponde a su seguro es $" << p->totalseguro << ".";
                     }
                     break;
                    default: cout<<"\n Ingrese una opcion valida...\n"; break;

                }
                

                return;

            }else {


                p=p->siguiente;

        }

    }
    if(p==NULL)
        cout<<"\n\t Codigo Incorrecto...!!\n";
}

/*------------------------- FUNCION MOSTRAR TICKET REMESAS  ------------------- */
void mostrarremesa(queue<Rem>remesas){

    queue <Rem> clone=remesas;
    cout<<"[----- ticket de retiro de remesa -----]"<<endl;

     while(!clone.empty()){
         cout<<"Nombre: ";
        cout << clone.front().nombres<< endl;
        cout<<"Apellido: ";
        cout<<clone.front().apellidos<<endl;
        cout<<"Dui: ";
        cout<<clone.front().Dui<< endl;
        cout<<"retiro $";
        cout<<clone.front().retiro<< endl;
      clone.pop();
     }
}

/*------------------------- FUNCION LLENAR DATOS DE REMESAS  ------------------- */
void llenaremesas(queue <Rem> &remesa){
    bool continuar= true;
    if(continuar){

    cout<<"[----- Retiro de remesas -----]"<<endl;
    cout<<"ingrese datos: "<<endl;
        Rem remesas;
        cout<<"Nombre: ";
        cin.ignore();
        cin.getline(remesas.nombres,maxchar);
        cout<<"Apellidos: ";
        cin.getline(remesas.apellidos,maxchar);
        cout<<"Dui: ";
        cin>> remesas.Dui;
        cout<<"Cantidad a retirar:$ ";
        cin>>remesas.retiro; 
        remesa.push(remesas);
        cout<<endl;
        cout<<endl;
        mostrarremesa(remesa); 
       continuar=false;
  }
}


/*------------------- FUNCION MAIN PRINCIPAL ------------------------ */
int main(){
    
    lista = NULL;
    listaseguro = NULL;

    bool continuar = true;
    do{
    int opcion = 0;
    cout<<"\n\t\t[    Operaciones Bancarias     ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. Apertura de Cuenta Bancaria                          "<<endl;
    cout<<" 2. Apertura de Seguros de Vida                          "<<endl;
    cout<<" 3. Consulta de Saldo Cuenta Bancaria Seguro de vida     "<<endl;
    cout<<" 4. Consulta de Cuenta Actual                            "<<endl;
    cout<<" 5. Retiro de remesa                                     "<<endl;
    cout<<" 6. Salir                                                "<<endl;

    cout<<"\n Ingrese opcion : ";
    cin >> opcion;
    
    switch (opcion){
    case 1:{
        bool status = true;
        int opcion1 = 0;
        while(status){
        cout<<"\n\t\t[    Apertura de Cuenta Bancaria    ]\n";
        cout<<"\t\t----------------------------------------\n\n";
        cout<<" 1. Registrar Cliente                          "<<endl;
        cout<<" 2. Actualizar Cliente                        "<<endl;
        cout<<" 3. Mostrar Lista de Cliente                   "<<endl;
        cout<<" 4. Regresar                                      "<<endl;

        cout<<"\n Ingrese opcion : ";
        cin >> opcion1;

        switch(opcion1){
            case 1: registrar_clientes();
            break;
            case 2:{
                if(lista==NULL){

                        cout<<"\n\tNo Hay Clientes Registrados.....!!!!\n";

                    }else{

                        actualizar_clientes();

                    }
            }
            break;
            case 3:{
                if(lista==NULL){

                            cout<<"\n\tNo Hay Clientes Registrados.....!!!!\n";

                        }else{

                            mostrar_clientes();
                        }
            }
            break;
            case 4: status = false;
            break;
            default: cout << " Opcion ingresada No valida"<< endl;
            break;
        }
        }
    }
        break;
    case 2: {
        bool status = true;
        int opcion3=0;
        while(status){
        cout<<"\n\t\t[    Apertura de Seguros de Vida   ]\n";
        cout<<"\t\t---------------------------------------\n\n";
        cout<<" 1. Registrar Cliente                          "<<endl;
        cout<<" 2. Mostrar Lista de Cliente                   "<<endl;
        cout<<" 3. Salir                                      "<<endl;

        cout<<"\n Ingrese opcion : ";
        cin >> opcion3;
            switch (opcion3){
                case 1:registrar_clientesSeguro();
                break;
                case 2:mostrar_clientesSeguro();
                break;
                case 3: status = false;
                break;
                default: cout << " Opcion ingresada No valida"<< endl;
                break;
            }
        }
    }
        break;
    case 3: consultacuenta_clientesseguro();
        break;
    case 4:consultacuenta_clientes();
        break;

    case 5: llenaremesas(remesa);
    break;

    case 6: continuar = false;
    }
    }while(continuar);
    return 0;
}
