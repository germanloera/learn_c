#include "student.h"
#include <cstddef>
#include <string>

Student::Student(int _id, string _name, CareerType _type, string _d){

  id = _id;
  name = _name;
  type = _type;
  if (type == CareerType::PRE) {
    data.degree = _d;
  } else {
    data.thesis = _d;
  }
}

void Student::setNext(Student *_next) { next = _next; }
void Student::setPrev(Student *_prev) { prev = _prev; }

Student *Student::getNext() { return next; }
Student *Student::getPrev() { return prev; }

Student::~Student() {
  prev->setNext(next);
  next->setPrev(prev);
}

Student *root = NULL;
Student *last = NULL;
