#ifndef SUB_STRUCTURE_H
#define SUB_STRUCTURE_H
#include <string>
#include <vector>
using namespace std;

typedef struct {
    string name;
    string surname;
} student;

typedef struct {
    string name;
    float score;   
} exercice;

typedef struct CopieNode{
    student name;
    vector<exercice> exo_liste; 
    struct CopieNode* suiv;
} copie;

#endif
