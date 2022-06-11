// libreria en uso
#include<iostream>
#include<fstream>
using namespace std;

// declaracion de la estuctura junto a los nodos
typedef struct lista
{
  // campo de informacio que se va a a gregar a las listas 
  string nombre;
  int codigo ; 
  int cantidad;
  float precio;
  // campo de vinulacion alas listas
  struct lista *siguiente;// tipo de apuntador que va a ligar los nodos  de las listas 

}nodo;// declaramos un tipo de dato de la estructura llamadas nodo
 
int main(){
  int op;
 nodo *p;// primer nodo de la lista
 nodo *dato_lista = new nodo();
 // funciones de menu
 int menu(void);
 int opAgregar(void);
 int menuImprime(void);
 int busquedaLista();
 // funciones de la lista
 // lleva la lista 
 nodo *creaInicio(nodo*);// crea el primer nodo de la lista returna p porue p se esta movinedo
 void insertaFinalList(nodo *,nodo *);// inserta un nodo al fial de la lista 
 // funciones que imprimen la lista
 void ImprimeIterativo(nodo *);//Imprime la lista con un bucle while
 void imprimeRecursivo(nodo *);// imprime la lista llamandose a ella misma
 // funcion que busca dentro de la lista algun dato
 void busquedaIterativa(nodo *);
 void busquedaRecursiva(nodo *);
 // leer lista desde el archivo
 //void leerLista(nodo*);
 // funcion que guarda la lsita en un archivo
 void guardarLista(nodo *);

 do{  
  op = menu();
  switch (op)
  {
   case 1:
    op=opAgregar();
    switch (op)
    {
     case 1:
       system("cls");
       p=creaInicio(p);// declaramos a crea inicio
       break;
     case 2:
       system("cls");
       insertaFinalList(p,dato_lista);
      break;
    }// fin swhit 
   break;
   case 2:
      op=menuImprime();
      switch (op){
       case 1:
         ImprimeIterativo(p);  
         system("pause"); 
         break;
       case 2:
         imprimeRecursivo(p); 
         system("pause"); 
         break;
       default:
         cout<<"\n\nOPCION INVALIDA";
         break;
      }
    break;
  case 3:system("cls");
      op=busquedaLista();
      switch(op){
        case 1:
         busquedaIterativa(p); 
         system("cls");
         break;
        case 2:
         busquedaRecursiva(p);  
         system("cls");
         break;
        default:
         cout<<"\n\nOPCION INVALIDA"; 
         break;
      }
      break;
   case 4:
    guardarLista(p);
    system("C:\\Users\\jason\\Downloads\\CodigosVsCode\\ProgramacionII\\LABORATORIO\\datos_de_la_lista.dat");
    break;
   default:
    cout<<"\n\nOPCION INVALIDA";
    break;
  } 
 }while(op !=4);
 
  return 0;
}
// opciones de agregar nodo en diferentes posiciones
int opAgregar(void)
{
  int x;
  cout<<"\n\tCREAR LISTA CON : "<<endl;
  cout<<"\t1. INSERTA INICIO "<<endl;
  cout<<"\t2. INSERTA FINAL"<<endl;
  cout<<"\t3. INSERTA EN X POSICION  ";
  cin>>x;
  return x;
}

//MENU DE IMPRESION 
int menuImprime(){
  int x;
  cout<<"\n\t1. IMPRIMIR CON ITERATIVO "<<endl;
  cout<<"\t2. IMPRIMIR CON RECURSIVO ";
  cin>>x;
  return x;
}
// MENU DE BUSQUEDAS EN LA LISTA  
int busquedaLista(){
  int x;
  cout<<"\n\t1. BUSQUEDA ITERATIVA "<<endl;
  cout<<"\t2. BUSQUEDA RECURSIVA ";
  cin>>x;
  return x;
}
// MENU PRINCIPAL  
int menu(void)
{
 int x;
  cout<<"\n\t\t*** SISTEMA DE INVENTARIO  ***\n"<<endl;
	cout<<"\t\t  1. CREAR INVENTARIO"<<endl;
	cout<<"\t\t  2. VER INVENTARIO"<<endl;
	cout<<"\t\t  3. VENTA O FACTURACION"<<endl;
	cout<<"\t\t  4. CERRA Y GUARDAR"<<endl;
	cout<<"\t\t  > INGRESA UNA OPCION : ";
  cin>>x;

  return x; 
}
 
