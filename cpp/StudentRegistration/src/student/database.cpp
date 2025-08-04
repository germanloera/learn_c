#include "database.h"



Handler *h = new Handler();

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