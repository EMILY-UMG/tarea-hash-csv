#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Estudiante {

    int student_id;
    string full_name;
    string career;
    int semester;
    float gpa;
    int skill_score;
};

struct Nodo {

    Estudiante estudiante;
    Nodo* siguiente;
};

class HashTable {

private:

    static const int SIZE = 10;

    Nodo* tabla[SIZE];

    int totalElementos;
    int totalColisiones;

    int funcionHash(int id) {

        return id % SIZE;
    }

public:

    HashTable() {

        for (int i = 0; i < SIZE; i++) {

            tabla[i] = nullptr;
        }

        totalElementos = 0;
        totalColisiones = 0;
    }

    bool insertar(Estudiante estudiante) {

        int indice = funcionHash(estudiante.student_id);

        if (buscar(estudiante.student_id) != nullptr) {

            cout << "ID duplicado.\n";
            return false;
        }

        Nodo* nuevo = new Nodo;

        nuevo->estudiante = estudiante;

        nuevo->siguiente = tabla[indice];

        if (tabla[indice] != nullptr) {

            totalColisiones++;
        }

        tabla[indice] = nuevo;

        totalElementos++;

        return true;
    }

    Estudiante* buscar(int id) {

        int indice = funcionHash(id);

        Nodo* actual = tabla[indice];

        while (actual != nullptr) {

            if (actual->estudiante.student_id == id) {

                return &actual->estudiante;
            }

            actual = actual->siguiente;
        }

        return nullptr;
    }

    bool eliminar(int id) {

        int indice = funcionHash(id);

        Nodo* actual = tabla[indice];

        Nodo* anterior = nullptr;

        while (actual != nullptr) {

            if (actual->estudiante.student_id == id) {

                if (anterior == nullptr) {

                    tabla[indice] = actual->siguiente;

                } else {

                    anterior->siguiente = actual->siguiente;
                }

                delete actual;

                totalElementos--;

                return true;
            }

            anterior = actual;
            actual = actual->siguiente;
        }

        return false;
    }

    void mostrarTabla() {

        cout << "\n=== TABLA HASH ===\n";

        for (int i = 0; i < SIZE; i++) {

            cout << "Bucket [" << i << "]: ";

            Nodo* actual = tabla[i];

            while (actual != nullptr) {

                cout << "("
                     << actual->estudiante.student_id
                     << ", "
                     << actual->estudiante.full_name
                     << ") -> ";

                actual = actual->siguiente;
            }

            cout << "FINAL\n";
        }
    }

    void mostrarEstadisticas() {

        cout << "\n=== ESTADISTICAS ===\n";

        cout << "TOTAL ESTUDIANTES: "
             << totalElementos << endl;

        cout << "TOTAL COLISIONES: "
             << totalColisiones << endl;

        cout << "FACTOR CARGA: "
             << (float) totalElementos / SIZE << endl;
    }

    void cargarCSV(string nombreArchivo) {

        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {

            cout << "NO SE PUEDE ABRIR CSV.\n";
            return;
        }

        string linea;

        getline(archivo, linea);

        while (getline(archivo, linea)) {

            stringstream ss(linea);

            string idStr;
            string nombre;
            string carrera;
            string semestreStr;
            string gpaStr;
            string skillStr;

            getline(ss, idStr, ',');
            getline(ss, nombre, ',');
            getline(ss, carrera, ',');
            getline(ss, semestreStr, ',');
            getline(ss, gpaStr, ',');
            getline(ss, skillStr, ',');

            Estudiante estudiante;

            estudiante.student_id = stoi(idStr);
            estudiante.full_name = nombre;
            estudiante.career = carrera;
            estudiante.semester = stoi(semestreStr);
            estudiante.gpa = stof(gpaStr);
            estudiante.skill_score = stoi(skillStr);

            insertar(estudiante);
        }

        archivo.close();

        cout << "CSV CARGADO CORRECTAMENTE.\n";
    }
};

int main() {

    cout << "================================\n";
    cout << "Nombre: Emily Monterroso\n";
    cout << "Carne: 9941-24-1489\n";
    cout << "================================\n";

    HashTable hash;

    hash.cargarCSV("../estudiantes.csv");

    int opcion = 0;

    do {

        cout << "\n========= MENU =========\n";
        cout << "1. Mostrar tabla hash\n";
        cout << "2. Buscar estudiante\n";
        cout << "3. Eliminar estudiante\n";
        cout << "4. Mostrar estadisticas\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        if (opcion == 1) {

            hash.mostrarTabla();
        }

        else if (opcion == 2) {

            int idBuscar;

            cout << "Ingrese ID a buscar: ";
            cin >> idBuscar;

            Estudiante* encontrado = hash.buscar(idBuscar);

            if (encontrado != nullptr) {

                cout << "\n=== ESTUDIANTE ENCONTRADO ===\n";

                cout << "ID: "
                     << encontrado->student_id << endl;

                cout << "Nombre: "
                     << encontrado->full_name << endl;

                cout << "Carrera: "
                     << encontrado->career << endl;

            } else {

                cout << "No encontrado.\n";
            }
        }

        else if (opcion == 3) {

            int idEliminar;

            cout << "Ingrese ID a eliminar: ";
            cin >> idEliminar;

            if (hash.eliminar(idEliminar)) {

                cout << "Eliminado correctamente.\n";

            } else {

                cout << "No existe estudiante.\n";
            }
        }

        else if (opcion == 4) {

            hash.mostrarEstadisticas();
        }

        else if (opcion == 5) {

            cout << "Saliendo...\n";
        }

        else {

            cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}