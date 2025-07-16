#include <stdio.h>
#include <stdlib.h>

/*
El Ejercicio: Adivina el Número

Escribe un programa en C y otro en C++ que realice un pequeño juego:

    El programa debe "pensar" en un número secreto al azar entre 1 y 100.
    Luego, debe pedirle al usuario que intente adivinar cuál es el número.
    Después de cada intento del usuario, el programa le dará una pista,
    indicando si su número es "muy alto" o "muy bajo" en comparación con el
número secreto. El juego continúa hasta que el usuario adivina el número
correcto. Cuando el usuario adivina, el programa lo felicita y le dice cuántos
intentos necesitó.

Ejemplo de ejecución:

He pensado un número entre 1 y 100. ¡Intenta adivinarlo!
Tu intento: 50
Muy bajo.
Tu intento: 75
Muy alto.
Tu intento: 63
¡Felicidades! Adivinaste el número en 3 intentos.


*/

int main() {

  int counter = 0;
  int userNumber;
  int randomNumber = (rand() % 100) + 1;

  printf("He pensado un numero entre 1 y 100, Intenta Adivinarlo!\n");

  do {
    counter++;

    scanf("%i", &userNumber);
    printf("Tu intento: %i \n", userNumber);

    if (userNumber < randomNumber) {
      printf("Muy bajo \n");

    } else if (userNumber > randomNumber) {

      printf("Muy alto \n");

    } else {

      printf(
          "Felicidades! Adivinaste el numero en %i intentos, el numero es: %i \n",
          counter, randomNumber);
    }

  } while (userNumber != randomNumber);

  return 0;
}
