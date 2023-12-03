#ifndef MAIN_STRUCTURE_H
#define MAIN_STRUCTURE_H
#include "sub_structure.hpp"

typedef struct {
    string name;
    copie* liste; //plusieur tête de liste si plusieurs DE
} course;

#define MAX_COURSE 12
typedef struct {
    int number;
    course course_liste[MAX_COURSE];
} semester;

void register_course();
void register_semester();
#endif