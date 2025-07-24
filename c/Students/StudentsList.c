

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
/*
Roster Dinámico de Estudiantes

Escribe un programa en C y otro en C++ que permita al usuario gestionar una
lista de estudiantes. El programa no sabrá cuántos estudiantes se van a
introducir de antemano.

    El programa debe permitir al usuario realizar dos acciones: "agregar un
estudiante" o "mostrar todos los estudiantes". Para "agregar", el programa
pedirá un nombre y una calificación (un número entero). El programa debe
almacenar esta información en una lista que crezca dinámicamente a medida que se
añaden estudiantes. Al "mostrar", el programa imprimirá el nombre y la
calificación de todos los estudiantes introducidos hasta el momento. El programa
debe gestionar la memoria correctamente, liberando todos los recursos al
finalizar (aunque no lo veas explícitamente, es la parte más importante del
ejercicio).

Ejemplo de ejecución:

(a)gregar, (m)ostrar, (s)alir: a
Nombre: Carlos
Calificación: 95
Estudiante agregado.

(a)gregar, (m)ostrar, (s)alir: a
Nombre: Beatriz
Calificación: 88
Estudiante agregado.

(a)gregar, (m)ostrar, (s)alir: m
--- Lista de Estudiantes ---
Carlos - 95
Beatriz - 88
--------------------------

(a)gregar, (m)ostrar, (s)alir: s
Liberando memoria... Adiós.
*/

struct Student {
  char name[50];
  int score;
};

void println(char text[100]) { printf("%s \n", text); }

int main() {

  int count = 0;

  struct Student *list = (struct Student *)malloc(1 * sizeof(struct Student));
  /*
Imagina que struct Student es un "kit de estudiante" que contiene una libreta
grande (char name[50]) y un bolígrafo (int score).


    Mi línea: struct Student* clase = (struct Student*) malloc(capacity *
sizeof(struct Student));

Esto es como ir a un almacén y decir: "Necesito espacio
para capacity (digamos 10) kits de estudiante completos. Dame exactamente los
metros cuadrados que necesito para esos 10 kits". El almacén te da un espacio
perfectamente medido.

Tu línea: struct Student *list = malloc(1);
Esto es como ir al mismo almacén y decir: "Dame 1 metro cuadrado de espacio". El
almacén te da tu metro cuadrado. Luego, intentas meter a la fuerza 10 kits de
estudiante completos en ese pequeño espacio. El resultado es un desastre: las
libretas se rompen, los bolígrafos se pierden y todo se desparrama por el
espacio de los demás, corrompiendo sus pertenencias.
*/

  // ¡CRÍTICO! Siempre comprueba si malloc devolvió NULL (falló por falta de
  // memoria).
  if (list == NULL) {
    printf("Error: No se pudo asignar memoria.\n");
    return 1; // Salir con un código de error
  }

  char option;

  do {

    option = ' ';
    printf("(a)gregar, (m)ostrar, (s)alir: \n ");
    scanf("%c", &option);

    switch (option) {
    case 'a': {

      printf("Nombre: ");
      scanf("%s", list[count].name);
      printf("Score: ");
      scanf("%i", &list[count].score);

      count++;
      struct Student *tempList =
          (struct Student *)realloc(list, count + 1 * sizeof(struct Student));

      // ¡CRÍTICO! Siempre comprueba si realloc devolvió NULL (falló por falta
      // de memoria).
      if (list == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1; // Salir con un código de error
      }

      list = tempList;

      printf("Total Items: %i  }\n",count);

      break;
    }

    case 'm': {

      for (u_long i = 0; i < count; i++) {
        struct Student s = list[i];
        printf("i: %lu, Nombre: %s; Score: %i \n", i, s.name, s.score);
      }

      break;
    }

    case 's': {

      free(list);
      println("Liberando memoria... Adiós.");

      return 0;
      break;
    }
    }

  } while (option != 's');
}