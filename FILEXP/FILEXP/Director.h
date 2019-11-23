#pragma once
#include "registro.h"
#include "BinaryTree.h"
#include <filesystem>
#include<system_error>
namespace gaa = std::experimental::filesystem;
void bica(Registro r)
{
	cout << r.get_nombre() << "  " << r.get_extension() << "  " << r.get_tamano() << "  " << r.get_fecha() << endl;
}
class Director
{
private:
	ArbolAVL<Registro>*arbol;
	string prueba;
	string ruta;
	void _searchFiles(ArbolAVL<Registro>* arbol)
	{
		for (const auto & entry : gaa::directory_iterator(ruta))
		{
			prueba = entry.path().string();
			gaa::path p = gaa::current_path();
			//fecha de modificacion o de creacion, lo de creacion es para k nmy se la crea
			auto ftime = gaa::last_write_time(prueba);
			time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
			//fecha
			//stem=nombre    extension weno ya se sabe        asctime y lo demas es para el tiempo  gaa::file_size(prueba,std::error_code())
			//cout << gaa::path(prueba).stem() << "\t" << "\t" << gaa::path(prueba).extension() << "\t" << gaa::file_size(prueba, std::error_code()) <<"  "<< asctime(localtime(&cftime)) << endl;
			Registro reg(gaa::path(prueba).stem().generic_string(), gaa::path(prueba).extension().generic_string(), asctime(localtime(&cftime)), gaa::file_size(prueba, std::error_code()));
			arbol->insertar(reg);
		}
	}
public:
	Director()
	{
		arbol = new ArbolAVL<Registro>(bica);
	}
	void searchFiles() {
		_searchFiles(arbol);
	}
	void set_ruta(string ruta) { this->ruta = ruta; }
	void searchPath()
	{
		string Nombre_Archivo = "C:";
		cin >> Nombre_Archivo;
		gaa::path p = Nombre_Archivo;
		cout << "Current path is " << gaa::current_path() << endl << "Absolute Path for " << p << " is " << gaa::absolute(p) << '\n';
	}
	///////////////////////////////////////////////////
	void printFileASC()
	{
		arbol->inOrderASC();//orden ascendente
	}
	void printFileDesc()
	{
		arbol->inOrdenDES();//orden descendente
	}
	////////////////////////////////////////////////////
	void printMaxTamanio()
	{
		arbol->obtenerMAXTamanio();//obtener el maximo tamaño
	}
	void printMinTamanio()
	{
		arbol->obtenerMINTamanio();//obtener el minimo tamaño
	}
	void buscar_tamanio(long t) {
		Registro aux("", "", "", t,2);
		arbol->search(aux);         //obtener un tamaño en especifico
	}
	///////////////////////////////////////////////////////
	void buscar_extension(string ext) {
		Registro aux("", ext, "", 0, 2);
		arbol->search(aux);
	}
	void buscar_fecha(string fecha) {
		Registro aux("", "", fecha, 0, 3);
		arbol->search(aux);
	}
	///////////////////////////////////////////////////////////////
	void buscar_nombre(string nombre) {
		Registro aux(nombre, "", "", 0);
		arbol->search(aux);
	}
	void buscar_nombre_t(string nombre) {//termina con
		Registro aux(nombre, "", "", 0, 4);
		arbol->search(aux);
	}
	void buscar_nombre_c(string nombre) {//contiene 
		Registro aux(nombre, "", "", 0, 5);
		arbol->search(aux);
	}
	//////////////////////////////////////////////////////////////////
	void cambiar_orden(bool x) {
		ArbolAVL<Registro>*aux = new ArbolAVL<Registro>(bica, x);
		_searchFiles(aux);
		arbol = aux;
	}
	
};
