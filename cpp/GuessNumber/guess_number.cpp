#include <iostream>
#include <random>
using namespace std;

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
  // configurar para obtener numeros aleatorios
  random_device device;
  mt19937 generador(device());
  uniform_int_distribution<int> distribucion(1, 100);
  //

  int counter = 0;
  int userNumber;
  int randomNumber = distribucion(generador); // obtener numero aleatorio

  cout << "He pensado un número entre 1 y 100. ¡Intenta adivinarlo!" << endl;

  do {
    counter++;
    cin >> userNumber;

    if (userNumber < randomNumber) {
      cout << "Muy bajo" << endl;
    } else if (userNumber > randomNumber) {
      cout << "Muy alto" << endl;
    } else {
      cout << "Felicidades! Adivinaste el numero en " << counter
           << " intentos, el numero es: " << randomNumber << endl;
    }

  } while (userNumber != randomNumber);

  return 0;
}