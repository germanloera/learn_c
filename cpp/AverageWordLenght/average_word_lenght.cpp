#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

/*
Write a program that calculates the average word length for a sentence:
Enter a sentence It was deja vu all over again.
Average word length: 3.4
For simplicity, your program should consider a punctuation mark to be part
*/

int main() {

  int palabras = 0;
  float caracteres = 0;

  string frase;
  cout << "Escribe una frase: ";
  getline(cin, frase);
  for (int i = 0; i < frase.length(); i++) {
    char c = frase.at(i);
    if (c == ' ') {
      palabras++;
    } else {
      caracteres++;
    }
  }
  palabras++;

  float av = caracteres / palabras;

  cout << "El promedio de letras por palabra es: " << fixed << setprecision(2) << av << endl;

  return 0;
}