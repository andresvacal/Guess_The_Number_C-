#include <iostream>
#include <vector>

using namespace std;

int busquedaBinariaRecursiva(const vector<int>& numeros, int objetivo, int bajo, int alto) {
    if (bajo > alto) {
        return -1; // No encontrado
    }

    int medio = bajo + (alto - bajo) / 2;

    if (numeros[medio] == objetivo) {
        return medio;
    } else if (numeros[medio] < objetivo) {
        return busquedaBinariaRecursiva(numeros, objetivo, medio + 1, alto);
    } else {
        return busquedaBinariaRecursiva(numeros, objetivo, bajo, medio - 1);
    }
}

int busquedaBinaria(const vector<int>& numeros, int objetivo) {
    return busquedaBinariaRecursiva(numeros, objetivo, 0, numeros.size() - 1);
}

void jugarJuego(const vector<int>& numeros, int bajo, int alto) {
    if (bajo > alto) {
        cout << "El número no fue adivinado." << endl;
        return;
    }

    int medio = bajo + (alto - bajo) / 2;
    int intentoCounter = 1;  // Counter for attempts

    while (true) {
        cout << "¿Tu número es mayor (1), menor (2) o igual (3) a " << numeros[medio] << "? ";
        int intento;
        cin >> intento;

        if (intento == 1) {
            bajo = medio + 1;
        } else if (intento == 2) {
            alto = medio - 1;
        } else if (intento == 3) {
            cout << "El número fue adivinado en " << intentoCounter << " intentos." << endl;
            break;
        } else {
            cout << "Entrada inválida. Saliendo." << endl;
            return;
        }

        medio = bajo + (alto - bajo) / 2;
        intentoCounter++;
    }
}

int main() {
    int eleccion;
    cout << "Elige el rango del número:" << endl;
    cout << "1. 1 a 100" << endl;
    cout << "2. 1 a 1000" << endl;
    cout << "3. 1 a 10000" << endl;
    cout << "Ingresa tu elección (1, 2 o 3): ";
    cin >> eleccion;

    int rango;
    switch (eleccion) {
        case 1:
            rango = 100;
            break;
        case 2:
            rango = 1000;
            break;
        case 3:
            rango = 10000;
            break;
        default:
            cout << "Elección inválida. Saliendo." << endl;
            return 1;
    }

    vector<int> numeros;
    for (int i = 1; i <= rango; ++i) {
        numeros.push_back(i);
    }

    jugarJuego(numeros, 0, numeros.size() - 1);

    return 0;
}
