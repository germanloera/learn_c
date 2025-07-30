#include "fileHandler.h"
#include "menu.h"
#include "utils.h"
#include <stdio.h>

int main() {

  printf("\e[1;1H\e[2J");

  p("Sistema de Gestión de Estudiantes Avanzado \n", AC_BLUE);
  char option;
  readFullFile();

  do {

    p("Menu \n", AC_GREEN);

    p("\t (1) Agregar", AC_YELLOW);
    p("\t (2) Listar", AC_YELLOW);
    p("\t (3) Buscar", AC_YELLOW);
    p("\t (4) Guardar", AC_YELLOW);
    p("\t (5) Cargar", AC_YELLOW);
    p("\t (6) Dummy \n", AC_YELLOW);
    p("\t (7) Borrar Archivo \n", AC_YELLOW);

    p("\t (s) Salir\n", AC_YELLOW);
    p("Opcion: ", AC_GREEN);
    scanf(" %c", &option);

    switch (option) {
    case '1': {
      add();
      break;
    }
    case '2': {
      list();
      break;
    }
    case '3': {
      find();
      break;
    }
    case '4': {
      save();
      break;
    }
    case '5': {
      load();
      break;
    }

    case '6': {
      release();
      dummy();
      save();
      break;
    }

    case '7': {
      release();
      deleteFile();
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