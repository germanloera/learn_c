#include "student.h"
#include "list.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

struct Student *root = NULL;
struct Student *last = NULL;

void createStudent(StudentType type) {
  char *t = "Pregrado";

  if (type == POST) {

    t = "Postgrado";
  }
  struct Student* s =(struct Student*)malloc(sizeof( struct Student));

  s->type = type;

  printf("Creando Estudiante de %s \n", t);

  p("ID: ", AC_YELLOW);
  scanf(" %i", &s->id);


  p("Nombre: ", AC_YELLOW);
  scanf(" %s", s->name);

  
  if (type == POST) {

    p("Tesis: ", AC_YELLOW);
    scanf(" %s", s->data.thesis);

  } else {
    p("Carrera: ", AC_YELLOW);
    scanf(" %s", s->data.degree);
  }

  s->next = NULL;

  addElementToList(s);
  p("Creado \n", AC_YELLOW);
}
