#pragma once
#include <fstream>
#include <vector>
#include "ABB.h"
#include <string>
#include <sstream>
#include <functional>

using namespace std;

class MiniBD {
private:
	ifstream archivo;
	vector<string>* vecCabeceras;
	vector<vector<string>*>* miBD;
	string cadena;
	//ABB<vector<string>*>* abbF;
	ABB<string>* abbString;
	ABB<float>* abbFloat;
	ABB<long>* abbLong;
	int nroCol;

public:
	MiniBD() {
		vecCabeceras = new vector<string>();
		miBD = new vector<vector<string>*>();
		//abbF = new ABB<vector<string>*>();
		abbString = new ABB<string>();
		abbFloat = new ABB<float>();
		abbLong = new ABB<long>();
		nroCol = 0;
	}

	void lectura(string nombreArchivo, bool cabecera = true) {
		archivo.open(nombreArchivo);
		//bool esFilaTitulos = true;

		vecCabeceras->clear();
		miBD->clear();

		if (cabecera) {
			getline(archivo, cadena);
			stringstream ss(cadena);
			dividirCampos(ss, true);
		}

		while (getline(archivo, cadena)) {
			stringstream ss(cadena);
			dividirCampos(ss, false);
		}

		archivo.close();

	}

	void dividirCampos(istream& registro, bool cabecera) {
		
		vector<string>* fila = new vector<string>;
		string temp;

		while (getline(registro, temp, ',')) {
			fila->push_back(temp);
		}

		if (cabecera) {
			for (int i = 0; i < fila->size(); i++)
				vecCabeceras->push_back(fila->at(i));
		}
		else {
			miBD->push_back(fila);
		}
		
	}

	void mostrarValores() {
		cout << "Cantidad de filas: " << miBD->size() << endl;
		cout << "Cantidad de columnas: " << miBD->at(0)->size() << endl;
	}

	void mostrarGrafo() {
		for (size_t i = 0; i < vecCabeceras->size(); i++)
			cout << vecCabeceras->at(i) << "\t";
		cout << endl;
		for (int i = 0; i < miBD->size(); i++)
		{
			for (int j = 0; j < miBD->at(0)->size(); j++)
			{
				cout << miBD->at(i)->at(j) << "\t";
			}
			cout << endl;
		}
	}

	void listarBD() {
		
		auto imprimirString = [](string s) {
			cout << s << endl;
		};

		auto imprimirFloat = [](float n) {
			cout << n << endl;
		};

		auto imprimirLong = [](long n) {
			cout << n << endl;
		};

		abbString->enOrden(imprimirString);
		abbFloat->enOrden(imprimirFloat);
		abbLong->enOrden(imprimirLong);

	}

	void borrar() {
		abbFloat->borrarTodo();
		abbString->borrarTodo();
		abbLong->borrarTodo();
	}

	void indexarColumna(int numCol) {

		borrar();

		auto esLong = [](string s)->bool {
			for (int i = 0; i < s.length(); i++) {
				if (!isdigit(s[i]))
					return false;
			}
			return true;
		};

		auto esFloat = [](string s)->bool {
			for (int i = 0; i < s.length(); i++) {

				if (s[0] == '.' || s[s.length() - 1] == '.') {
					return false;
				}

				if (!isdigit(s[i])) {
					if (s[i] != '.') {
						return false;
					}
				}

			}
			return true;
		};

		auto critInsercionFloat = [](float a, float b)->bool {
			return a >= b;
		};

		auto critInsercionLong = [](long a, long b)->bool {
			return a >= b;
		};

		if (esLong(miBD->at(1)->at(numCol))) {
			abbLong->borrarTodo();
			for (int i = 0; i < miBD->size(); i++)
				abbLong->agregar(stol(miBD->at(i)->at(numCol)), critInsercionLong);
		} else if (esFloat(miBD->at(1)->at(numCol))) {
			abbFloat->borrarTodo();
			for (int i = 0; i < miBD->size(); i++)
				abbFloat->agregar(stof(miBD->at(i)->at(numCol)), critInsercionFloat);
		}
		else {
			abbString->borrarTodo();
			for (int i = 0; i < miBD->size(); i++)
				abbString->agregar(miBD->at(i)->at(numCol));
		}

	}

	long getNroFilas() {
		return miBD->size();
	}

	long getNroColumnas() {
		return miBD->at(0)->size();
	}

	void insertarColumna(string cabeceraColumna, vector<string>* columna) {

		vecCabeceras->push_back(cabeceraColumna);

		for (int i = 0; i < miBD->size(); i++)
		{
			miBD->at(i)->push_back(columna->at(i));
		}
	}

	void escribirCabeceras(int numColumna = -1) {

		if (numColumna == -1) {
			for (int i = 0; i < vecCabeceras->size(); i++)
			{
				cout << vecCabeceras->at(i) << "\t";
			}
		}
		else {
			cout << vecCabeceras->at(numColumna);
		}
		
		cout << endl;
	}

