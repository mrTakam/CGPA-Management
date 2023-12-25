#include "..\..\include\structure\main_structure.hpp"


student registerStudent(){
    student studentID;
    studentID.name = str_input("provide the student name : ");
    studentID.surname = str_input("provide the student surname : ");
    return studentID;
}

exercice registerExercice(string name) {
    exercice exo;
    exo.name = name;
    string toDisplay = "provide the grade of the " + name + " exercice : ";
    exo.score = int_input(toDisplay);
    return exo;
}

copie* addCopie(copie* cliste, student studentID, vector<exercice> exo_liste) {
	copie* new_copie = (copie*)malloc(sizeof(copie));
	
	new_copie->name = studentID;
    new_copie->exo_liste = exo_liste;
	new_copie->suiv = cliste;

	return new_copie;
}

copie* getExam() {
    int nb_exercice = int_input("provide the number of exercice in the exam : ");    
    vector<string> exoName;
    for (int i = 0; i < nb_exercice; i++) {
        string toDisplay = "veuillez saisir le thème du " + to_string(i + 1) + "e exercice : ";
        exoName.push_back(str_input(toDisplay));
    }
    
    copie* cliste = (copie*)malloc(sizeof(copie));
    cliste->suiv = NULL; 
    vector<exercice> listeExo;
    student studentID;
    
    int nb_copie = int_input("veuillez saisir le nombre de copie : ");
    for(int i = 0; i < nb_copie; i++) {
        studentID = registerStudent();
        for (const auto& str : exoName) {
            listeExo.push_back(registerExercice(str));
        }
        cliste = addCopie(cliste, studentID, listeExo);
        listeExo.clear();
    }

    return cliste;
}



