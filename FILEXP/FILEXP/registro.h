#pragma once
#include<string>
#include <iostream>

using namespace System;
using namespace std;
class Registro
{
public:
	Registro() {}
	Registro(string nombre, string extension, string fecha, long tamano) {
		filtro = 0;
		this->nombre = nombre;
		this->extension = extension;
		this->fecha = fecha;
		this->tamano = tamano;
		if (tamano == -1) { this->tamano = 0; }
	}
	Registro(string nombre, string extension, string fecha, long tamano, int filtro) {
		this->filtro = filtro;
		this->nombre = nombre;
		this->extension = extension;
		this->fecha = fecha;
		this->tamano = tamano;
		if (tamano == -1) { this->tamano = 0; }
	}


	string get_nombre() { return nombre; }
	string get_extension() { return extension; }
	int    get_tamano() { return tamano; }
	string   get_fecha() { return fecha; }
	int get_filtro() { return filtro; }

	void set_fltro(int filtro) { this->filtro = filtro; }
	void set_nombre(string nombre) { this->nombre = nombre; }
	void set_extension(string extension) { this->extension = extension; }
	void set_tamano(long tamano) { this->tamano = tamano; }
	void set_fecha(string fecha) { this->fecha = fecha; }


	bool operator <(Registro r1) {
		return nombre[0] < r1.get_nombre()[0];
	}
	bool operator >(Registro r) {
		return nombre[0] > r.get_nombre()[0];
	}
	bool operator <=(Registro r)
	{
		return tamano < r.get_tamano();
	}
	bool operator >=(Registro r) {
		return tamano > r.get_tamano();
	}
	bool operator ==(Registro r) {
		if (r.get_filtro() == 0)
		{
			return nombre[0] == r.get_nombre()[0];
		}
		else if (r.get_filtro() == 1)
		{
			return extension == r.get_extension();
		}
		else if (r.get_filtro() == 2)
		{
			return tamano == r.get_tamano();
		}
		else if (r.get_filtro() == 3)
		{
			return fecha == r.get_fecha();
		}
		else if (r.get_filtro() == 4)//termina con
		{
			return nombre.at(nombre.size() - 1) == r.get_nombre().at(r.get_nombre().size() - 1);
		}
		else if (r.get_filtro() == 5)//contiene
		{
			for (int i = 0; i < nombre.size(); i++)
			{
				if (nombre.at(i) == r.get_nombre()[0]) { return true; }
			}
			return false;
		}
		//	/*for (int i = 0; i < nombre.size(); i++)
		//	{
		//		if (nombre.at(i) == r.get_nombre()[0]) { return true; }
		//	}
		//	return false;/*
		//	/*return nombre.at(nombre.size()-1) == r.get_nombre().at(r.get_nombre().size() - 1);
		//	return tamano == r.get_tamano();*/
	}

private:
	int filtro;
	string nombre;
	string extension;
	long tamano;
	string fecha;
};