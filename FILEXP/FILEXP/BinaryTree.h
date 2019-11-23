#pragma once
#include "CNodo.h"
#include"registro.h"
template<class T>
class ArbolAVL {
private:
	bool criterio;
	CNodo<T>* raiz;
	void(*procesar)(T);
	//---
	int max(int a, int b) {
		return (a > b ? a : b);
	}

	int _altura(CNodo<T>* nodo) {
		if (nodo == nullptr) return -1;
		return nodo->height;
	}

	bool _insertar(CNodo<T>*& nodo, T e) {
		if (criterio == true) {
			if (nodo == nullptr) {
				nodo = new CNodo<T>();
				nodo->key = e;
			}
			else if (e < nodo->key) {
				_insertar(nodo->left, e);
			}
			else if (e > nodo->key) {
				_insertar(nodo->right, e);
			}

			int hi = _altura(nodo->left);
			int hd = _altura(nodo->right);
			int d = hd - hi;
			if (d > 1) {
				int hni = _altura(nodo->right->left);
				int hnd = _altura(nodo->right->right);
				if (hni > hnd) {
					_rotarDer(nodo->right->left, nodo->right, nodo->right);
				}
				_rotarIzq(nodo, nodo->right, nodo);
			}
			else if (d < -1) {
				int hni = _altura(nodo->left->left);
				int hnd = _altura(nodo->left->right);
				if (hnd > hni) {
					_rotarIzq(nodo->left, nodo->left->right, nodo->left);
				}
				_rotarDer(nodo->left, nodo, nodo);
			}

			hi = _altura(nodo->left);
			hd = _altura(nodo->right);
			nodo->height = 1 + ((hi > hd) ? hi : hd);
			return true;
		}
		else
		{
			if (nodo == nullptr) {
				nodo = new CNodo<T>();
				nodo->key = e;
			}
			else if (e <= nodo->key) {
				_insertar(nodo->left, e);
			}
			else if (e >= nodo->key) {
				_insertar(nodo->right, e);
			}

			int hi = _altura(nodo->left);
			int hd = _altura(nodo->right);
			int d = hd - hi;
			if (d > 1) {
				int hni = _altura(nodo->right->left);
				int hnd = _altura(nodo->right->right);
				if (hni > hnd) {
					_rotarDer(nodo->right->left, nodo->right, nodo->right);
				}
				_rotarIzq(nodo, nodo->right, nodo);
			}
			else if (d < -1) {
				int hni = _altura(nodo->left->left);
				int hnd = _altura(nodo->left->right);
				if (hnd > hni) {
					_rotarIzq(nodo->left, nodo->left->right, nodo->left);
				}
				_rotarDer(nodo->left, nodo, nodo);
			}

			hi = _altura(nodo->left);
			hd = _altura(nodo->right);
			nodo->height = 1 + ((hi > hd) ? hi : hd);
			return true;

		}
	}
	void _rotarDer(CNodo<T>*& x, CNodo<T>* y, CNodo<T>*& p) {
		p = x;
		y->left = x->right;
		p->right = y;
	}

	void _rotarIzq(CNodo<T>* x, CNodo<T>*& y, CNodo<T>*& p) {
		p = y;
		x->right = y->left;
		p->left = x;
	}

	void _inOrderASC(CNodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrderASC(nodo->left);
		procesar(nodo->key);
		_inOrderASC(nodo->right);
	}
	void _inOrderDES(CNodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrderDES(nodo->right);
		procesar(nodo->key);
		_inOrderDES(nodo->left);
	}
	void _search(CNodo<T>* nodo, T e) {
		if (nodo == nullptr) return;
		_search(nodo->left, e);
		if (nodo->key == e) { procesar(nodo->key); }
		_search(nodo->right, e);
	}
	void obtenerMayorTamanio(CNodo<T>*nodo)
	{
		if (nodo==nullptr)
		{
			return;
		}
		if (nodo->right == nullptr)
			procesar(nodo->key);
		obtenerMayorTamanio(nodo->right);
	}
	void obtenerMenorTamanio(CNodo<T>*nodo)
	{
		if (nodo == nullptr)
		{
			return;
		}
		if (nodo->left == nullptr)
			procesar(nodo->key);
		obtenerMenorTamanio(nodo->left);
	}
public:
	ArbolAVL(void(*pf)(T)) {
		this->procesar = pf;
		raiz = nullptr;
		criterio = true;
	}
	ArbolAVL(void(*pf)(T), bool criterio) {
		this->procesar = pf;
		raiz = nullptr;
		this->criterio = criterio;
	}

	void insertar(T e) {
		_insertar(raiz, e);
	}

	void inOrderASC() {
		_inOrderASC(raiz);
	}
	void inOrdenDES()
	{
		_inOrderDES(raiz);
	}
	void search(T e) {
		_search(raiz, e);
	}
	void cambiar_orden() {

	}
	void set_criterio(bool criterio) { this->criterio = criterio; }
	void obtenerMAXTamanio()
	{
		obtenerMayorTamanio(raiz);
	}
	void obtenerMINTamanio()
	{
		obtenerMenorTamanio(raiz);
	}
};