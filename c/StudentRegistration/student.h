#include <stdio.h>

#ifndef STUDENT_H
#define STUDENT_H

typedef enum { PRE, POST } StudentType;

struct Student {
  int id;
  char *name;
  StudentType type;
  union {
    char *degree;
    char* thesis;
  } data;

  struct Student* next;
};

extern struct Student *root;
extern struct Student *last;

void add();
void list();
void find();
void save();
void load();

#endif


