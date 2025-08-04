
#include <string>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

enum class CareerType { PRE, POST };

struct Student {
  int id;
  string name;
  CareerType type;
  union Data {
    string degree;
    string thesis;

    Data() { memset(this, 0, sizeof(*this)); }
    ~Data(){}
  } data;

  Student *next;
  Student *prev;

public:
  Student(int _id, string _name, CareerType _type, string _d);
  ~Student();

  void setNext(Student *_next);
  void setPrev(Student *_prev);

  Student *getNext();
  Student *getPrev();
};

extern Student *root;
extern Student *last;

#endif