	void filtrado_iniciaCon(bool esFiltradoIniciaCon, string cad) {
		auto iniciaCon_Long = [=](long element) {
			string str = to_string(element);

			size_t indice = str.find(cad);
			if (indice != string::npos) {
				if (indice == 0) {
					cout << str << endl;
				}
			}
		};

		auto iniciaCon_Float = [=](float element) {
			string str = to_string(element);

			size_t indice = str.find(cad);
			if (indice != string::npos) {
				if (indice == 0) {
					cout << str << endl;
				}
			}
		};

		auto iniciaCon_String = [=](string str) {
			
			size_t indice = str.find(cad);
			if (indice != string::npos) {
				if (indice == 0) {
					cout << str << endl;
				}
			}
		};

		auto finalizaCon_Long = [=](long element) {

			string str = to_string(element);

			if (str.length() >= cad.length()) {
				if (str.compare(str.length() - cad.length(), cad.length(), cad) == 0)
				{
					cout << str << endl;
				}
			}
		};

		auto finalizaCon_Float = [=](float element) {

			string str = to_string(element);

			if (str.length() >= cad.length()) {
				if (str.compare(str.length() - cad.length(), cad.length(), cad) == 0)
				{
					cout << str << endl;
				}
			}
		};

		auto finalizaCon_String = [=](string str) {
			if (str.length() >= cad.length()) {
				if (str.compare(str.length() - cad.length(), cad.length(), cad) == 0)
				{
					cout << str << endl;
				}
			}
		};

		if (esFiltradoIniciaCon)
		{
			abbLong->enOrden(iniciaCon_Long);
			abbFloat->enOrden(iniciaCon_Float);
			abbString->enOrden(iniciaCon_String);
		}
		else {
			abbLong->enOrden(finalizaCon_Long);
			abbFloat->enOrden(finalizaCon_Float);
			abbString->enOrden(finalizaCon_String);
		}

	}

	void filtrado_MenorMayor(bool esFiltradoMenor, string cad) {

		auto esMenor_Long = [=](long element) {
			if (element < stol(cad))
				cout << element << endl;
		};

		auto esMenor_Float = [=](float element) {
			if (element < stof(cad))
				cout << element << endl;
		};

		auto esMayor_Long = [=](long element) {
			if (element > stol(cad))
				cout << element << endl;
		};

		auto esMayor_Float = [=](float element) {
			if (element > stof(cad))
				cout << element << endl;
		};

		if (esFiltradoMenor)
		{
			abbLong->enOrden(esMenor_Long);
			abbFloat->enOrden(esMenor_Float);
		}
		else {
			abbLong->enOrden(esMayor_Long);
			abbFloat->enOrden(esMayor_Float);
		}
	}

	void filtrado_EstaContenidoEn(bool esFiltradoEstaContenidoEn, string cad) {
		auto estaContenidoEn = [=](string str) {
			size_t indice = str.find(cad);
			if (indice != string::npos) {
				cout << str << endl;
			}
		};

		auto noEstaContenidoEn = [=](string str) {
			size_t indice = str.find(cad);
			if (indice == string::npos) {
				cout << str << endl;
			}
		};

		if (esFiltradoEstaContenidoEn)
		{
			abbString->enOrden(estaContenidoEn);
		}
		else {
			abbString->enOrden(noEstaContenidoEn);
		}

	}

	void filtrado_IgualA(string cad) {
		auto esIgualA_Long = [=](long element) {
			if (element == stol(cad))
				cout << element << endl;
		};

		auto esIgualA_Float = [=](float element) {
			if (element == stof(cad))
				cout << element << endl;
		};
		
		auto esIgualA_String = [=](string str) {
			if (str == cad)
				cout << str << endl;
		};

		abbLong->enOrden(esIgualA_Long);
		abbFloat->enOrden(esIgualA_Float);
		abbString->enOrden(esIgualA_String);

	}

	void mostrarColumna(string selecColumnas) {
		stringstream ss(selecColumnas);
		string temp;

		while (getline(ss, temp, ',')) {
			cout << vecCabeceras->at(stoi(temp)) << endl;
			for (int i = 0; i < getNroFilas(); i++)
			{
				cout << miBD->at(i)->at(stoi(temp)) << endl;
			}
		}
	}

	/*void guardarEnArchivo(string nombreArchivo) {

		auto imprimirString = [](string s) {
			cout << s << endl;
		};

		ofstream archivoGenerado;
		archivoGenerado.open(nombreArchivo);
		if (archivoGenerado.is_open())
		{
			//archivoGenerado << abbString->enOrden(imprimirString);
			abbString->guardarDatosBST(archivoGenerado);
		}

		archivoGenerado.close();
	}*/

};