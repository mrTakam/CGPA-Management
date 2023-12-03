#ifndef SUB_STRUCTURE_H
#define SUB_STRUCTURE_H
#include <string>
using namespace std;

typedef struct {
    string name;
    string surname;
} student;

typedef struct {
    string name;
    float score;   
} exercice;

//exercice exo_liste[nb_exercice]; this don't work --> // Use a pointer for dynamic allocation 
typedef struct CopieNode{
    student name;
    int nb_exercice;
    exercice* exo_liste; 
    struct CopieNode* suiv;
} copie;

void register_student();
void reister_exercice();
void register_copie();


/*
enum Gpa {
    A, B, C, 
    D, E, F    
};

enum Order{
    first, second, third, fourth, 
    fifth, sixth, seventh, eighth, 
    ninth, tenth, eleventh, twelfth, 
    thirteenth, fourteenth, fifteenth
};
*/

#endif
