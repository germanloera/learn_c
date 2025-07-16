#include <stdio.h>
#include <time.h>

/*
El Ejercicio: Saludo Personalizado

Escribe un programa en C y otro en C++ que haga lo siguiente:

    Pida al usuario que introduzca su nombre.
    Pida al usuario que introduzca su año de nacimiento.
    Calcule su edad aproximada.
    Muestre en pantalla un mensaje de saludo que incluya su nombre y su edad.

Ejemplo de ejecución:

Por favor, introduce tu nombre: Ana
Introduce tu año de nacimiento: 1995
Hola Ana, tienes aproximadamente 30 años.
*/

int main() {

  char name[50];
  int edad;

  // Obtener el anio actual
  time_t currentTime = time(NULL);
  struct tm *currentTimeFormated = localtime(&currentTime);
  int year = currentTimeFormated->tm_year + 1900;
  //



  printf("Please, type your name: ");
  scanf("%s", name);
  printf("\n");
  printf("Now, type your birth year: ");
  scanf("%i", &edad);

  int edadCalculada = year - edad;
  
  printf("Hi! %s, your estimated age is %i\n", name, edadCalculada );
}