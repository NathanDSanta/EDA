// Creat per jhg 24/25
// Codi simple que mostra per pantalla els primers N nombres primers 
// El valor N es demana a l'usuari

#include <iostream>
#include <cmath>

using namespace std;

// Funció que comprova si un nombre és primer
bool esPrimer(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    string nom;
    int N;

    cerr << "Hola! Com et dius? ";
    cin >> nom;

    cerr << "Genial, " << nom << "! Quants nombres primers vols? ";
    cin >> N;

    if (N > 0) { // Trobar i mostrar els primers N nombres primers
        cout << "Els primers " << N << " nombres primers són: ";
        int num = 2; // El primer nombre primer és 2
	cout << num++;
        int comptador = 1; // ja hem mostrar el 2
        while (comptador < N) {
            if (esPrimer(num)) {
                cout << ", " << num;
                comptador++;
            }
            num += 2; // cap altre nombre senar és primer
        }
        cout << endl;
    }
    else {
        cout << "El nombre ha de ser positiu!" << endl;
    }
    return 0;
}
