#include <ctime>
#include <iostream>
#include <string>
using namespace std;

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

int getCurrentYear() {

  time_t currentTime = time(nullptr);
  tm *currentTimeFormatted = localtime(&currentTime);
  return currentTimeFormatted->tm_year + 1900;
}

int main() {

  string nombre;
  int anio;

  cout << "Please, type your name: ";
  cin >> nombre;
  cout << "Now, type your birth year: ";
  cin >> anio;

  int edad = getCurrentYear() - anio;

  cout << "Hi! " << nombre << ", your estimated age is " << edad << endl;

  return 0;
}
