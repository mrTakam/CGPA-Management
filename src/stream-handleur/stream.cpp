#include <limits>
#include "stream.hpp"

int int_streamhdl(string to_display) {
    int valeurSaisie;

	cout << to_display;

	if (!(cin >> valeurSaisie)) {
		cerr << "Erreur de saisie." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return int_streamhdl(to_display); // Retourne la valeur mise à jour
	}
    
    return valeurSaisie;
}

// en c la surcharge de fonctionne pas pour modification du retour uniquement
string str_streamhdl(string to_display) {
    string valeurSaisie;

	cout << to_display;

	if (!(cin >> valeurSaisie)) {
		cerr << "\nErreur de saisie !!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return str_streamhdl(to_display); // Retourne la valeur mise à jour
	}
    
    return valeurSaisie;
}

