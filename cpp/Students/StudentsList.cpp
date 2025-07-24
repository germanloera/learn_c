#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
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
  string name;
  int score;

  Student(const string n, int s) : name(n), score(s) {
    cout << "Objeto creado, name: " << name << " score: " << score << endl;
  }

  ~Student() {
    cout << "Objeto destruido, name: " << name << " score: " << score << endl;
  }
};

int main() {

  char opcion;
  vector<unique_ptr<Student>> list;

  do {

    cout << "(a)gregar, (m)ostrar, (s)alir:" << endl;
    cin >> opcion;

    switch (opcion) {

    case 'a': {

      string n;
      int s;
      cout << "Nombre: " << endl;
      cin >> n;
      cout << "Score: " << endl;
      cin >> s;
      list.push_back(make_unique<Student>(n, s));

      break;
    }
    case 'm': {

      for (unique_ptr<Student> &s : list) {
        cout << "Nombre: " << s->name << ", Score: " << s->score << endl;
      }

      break;
    }

    case 's': {

      cout << "Saliendo " << endl;
      return 0;
      break;
    }

    }

  } while (opcion != 's');

  return 0;
}