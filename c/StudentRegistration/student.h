#include <stdio.h>

#ifndef STUDENT
#define STUDENT

typedef enum { PRE, POST } StudentType;

struct Student {
  int id;
  char name[10];
  StudentType type;
  union level {
    char degree[10];
    char thesis[10];
  } data;

  struct Student *next;
};

extern struct Student *root;
extern struct Student *last;



void createStudent(StudentType type);

#endif


