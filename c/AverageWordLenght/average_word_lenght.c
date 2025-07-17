#include <stdio.h>

/*
Write a program that calculates the average word length for a sentence:
Enter a sentence It was deja vu all over again.
Average word length: 3.4
For simplicity, your program should consider a punctuation mark to be part
*/

int main(void) {
  printf("Escribe una frase: ");
  char fraseBuffer[200];

  fgets(fraseBuffer, sizeof(fraseBuffer), stdin);

  int palabras = 0;
  float caracteres = 0;

  for (int i = 0; i < sizeof(fraseBuffer); i++) {
    char c = fraseBuffer[i];
   // printf("c: %c, Palabras: %i, caracteres: %f \n", c, palabras, caracteres);
    
    if (c == ' ') {
      palabras++;
    } else if (c == '\n') {
      palabras++;
      break;
    } else {
      caracteres++;
    }
  }

  float average = caracteres / palabras;

  printf("El promedio de letras por palabra es: %.2f \n", average);

  return 0;
}