/*
 * declaracion de la funcion que va a crear un nodo al inico de la lista 
*/
nodo *creaInicio( nodo *p) // crea cada nuevo nodo al inicio de la lista 
{ 
  p = new nodo(); // aqui recervamos memoria en la RAM a inicio
  char sn[3];
  nodo *q;

  // Leemos el campo de informacion que vamos a almacenar en la lista 
  cout<<"      *** INTRODUCCION DE MERCANCIA ***    "<<endl;
	cout<<"\t1. Codigo del Producto   : ";
  cin>>p->codigo;
	cout<<"\t2. Nombre del Producto   : ";
  cin>>p->nombre;
	cout<<"\t3. Cantidad del producto : ";
  cin>>p->cantidad;
	cout<<"\t4. Precio del producto   : ";
	cin>>p->precio;
  //definimos que el ultimo nodo de la lista esta vacia (NULL)
  p->siguiente= NULL; 
  cout<<"\n Exito!\n Producto Agregado al inicio de la lista \n\n"<<endl;
  cout<<"\n   > Agregar (s/n) < ";cin>>sn;
 system("cls");
  while(sn[0] == 's'|| sn[0]=='S'||sn[0]=='1')
  { 
   q= new nodo(); // reservamos memoria al siguiente nodo (despues)
   cout<<"      *** INTRODUCCION DE MERCANCIA ***    "<<endl;
	 cout<<"\t1. Codigo del Producto   : ";
   cin>>q->codigo;
	 cout<<"\t2. Nombre del Producto   : ";
   cin>>q->nombre;
	 cout<<"\t3. Cantidad del producto : ";
   cin>>q->cantidad;
	 cout<<"\t4. Precio del producto   : ";
	 cin>>q->precio;
   q->siguiente = p;
   p= q;
  cout<<"\n Exito!\n Producto Agregado al inicio de la lista \n\n"<<endl;
	 cout<<"\n   > Agregar (s/n) < ";cin>>sn;
   system("cls");
	 
  }
  
  return p;
}

/* 
 * DEFINICON DE LA FUNCION QUE INSERTARA UN NODO "X" POSICION 
*/

/* 
 * definicion de la funcion agregar un nodo al final de la lista 
*/
void insertaFinalList(nodo *p, nodo * datos_lista)
{
  char sn[3];
 nodo *t;//Creamos el nodo que insertariamos al final de la lista 
 nodo *q;
 t = p;// el nodo final va ser igual al primer nodo
  cout<<"      *** INTRODUCCION DE MERCANCIA ***    "<<endl;
	cout<<"\t1. Codigo del Producto   : ";
  cin>>datos_lista->codigo;
	cout<<"\t2. Nombre del Producto   : ";
  cin>>datos_lista->nombre;
	cout<<"\t3. Cantidad del producto : ";
  cin>>datos_lista->cantidad;
	cout<<"\t4. Precio del producto   : ";
	cin>>datos_lista->precio;
  cout<<"\n Exito!\n Producto Agregadoal final de la lista \n\n"<<endl;
  cout<<"\n   > Agregar (s/n) < ";cin>>sn;
 system("cls");
  while(sn[0] == 's'|| sn[0]=='S'||sn[0]=='1')
  { 
   cout<<"      *** INTRODUCCION DE MERCANCIA ***    "<<endl;
	 cout<<"\n 1. Codigo del Producto   : ";
   cin>>datos_lista->codigo;
	 cout<<"\t2. Nombre del Producto   : ";
   cin>>datos_lista->nombre;
	 cout<<"\t3. Cantidad del producto : ";
   cin>>datos_lista->cantidad;
	 cout<<"\t4.Precio del producto   : ";
	 cin>>datos_lista->precio;
   cout<<"\n Exito!\n Producto Agregado al final de la lista \n\n"<<endl;
	 cout<<"\n   > Agregar (s/n) < ";cin>>sn;
   system("cls");

  }

 while(t->siguiente != NULL){// minetas nodo sea diferente de null oseas que la lista tenga datos
  t =  t->siguiente;
 } 
 q = new nodo();// reservamos memoria a q
 q= datos_lista;
 q->siguiente = NULL;
 t->siguiente = q;

 
}

/* 
  definimos la funcion de insertar en x posicion  
*/
nodo * insertaXpOsiscion(nodo * p){
 


  return p;
}



