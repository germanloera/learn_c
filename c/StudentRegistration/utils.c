#include <stdio.h>
#include "utils.h"
#include "student.h"


void p(char text[100], char color[10]) {

  printf("%s %s %s \n", color, text, AC_NORMAL);
  
}

void ps(struct Student *current) {

        union level *d = &current->data;

      printf(
          "  Student { id: %i; Name: %s; Type: %u; Degree: %s; Tesis: %s} \n",
          current->id, current->name, current->type, d->degree, d->thesis);
  
}