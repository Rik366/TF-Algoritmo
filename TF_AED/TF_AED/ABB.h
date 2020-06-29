#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template<class G>
class ABB
{
	template<class G>
	class Nodo {
	public:
		G valor;
		Nodo<G>* izquierdo;
		Nodo<G>* derecho;
		Nodo() {
			valor = 0;
			izquierdo = derecho = nullptr;
		}
		Nodo(G valor) {
			this->valor = valor;
			izquierdo = derecho = nullptr;
		}
	};

private:

	Nodo<G>* raiz;
	long cantidad;

	void _agregar(Nodo<G>*& nodo, G valor) {
		if (nodo == nullptr)
		{
			nodo = new Nodo<G>(valor);
			cantidad++;
		}
		else if (valor >= nodo->valor)
			_agregar(nodo->derecho, valor);
		else
			_agregar(nodo->izquierdo, valor);
	}

	void _agregar(Nodo<G>*& nodo, G& valor, function<bool(G, G)> criterio) {
		if (nodo == nullptr) {
			nodo = new Nodo<G>(valor);
			cantidad++;
		}
		else if (criterio(valor, nodo->valor)) {
			_agregar(nodo->derecho, valor, criterio);
		}
		else {
			_agregar(nodo->izquierdo, valor, criterio);
		}
	}

	void _enOrden(Nodo<G>* nodo, function<void(G)>criterioImpresion) {
		if (nodo != nullptr) {
			_enOrden(nodo->izquierdo, criterioImpresion);
			criterioImpresion(nodo->valor);
			_enOrden(nodo->derecho, criterioImpresion);
		}
	}

	/*void _guardarDatosBST(Nodo<G>* nodo, ofstream &archivoGenerado) {
		if (nodo == nullptr) {
			archivoGenerado << "# ";
		}
		else {
			_guardarDatosBST(nodo->izquierdo, archivoGenerado);
			archivoGenerado << nodo->valor; << " ";
			_guardarDatosBST(nodo->derecho, archivoGenerado);
		}
	}*/

	void _buscar(Nodo<G>* nodo, G valor, function<char(G, G)> crit, bool &encontrar) {
		if (nodo == nullptr) {
			encontrar = false;
		}
		else {
			if (crit(valor, nodo->valor) == 'E') {
				encontrar = true;
				return;
			}
			else if (crit(valor, nodo->valor) == 'R')
				_buscar(nodo->derecho, valor, crit, encontrar);
			else
				_buscar(nodo->izquierdo, valor, crit, encontrar);
		}
	}

	void _borrarTodo(Nodo<G>* nodo) {
		if (nodo != nullptr) {
			_borrarTodo(nodo->izquierdo);
			_borrarTodo(nodo->derecho);
			delete nodo;
		}
		this->raiz = nullptr;
		this->cantidad = 0;
	}

	G _sumarElementos(Nodo<G>* nodo) {
		G suma = 0;
		if (nodo != nullptr) {
			suma += _sumarElementos(nodo->izquierdo);
			suma += nodo->valor;
			suma += _sumarElementos(nodo->derecho);
		}
		return suma;
	}

	void _getNrosRango(Nodo<G>* nodo, G nro1, G nro2) {
		if (nodo != nullptr)
		{
			_getNrosRango(nodo->izquierdo, nro1, nro2);

			if (nro1 <= nodo->valor && nodo->valor <= nro2)
			{
				cout << nodo->valor << " ";
			}

			_getNrosRango(nodo->derecho, nro1, nro2);

		}
	}

public:

	void agregar(G valor) {
		_agregar(raiz, valor);
	}

	void agregar(G valor, function<bool(G, G)> criterio) {
		_agregar(raiz, valor, criterio);
	}

	void enOrden(function<void(G)>criterioImpresion) {
		_enOrden(raiz, criterioImpresion);
	}
	bool buscar(G valor, function<char(G, G)> crit) {
		bool find = false;
		_buscar(raiz, valor, crit, find);
		return find;
	}

	ABB() {
		raiz = nullptr;
		cantidad = 0;
	}

	~ABB() {}

	int getNroElementos() {
		return cantidad;
	}

	void borrarTodo() {
		_borrarTodo(raiz);
	}

	/*void guardarDatosBST(ofstream& archivoGenerado) {
		_guardarDatosBST(raiz, archivoGenerado);
	}*/

};