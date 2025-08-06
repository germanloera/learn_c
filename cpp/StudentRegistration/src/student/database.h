#include "student.h"
#include <fstream>
#include <string>

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class Handler {

public:
  void addStudent(Student *s);

  void saveAllStudents();
  void saveStudent(Student *s, ofstream &file);

  void writeInt(int value, ofstream &file);
  void writeStr(string value, ofstream &file);

  void readFile();
  Student* loadStudent(ifstream &file);

  int readInt(ifstream &file);
  string readStr(ifstream &file);


  void dummy();

  static string filename;
};

extern Handler *h;

#endif