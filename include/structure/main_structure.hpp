#ifndef MAIN_STRUCTURE_H
#define MAIN_STRUCTURE_H
#include "sub_structure.hpp"
#include "..\stream-handleur\stream.hpp"

typedef struct {
    string name;
    vector<copie> exam; //plusieur tête de liste si plusieurs DE
} course;

#define MAX_COURSE 12
typedef struct {
    int number;
    course course_liste[MAX_COURSE];
} semester;

copie* getExam();

#endif

