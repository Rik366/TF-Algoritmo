#include <iostream>
#include "MiniBD.h"

using namespace std;

template<typename G>
void cargarDatosArbol(ABB<G>* arbol, string nombreArchivo, short nroColumna) {
	ifstream archivo(nombreArchivo);
	string fila;
	bool esFilaTitulos = true;

	if (archivo.is_open()) {
		while (getline(archivo, fila))
		{
			if (!esFilaTitulos) // esto es para no tomar en cuenta la primera fila que es la de los titulos de las columnas
			{
				stringstream ss(fila);
				dividirColumnas(arbol, ss, nroColumna);
			}
			esFilaTitulos = false;
		}
	}
}

template<typename G>
void dividirColumnas(ABB<G>* arbol, istream& ss, short nroColumna) {
	short contColumna = 0;
	string campo;
	while (getline(ss, campo, ',')) {
		if (contColumna == nroColumna) // solo guardara los datos de la columna requerida
		{
			arbol->agregar(stof(campo));
		}
		++contColumna;
	}
}

void menu(int& op) {
	system("cls");
	cout << endl;
	cout << "\t------------- MENU -------------" << endl;
	cout << "\t1. Crear tabla" << endl;
	cout << "\t2. Mostrar tabla" << endl;
	cout << "\t3. Seleccion de datos por columna" << endl;
	cout << "\t4. Insertar columna" << endl;
	cout << "\t5. Indexar columna" << endl;
	cout << "\t6. Mostrar columna indexada" << endl;
	cout << "\t7. Borrar datos de columnas indexadas" << endl;
	cout << "\t8. Filtrado de datos por columnas" << endl;
	cout << endl;
	cout << "\tIngrese la opcion: ";
	cin >> op;
	cout << endl;
}

void menuFiltrar(int& op2) {
	system("cls");
	cout << endl;
	cout << "\t------------- FILTRAR -------------" << endl;
	cout << "\t1. Mayor" << endl;
	cout << "\t2. Menor" << endl;
	cout << "\t3. Igual a" << endl;
	cout << "\t4. Inicia con" << endl;
	cout << "\t5. Finaliza con" << endl;
	cout << "\t6. Esta contenido en" << endl;
	cout << "\t7. No esta contenido en" << endl;
	cout << "\t8. Regresar al menu anterior" << endl;
	cout << endl;
	cout << "\tIngrese la opcion: ";
	cin >> op2;
	cout << endl;
}

int main() {

	MiniBD BD;
	int op = 0;
	int op2 = 0;

	do
	{
		menu(op);

		switch (op)
		{
		case 1:
		{
			BD.lectura("datos.csv");
			BD.mostrarValores();
			cout << endl;
			BD.mostrarGrafo();

			system("pause>nul");
			op = 0;
			break;
		}
		case 2:
		{
			BD.mostrarValores();
			cout << endl;
			BD.mostrarGrafo();

			system("pause>nul");
			op = 0;
			break;
		}
		case 3:
		{
			string selecColumnas = "";
			BD.escribirCabeceras();
			cout << endl;
			cout << "Ingrese los numeros de columna separados por comas (Ej. 1,3) [0-" << BD.getNroColumnas() - 1 << "]: ";
			cin >> selecColumnas;
			BD.mostrarColumna(selecColumnas);

			system("pause>nul");
			op = 0;
			break;
		}
		case 4:
		{
			string cabeceraColumna = "";
			cout << "Ingrese el nombre (cabecera) de la columna a insertar: ";
			cin >> cabeceraColumna;
			cout << "Ingrese los datos a insertar: " << endl;
			string valoraux = "";
			vector<string>* aux = new vector<string>();
			for (int i = 0; i < BD.getNroFilas(); i++)
			{
				cin >> valoraux;
				aux->push_back(valoraux);
			}

			BD.insertarColumna(cabeceraColumna, aux);

			cout << "\nSe inserto la columna exitosamente" << endl;

			system("pause>nul");
			op = 0;
			break;
		}
		case 5:
		{
			int nroCol = 0;
			BD.escribirCabeceras();
			for (int i = 0; i < BD.getNroColumnas(); i++)
				cout << i << "\t";
			cout << "\n\n\tIngrese el numero de columna a indexar [0-" << BD.getNroColumnas() - 1 << "]: ";
			cin >> nroCol;
			BD.indexarColumna(nroCol);
			BD.escribirCabeceras(nroCol);
			BD.listarBD();

			system("pause>nul");
			op = 0;
			break;
		}
		case 6:
		{
			BD.listarBD();

			system("pause>nul");
			op = 0;
			break;
		}
		case 7:
		{
			BD.borrar();
			cout << "\tSe borro correctamente" << endl;

			system("pause>nul");
			op = 0;
			break;
		}
		case 8:
		{
			do
			{
				menuFiltrar(op2);
				switch (op2)
				{
				case 1:
				{
					string str = "";
					cout << "\tIngrese el valor a consultar: ";
					cin >> str;
					BD.filtrado_MenorMayor(false, str);

					system("pause>nul");
					op2 = 0;
					break;
				}
				case 2:
				{
					string str = "";
					cout << "\tIngrese el valor a consultar: ";
					cin >> str;
					BD.filtrado_MenorMayor(true, str);

					system("pause>nul");
					op2 = 0;
					break;
				}
				case 3:
				{
					string str = "";
					cout << "\tIngrese el valor a consultar: ";
					cin >> str;
					BD.filtrado_IgualA(str);

					system("pause>nul");
					op2 = 0;
					break;
				}
				case 4:
				{
					
					string cad = "";
					cout << "\tIngrese el string a buscar: ";
					cin >> cad;
					BD.filtrado_iniciaCon(true, cad);

					system("pause>nul");
					op2 = 0;
					break;
				}
				case 5:
				{
					string cad = "";
					cout << "\tIngrese el string a buscar: ";
					cin >> cad;
					BD.filtrado_iniciaCon(false, cad);

					system("pause>nul");
					op2 = 0;
					break;
				}
				case 6:
				{
					string str = "";
					cout << "\tIngrese el valor a consultar: ";
					cin >> str;
					BD.filtrado_EstaContenidoEn(true, str);

					system("pause>nul");
					op2 = 0;
					break;
				}
				case 7:
				{
					string str = "";
					cout << "\tIngrese el valor a consultar: ";
					cin >> str;
					BD.filtrado_EstaContenidoEn(false, str);

					system("pause>nul");
					op2 = 0;
					break;
				}
				case 8:
				{
					op2 = 8;
					break;
				}
				default:
					break;
				}
			} while (!(op2 >= 1 && op2 <= 8));

			op = 0;
			break;
		}
		default:
			break;
		}

	} while (!(op >= 1 && op <= 7));

	cin.get();
	//BD.borrar();
	return 0;
}