/* 
   DEFINICIONES PARA LAS FUNCION DE BUSQUEDA 
*/
void busquedaIterativa(nodo *p){
 bool band = false;
 int codeTemp,posicion=0,cantTemp;
 float total,itbms;
 nodo *q = new nodo();
 q = p;
 cout<<"\n\n        *** BUSCAR PRODUCTO ***\n"<<endl; 
  cout<<"\nCodigo el Producto: "; cin>>codeTemp;
  while (q != NULL )
  {
    if(q->codigo!=codeTemp)
    {
      band = false;  
    }
    else{
      cout<<"\n Ingresa la Cantidad a Vender: ";
      cin>>cantTemp;
	   if(cantTemp>q->cantidad) //si no hay la  cantidad buscada
	   {
	    cout<<"\nUPSSS!!!\nLa Cantidada Deseada no esta Disponible "<<endl;
	  	system("pause");
	   }
     else // si hay la cantidad disponible imprime...
	   {
      q->cantidad += -cantTemp;
      itbms=cantTemp*0.07;
      total = cantTemp*q->precio+itbms;
      posicion ++;
      cout<<"\n\t\t-->  Nombre   : "<<q->nombre;         
      cout<<"\n\t\t-->  Precio   : "<<q->precio;         
	    cout<<"\n\t\t-->  Codigo   : "<<q->codigo;                 
	    cout<<"\n\t\t-->  Cantidad : "<<cantTemp<<endl;
	    cout<<"\n\t\t-->  Precio a Pagar   : "<<total<<" $\n"<<endl;          
      cout<<"\tEl producto "<<q->nombre<<" se encuentra en la poscision "<<posicion<<" de la lista "<<endl;
      cout<<"\n\tUnidades Disponibles: "<<q -> cantidad<<endl;  
      system("pause");
     }// fin else 2
    }// fin else 1
    q= q->siguiente;
  }// fin while 
  if (band = false)
  {
    cout<<"\n PRODUCTO NO ENCONTRADO EN LA LISTA "<<endl;
    system("pause");
  }
}
// busqueda recursiva
void busquedaRecursiva(nodo *p)
{
  bool band = false;
 int codeTemp,posicion =0,cantTemp;
 float total,itbms;
  if (p != NULL){
   cout<<"\n\n        *** BUSCAR PRODUCTO ***\n"<<endl; 
   cout<<"\nCodigo el Producto: "; cin>>codeTemp;
    if(p->codigo!=codeTemp)
    {
     cout<<"\n PRODUCTO NO ENCONTRADO EN LA LISTA "<<endl;
     system("pause");
    }
    else{ 
      cout<<"\n Ingresa la Cantidad a Vender: ";
     cin>>cantTemp;
	   if(cantTemp>p->cantidad)// si la canidad es mayor a la deseada le dice que no hay
	   {
	    cout<<"\nUPSSS!!!\nLa Cantidada Deseada no esta Disponible "<<endl;
	  	system("pause");
	   }// fin if 2
     else
	   {
      p->cantidad += -cantTemp;
      itbms=p->cantidad*0.07;
      total = p->cantidad*cantTemp+itbms;
      posicion ++;
      cout<<"\n\t\t-->  Nombre   : "<<p->nombre;         
      cout<<"\n\t\t-->  precio   : "<<p->precio<<" $";        
	    cout<<"\n\t\t-->  Codigo   : "<<p->codigo;                 
	    cout<<"\n\t\t-->  Cantidad : "<<cantTemp<<endl;
	    cout<<"\n\t\t-->  Precio a Pagar   : "<<total<<" $\n"<<endl;         
      cout<<"\n\tEl producto "<<p->nombre<<" se encuentra en la poscision "<<posicion<<" de la lista "<<endl;
      cout<<"\n\tUnidades Disponibles: "<<p->cantidad<<"\n"<<endl;  
      busquedaRecursiva(p->siguiente);// la funcion se llama a ella misma 
      system("pause");
     }// fin else2
    }// fin else 1
  }//fin if 1
}// fin funcion

/* 
 * definicion dela funcion que imprimiran el campo de informacion dentro de la lista
*/

//Imprime la lista con un bucle while
void ImprimeIterativo(nodo *p)
{
 nodo *q;
 q = p;
 while (q != NULL)
 {
  cout<<"\n\t\t-->  Nombre   : "<<q->nombre;         
	cout<<"\n\t\t-->  Precio   : "<<q->precio<<" $";          
	cout<<"\n\t\t-->  Codigo   : "<<q->codigo;                 
	cout<<"\n\t\t-->  Cantidad : "<<q->cantidad<<endl; 
  q = q->siguiente; //  aqui nos desplasamos al nodo de la derecha
 }
 
}

// imprime la lista llamandose a ella misma
void imprimeRecursivo(nodo *p)
{
 if( p != NULL){
  cout<<"\n\t\t-->  Nombre   : "<<p->nombre;         
	cout<<"\n\t\t-->  Precio   : "<<p->precio<<" $";          
	cout<<"\n\t\t-->  Codigo   : "<<p->codigo;                 
	cout<<"\n\t\t-->  Cantidad : "<<p->cantidad<<endl; 
  imprimeRecursivo(p->siguiente);
 }

}
/*
 * guarda  la lista en un archivo 
*/
void guardarLista(nodo *p){
	nodo *q;
	q= p; //estamos poniendo la variable puntero nodoDespues en la posicion de p
 ofstream archOut("datos_de_la_lista.dat");
 if (archOut.fail()){
	cout<<"ERROR AL ARCHVO"<<endl;
 }
 else
 {
	while(q!= NULL){
	archOut<<q->nombre<< " " <<q->codigo<<"  "<<q->cantidad<<" "<<q->precio<<endl; 
	q = q->siguiente; //aqui nos desplazamos al nodo de la derecha
	}
	cout<<"GUARDADO CORRECTAMENTE"<<endl;
 }
archOut.close();
}



