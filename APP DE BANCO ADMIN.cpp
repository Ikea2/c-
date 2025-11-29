/*   
Crea una aplicación de consola de un cajero automático en ella podré ingresar dinero/retirarlo iniciar sesión y asociar el dinero a una cuenta 
según el usuario para ello crearemos un menú donde seleccionemos la opciones a retirar y poder ver el saldo de mi cuenta 
Si entro con el rol de admistracion puedo ver el saldo de todas la cuentas 


Funciones(opcional pero mejor)

Manejo de roles sistema de usuarios 

Permita crear una cuenta 

Bucle while 
Switch 
Arrays
*/

#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

using namespace std;

struct Datos_Ban{  //Datos de la cuenta de cada usuario 
	float saldo = 0;
	float Ult_Mov;
};

struct Usuario_Real{  //Datos guardados de cuentas validas
	string UserNameR;
	string PasswordR;
	
	struct Datos_Ban UserData;
}UsuariosR[6];

struct Usuario_str{  //usuario que introduces en la interfaz
	string UserName;
	string Password;

}Usuario;

int main(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	bool p = false; //si ha fallado la contraseña
	int Valid = 0;
	int l = 0; //maximo de cuentas aux
	int n_user = 0; //el numero en el que el usuario ha creado su cuenta en el array 
	int accion = 0;
	int AdminUser = 0; // numero de cuenta buscado por el admin
	int g=0;
	float ingreso = 0;
	UsuariosR[5].UserData.saldo = 99999;
	bool close = false;
	bool vAdmin = false;
	bool admin = false;
	string respuesta;
	
	UsuariosR[5].UserNameR = "iker";
	UsuariosR[5].PasswordR = "admin";
	UsuariosR[4].UserNameR = "juanjo";
	UsuariosR[4].PasswordR = "programador";
	UsuariosR[4].UserData.saldo = 50;
	UsuariosR[4].UserData.Ult_Mov = -120;
	UsuariosR[3].UserNameR = "gael";
	UsuariosR[3].PasswordR = "siena";
	UsuariosR[3].UserData.saldo = 1300;
	UsuariosR[3].UserData.Ult_Mov = -99;
	
	for(int j=1;j<3;j++){  //rellenar cuentas vacias o con valores basura 
		UsuariosR[j].PasswordR = "";
		for(int k = 0; k < 4; k++){ // contraseña de 4 letras 
   			 UsuariosR[j].PasswordR += char('A' + rand() % 26);
		}
	}
	
	
	while(Valid == 0){
		SetConsoleTextAttribute(h, 13);
		cout<<"Bienvenido de Nuevo"<<endl; 
		SetConsoleTextAttribute(h, 7);
		if(l < 3){
			cout<<"\nDesea crearse una cuenta: ";
			cin>>respuesta;
			if(respuesta == "si"){
				cout<<"\nIngrese el nombre de usuario de su nueva cuenta: ";
				cin>>UsuariosR[1+l].UserNameR;
				cout<<"Ingrese la contraseña de su nueva cuenta: ";
				cin>>UsuariosR[1+l].PasswordR;
				n_user = 1+l;
				l += 1;
			}
		} else {
   			 cout << "No se pueden crear más cuentas" << endl;
		}
		
		 //pedir Datos al Usuario
		cout<<"\nUsuario: ";
		cin>>Usuario.UserName;
		cout<<"Contraseña: ";
		cin>>Usuario.Password;
		
		for(int i=0;i<6;i++){  //revisa los 5 espacios de la memoria de cuantas validas
			if(Usuario.UserName == UsuariosR[i].UserNameR && Usuario.Password == UsuariosR[i].PasswordR){
				Valid = 1;
				break;
			}
		}
		if(Usuario.UserName == UsuariosR[5].UserNameR && Usuario.Password == UsuariosR[5].PasswordR){
				admin = true;
			}
		
		if(Valid == 0){
			SetConsoleTextAttribute(h, 12);
			cout<<"\nUsuario o contraseña incorrecta "<<endl<<endl;
			p = true;
			SetConsoleTextAttribute(h, 1);
		}
		SetConsoleTextAttribute(h, 7);	
	}
	
	SetConsoleTextAttribute(h, 10);
	cout<<endl<<"DATOS DE INICIO DE SESION CORRECTOS"<<endl;
	
	if(admin == true){
		do{
			SetConsoleTextAttribute(h, 13);
			cout<<"\nMENU DE ADMIN: ";
			SetConsoleTextAttribute(h, 7);
			cout<<"\nDigite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"1 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para ver el saldo actual"<<endl;
			cout<<"Digite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"2 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para ver los ultimos movimientos"<<endl;
			cout<<"Digite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"3 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para ingresar dinero"<<endl;
			cout<<"Digite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"4 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para extraer dinero"<<endl;
			cout<<"Digite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"5 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para cerrar sesion"<<endl;
			cin>>accion;
			switch(accion){
				case 1: cout<<"\nDigite el nombre del usuario del cual desea acceder a su saldo: ";
						cin>>Usuario.UserName;
						for(int i=0;i<6;i++){
							if(Usuario.UserName == UsuariosR[i].UserNameR){
								vAdmin = true;
								AdminUser = i;
							}
						}
						if(vAdmin == true){
							cout<<"Saldo de ";
							SetConsoleTextAttribute(h, 2);
							cout<<UsuariosR[AdminUser].UserNameR<<": ";
							SetConsoleTextAttribute(h, 7);
							cout<<endl<<UsuariosR[AdminUser].UserData.saldo;
						}else{
							SetConsoleTextAttribute(h, 4);
							cout<<"\nNOMBRE DE USUARIO NO ENCONTRADO";
							SetConsoleTextAttribute(h, 7);
						}
						cout<<"\nDigite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"1 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para volver al menu"<<endl;
						cout<<"Digite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"2 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para cerrar sesion"<<endl;
						cin>>accion;
						if(accion==2){
							close = true;
						} break;
				case 2: cout<<"\nDigite el nombre del usuario del cual desea acceder a su ultimo movimineto: ";
						cin>>Usuario.UserName;
						for(int i=0;i<6;i++){
							if(Usuario.UserName == UsuariosR[i].UserNameR){
								vAdmin = true;
								AdminUser = i;
							}
						}
						if(vAdmin == true){
							cout<<"Ultimo movimiento de ";
							SetConsoleTextAttribute(h, 2);
							cout<<UsuariosR[AdminUser].UserNameR<<": ";
							SetConsoleTextAttribute(h, 7);
							cout<<endl<<UsuariosR[AdminUser].UserData.Ult_Mov;
						}else{
							SetConsoleTextAttribute(h, 4);
							cout<<"\nNOMBRE DE USUARIO NO ENCONTRADO";
							SetConsoleTextAttribute(h, 7);
						}
						cout<<"\nDigite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"1 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para volver al menu"<<endl;
						cout<<"Digite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"2 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para cerrar sesion"<<endl;
						cin>>accion;
						if(accion==2){
							close = true;
						} break;
				case 3: cout<<"\nDigite el nombre del usuario al cual desea ingresar dinero: ";
						cin>>Usuario.UserName;
						for(int i=0;i<6;i++){
							if(Usuario.UserName == UsuariosR[i].UserNameR){
								vAdmin = true;
								AdminUser = i;
							}
						}
						if(vAdmin == true){
							cout<<"\nDigite la cantidad a ingresar: ";
							cin>>ingreso;
							UsuariosR[AdminUser].UserData.saldo += ingreso;
							cout<<"Saldo de ";
							SetConsoleTextAttribute(h, 2);
							cout<<UsuariosR[AdminUser].UserNameR<<": ";
							SetConsoleTextAttribute(h, 7);
							cout<<endl<<UsuariosR[AdminUser].UserData.saldo;
						}else{
							SetConsoleTextAttribute(h, 4);
							cout<<"\nNOMBRE DE USUARIO NO ENCONTRADO";
							SetConsoleTextAttribute(h, 7);
						}
						cout<<"\nDigite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"1 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para volver al menu"<<endl;
						cout<<"Digite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"2 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para cerrar sesion"<<endl;
						cin>>accion;
						if(accion==2){
							close = true;
						} break;
				case 4: cout<<"\nDigite el nombre del usuario al cual desea retirar dinero: ";
						cin>>Usuario.UserName;
						for(int i=0;i<6;i++){
							if(Usuario.UserName == UsuariosR[i].UserNameR){
								vAdmin = true;
								AdminUser = i;
							}
						}
						if(vAdmin == true){
							cout<<"\nDigite la cantidad a retirar: ";
							cin>>ingreso;
							UsuariosR[AdminUser].UserData.saldo -= ingreso;
							cout<<"Saldo de ";
							SetConsoleTextAttribute(h, 2);
							cout<<UsuariosR[AdminUser].UserNameR<<": ";
							SetConsoleTextAttribute(h, 7);
							cout<<endl<<UsuariosR[AdminUser].UserData.saldo;
						}else{
							SetConsoleTextAttribute(h, 4);
							cout<<"\nNOMBRE DE USUARIO NO ENCONTRADO";
							SetConsoleTextAttribute(h, 7);
						}
						cout<<"\nDigite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"1 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para volver al menu"<<endl;
						cout<<"Digite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"2 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para cerrar sesion"<<endl;
						cin>>accion;
						if(accion==2){
							close = true;
						} break;
						
				case 5: close = true;
						break;							
			}	
		}while(close==false);
	}else{
		do{
			SetConsoleTextAttribute(h, 13);
			cout<<"\nMENU: ";
			SetConsoleTextAttribute(h, 7);
			cout<<"\nDigite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"1 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para ver el saldo actual"<<endl;
			cout<<"Digite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"2 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para ver los ultimos movimientos"<<endl;
			cout<<"Digite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"3 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para ingresar dinero"<<endl;
			cout<<"Digite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"4 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para extraer dinero"<<endl;
			cout<<"Digite ";
			SetConsoleTextAttribute(h, 2);
			cout<<"5 ";
			SetConsoleTextAttribute(h, 7);
			cout<<"para cerrar sesion"<<endl;
			cin>>accion;
	
	
			switch(accion){
				case 1: SetConsoleTextAttribute(h, 6);
						cout<<endl<<"SALDO:"<<endl;
						SetConsoleTextAttribute(h, 7);
						cout<<UsuariosR[n_user].UserData.saldo<<endl;
						cout<<"\nDigite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"1 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para volver al menu"<<endl;
						cout<<"Digite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"2 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para cerrar sesion"<<endl;
						cin>>accion;
						if(accion==2){
							close = true;
						} break;
				case 2: SetConsoleTextAttribute(h, 6);
						cout<<endl<<"ULTIMO MOVIMIENTO:"<<endl;
						SetConsoleTextAttribute(h, 7);
						cout<<UsuariosR[n_user].UserData.Ult_Mov<<endl;
						cout<<"\nDigite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"1 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para volver al menu"<<endl;
						cout<<"Digite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"2 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para cerrar sesion"<<endl;
						cin>>accion;
						if(accion==2){
							close = true;
						}break;
				case 3: cout<<"\nDigite la cantidad a ";
						SetConsoleTextAttribute(h, 2);
						cout<<"ingresar: ";
						SetConsoleTextAttribute(h, 7);
						cin>>ingreso; 
						UsuariosR[n_user].UserData.saldo += ingreso;
						UsuariosR[n_user].UserData.Ult_Mov = ingreso;
						cout<<"\nDigite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"1 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para volver al menu"<<endl;
						cout<<"Digite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"2 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para cerrar sesion"<<endl;
						cin>>accion;
						if(accion==2){
							close = true;
						}break;
				
				case 4: cout<<"\nDigite la cantidad a ";
						SetConsoleTextAttribute(h, 4);
						cout<<"retirar: ";
						SetConsoleTextAttribute(h, 7);
						cin>>ingreso;
						UsuariosR[n_user].UserData.saldo -= ingreso;
						UsuariosR[n_user].UserData.Ult_Mov = ingreso*(-1);
						cout<<"\nDigite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"1 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para volver al menu"<<endl;
						cout<<"Digite ";
						SetConsoleTextAttribute(h, 2);
						cout<<"2 ";
						SetConsoleTextAttribute(h, 7);
						cout<<"para cerrar sesion"<<endl;
						cin>>accion;
						if(accion==2){
							close = true;
						}break;
		
				case 5: close = true;
						break;
					}	
		}while(close==false);
	}	
	
	
	SetConsoleTextAttribute(h, 10);
	cout<<endl<<"\nSESION CERRADA CORRECTAMENTE"<<endl<<endl;
	SetConsoleTextAttribute(h, 7);
	
	
	

	return 0;
}
