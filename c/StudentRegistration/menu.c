#include "list.h"
#include "student.h"
#include "utils.h"
#include <stdio.h>

void add() {
  char opcion;
  p("Agregar estudiante \n", AC_MAGENTA);

  do {
    p("Opciones", AC_GREEN);
    p("\t (e) Pregrado", AC_YELLOW);
    p("\t (o) Postgrado", AC_YELLOW);
    p("\t (r) Regresar", AC_YELLOW);
    scanf(" %c", &opcion);

    switch (opcion) {
    case 'e': {
      createStudent(PRE);
      break;
    }
    case 'o': {
      createStudent(POST);
      break;
    }
    }

  } while (opcion != 'r');
}

void list() { printAll(); }

void find() {

  int id;
  p("Ingrese ID: ", AC_YELLOW);
  scanf(" %i", &id);

  struct Student *element = findElement(id);

  if (element == NULL) {
    p("Elemento no encontrado", AC_RED);
  } else {

    ps(element);
  }
}

void save() {}

void load() {}

void release() {
  releaseMemory();
}