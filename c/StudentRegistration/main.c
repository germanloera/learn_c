#include "utils.h"
#include <stdio.h>
#include "menu.h"


int main() {

  printf("\e[1;1H\e[2J");

  p("Sistema de Gestión de Estudiantes Avanzado \n", AC_BLUE);
  char option;

  do {

    p("Menu \n", AC_GREEN);

    p("\t (a) Agregar", AC_YELLOW);
    p("\t (l) Listar", AC_YELLOW);
    p("\t (b) Buscar", AC_YELLOW);
    p("\t (g) Guardar", AC_YELLOW);
    p("\t (c) Cargar", AC_YELLOW);
    p("\t (s) Salir\n", AC_YELLOW);
    p("Opcion: ", AC_GREEN);
    scanf(" %c", &option);

    switch (option) {
    case 'a': {
      add();
      break;
    }
    case 'l': {
      list();
      break;
    }
    case 'b': {
      find();
      break;
    }
    case 'g': {
      save();
      break;
    }
    case 'c': {
      load();
      break;
    }
    case 's': {
      release();
      return 0;
    }
    }

  } while (option != 's');
  return 0;
}