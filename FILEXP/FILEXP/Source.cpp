#include "BinaryTree.h"
#include <iostream>
#include<conio.h>
#include "registro.h"
#include "Director.h"
using namespace std;
using namespace System;
Director*dir = new Director;
void subMenu2();
void subMenu3();
void subMenu1();
void MenuPrincipal();
int main()
{
	MenuPrincipal();
	_getch();
	return 0;
}
void MenuPrincipal()
{
	int tecla;
	string ruta;
	do
	{
		cout << "#######################MENU#####################" << endl;
		/*cout << "1.Ingresar Ruta: "<<endl;*/
		cout << "1.Mostrar el directorio con los archivos: " << endl;
		cout << "2.Filtrado de datos por columnas : " << endl;
		cout << "3.Salir" << endl;
		cout << "Seleccionar Opcion: "; cin >> tecla;
		switch (tecla)
		{

		case 1:
			system("cls");
			dir->searchPath();
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Ingresar la ruta del directorio: "; cin >> ruta;
			dir->set_ruta(ruta);
			dir->searchFiles();
			dir->printFileASC();
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			subMenu1();
			system("cls");

		case 4:
			return;
		}
	} while (tecla != 4);
	system("cls");
}
void subMenu1()
{
	int tecla2;
	cout << "1. Filtrado de Nombres: " << endl;
	cout << "2. Filtrado por el tamanio del archivo: " << endl;
	cout << "3. Regresar Menu Principal" << endl;
	cout << "Selecciona una opcion: "; cin >> tecla2;
	system("cls");
	switch (tecla2)
	{
	case 1:
		subMenu2();
		break;

	case 2:

		subMenu3();
		break;
	case 3:
		MenuPrincipal();
		
		break;
	}
}
void subMenu2()
{
	int orden1;
	char tecla3;
	bool ultimo = true;
	string letra_a, letra_b, letra_c;
	cout << "a. Nombre que empieza con: " << endl;
	cout << "b. Nombre que finaliza con: " << endl;
	cout << "c. Nombre que contiene:  " << endl;
	cout << "d. Regresar a la ventana anterior: " << endl;
	cout << " Seleccione letra: "; cin >> tecla3;
	system("cls");
	switch (tecla3)
	{
	case 'a':case 'A':
		cout << "Digite la letra a buscar: "; cin >> letra_a;
		dir->buscar_nombre(letra_a);
		_getch();
		switch (orden1)
		{
		case 1:
			cout << "Ordenado Ascendentemente: " << endl;
			dir->cambiar_orden(ultimo);
			dir->printFileASC();
			_getch();
			system("cls");
			subMenu2();
			break;
		case 2:
			cout << endl << "Ordenado Descendentemente: " << endl;
			dir->cambiar_orden(ultimo);
			dir->printFileDesc();
			_getch();
			system("cls");
			subMenu2();
		default:
			break;
		}
		break;
	case 'b':case 'B':
		
		cout << "Digite la letra a buscar: "; cin >> letra_b;
		dir->buscar_nombre_t(letra_b);
		_getch();
		cout << "Desea Ordenarlo Ascendentemente(1) o Descendentemente(2): "; cin >> orden1;
		switch (orden1)
		{
		case 1:
			cout << "Ordenado Ascendentemente: " << endl;
			dir->cambiar_orden(ultimo);
			dir->printFileASC();
			_getch();
			system("cls");
			subMenu2();
			break;
		case 2:
			cout << endl << "Ordenado Descendentemente: " << endl;
			dir->cambiar_orden(ultimo);
			dir->printFileDesc();
			_getch();
			system("cls");
			subMenu2();
		default:
			break;
		}
		break;
	case 'c': case 'C':
		cout << "Digite la letra a buscar: "; cin >> letra_c;
		dir->buscar_nombre_c(letra_c);
		_getch();
		system("cls");
		cout << "Desea Ordenarlo Ascendentemente(1) o Descendentemente(2): "; cin >> orden1;
		switch (orden1)
		{
		case 1:
			cout << "Ordenado Ascendentemente: " << endl;
			dir->cambiar_orden(ultimo);
			dir->printFileASC();
			_getch();
			system("cls");
			subMenu2();
			break;
		case 2:
			cout << endl << "Ordenado Descendentemente: " << endl;
			dir->cambiar_orden(ultimo);
			dir->printFileDesc();
			_getch();
			system("cls");
			subMenu2();
		default:
			break;
		}
		subMenu2();
		break;
	case 'd':case 'D':
		subMenu1();
		_getch();
		system("cls");
		break;

	default:
		cout << "Vuelva a insertar una letra que corresponda: " << endl;
		break;
	}
}
void subMenu3()
{
	int tamanio3;
	char tecla4;
	bool minTAM = false;
	bool maxTAM = false;
	cout << "a. Archivo de mayor tamanio en kB: " << endl;
	cout << "b. Archivo de menor tamamio en kB: " << endl;
	cout << "c. Archivo con tamanio igual a: " << endl;
	cout << "d. Regresar a la ventana anterior: " << endl;
	cout << "   Elige una letra: "; cin >> tecla4;
	system("cls");
	switch (tecla4)
	{
	case 'a':case'A':
		system("cls");
		cout << " El archivo con mayor tamanio es :" << endl;
		
		dir->cambiar_orden(maxTAM);
		dir->printMaxTamanio();
		_getch();
		system("cls");
		subMenu3();
		break;
		
	case 'b':case 'B':
		system("cls");
		cout << " El archivo con menor Tamanio :" << endl;
		
		dir->cambiar_orden(minTAM);
		dir->printMinTamanio();
		_getch();
		system("cls");
		subMenu3();
		
		break;
	case 'c':case 'C':
		system("cls");
		cout << "Elige el tamamio: "; cin >> tamanio3;
		dir->buscar_tamanio(tamanio3);
		_getch();
		system("cls");
		subMenu3();
		break;
	case 'd':case 'D':
		subMenu1();
		break;
	default:
		break;
	}
}



