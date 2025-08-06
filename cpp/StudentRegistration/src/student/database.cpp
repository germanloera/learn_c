#include "database.h"
#include <cstddef>
#include <cstring>
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

Handler *h = new Handler();

string Handler::filename = "students.bin";

void Handler::addStudent(Student *s) {
  if (root == NULL) {
    root = s;
    last = root;
  } else {
    last->setNext(s);
    s->setPrev(last);
    last = last->next;
  }
};

void Handler::saveAllStudents() {

  ofstream file(filename, ios::binary | ios::ate);

  if (!file.is_open()) {
    cout << "saveAllStudents: Error abriendo el archivo" << endl;
    return;
  }

  Student *current = root;

  while (current != NULL) {

    try {
      saveStudent(current, file);
    } catch (exception &e) {
      cout << e.what() << endl;
    }
    current = current->getNext();
  }

  file.close();
}
void Handler::saveStudent(Student *s, ofstream &file) {

  writeInt(s->id, file);
  writeStr(s->name, file);

  int type = 1;
  string data = "DATA";
  if (s->type == CareerType::PRE) {
    type = 0;
    data = s->data.degree.c_str();
  } else {
    data = s->data.thesis.c_str();
  }

  writeInt(type, file);
  writeStr(data, file);
}

void Handler::writeInt(int value, ofstream &file) {
  if (file.is_open()) {

    try {
      file.write(reinterpret_cast<char *>(&value), sizeof(value));

    } catch (exception &e) {
      cout << "Error: " << e.what() << endl;
    }

  } else {
    cout << "writeInt: Error abriendo el archivo 2" << endl;
  }
}
void Handler::writeStr(string value, ofstream &file) {

  if (file.is_open()) {

    int longitud = value.length();
    writeInt(longitud, file);

    try {
      file.write(value.c_str(), longitud);

    } catch (exception &e) {
      cout << e.what() << endl;
    }

  } else {
    cerr << "writeStr: Error abriendo el archivo 3" << endl;
  }
}

void Handler::readFile() {
  ifstream file(filename, ios::binary);

  if (!file.is_open()) {
    cerr << "readFile: Error abriendo el archivo 4" << endl;
    return;
  }

  while (!file.eof()) {
    Student *s = loadStudent(file);
    addStudent(s);
  };

  file.close();
}
Student *Handler::loadStudent(ifstream &file) {

  int id = readInt(file);
  string name = readStr(file);
  int type = readInt(file);
  string data = readStr(file);
  CareerType t = CareerType::PRE;

  cout << "id: " << id << ", name: " << name << ", type: " << type
       << ", data: " << data << endl;

  if (type == 1) {
    t = CareerType::POST;
  }

  Student *s = new Student(id, name, t, data);

  return s;
}

int Handler::readInt(ifstream &file) {
  int value;
  if (file.is_open()) {

    file.read(reinterpret_cast<char *>(&value), sizeof(value));
  } else {
    cerr << "readInt: Error abriendo el archivo 5" << endl;
  }
  return value;
}

string Handler::readStr(ifstream &file) {

  if (file.is_open()) {

    int longitud = readInt(file);
    // Crear buffer para el string
    char *buffer = new char[longitud ];
    file.read(buffer, longitud);
    buffer[longitud] = '\0'; // Terminar string
    std::string texto(buffer);
    delete[] buffer;

    return texto;

  } else {
    cerr << "readInt: Error abriendo el archivo 5" << endl;
  }
  return "";
}

void Handler::dummy() {

  Student *s1 = new Student(1, "aaa", CareerType::PRE, "aaa");
  addStudent(s1);
  Student *s2 = new Student(2, "bbb", CareerType::PRE, "bbb");
  addStudent(s2);
  Student *s3 = new Student(3, "ccc", CareerType::PRE, "ccc");
  addStudent(s3);
  Student *s4 = new Student(4, "ddd", CareerType::POST, "ddd");
  addStudent(s4);
  Student *s5 = new Student(5, "eee", CareerType::POST, "eee");
  addStudent(s5);
  Student *s6 = new Student(6, "fff", CareerType::POST, "fff");
  addStudent(s6);
}
