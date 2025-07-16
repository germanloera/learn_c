#include <iostream>
#include <ostream>
using namespace std;

void line(), message(), println(char *);

int main() {

  line();
  message();
}

void println(const char *texto) {
  cout << texto;
  cout << endl;
}

void line() { println("metodo Line"); }

void message() { println("metodo message"); }