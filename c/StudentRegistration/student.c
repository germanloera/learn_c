#include "student.h"
#include "list.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student *root = NULL;
struct Student *last = NULL;

void createStudent(StudentType type) {
  char *t = "Pregrado";

  if (type == POST) {

    t = "Postgrado";
  }
  struct Student *s = (struct Student *)malloc(sizeof(struct Student));

  s->type = type;

  printf("Creando Estudiante de %s \n", t);

  p("ID: ", AC_YELLOW);
  scanf(" %i", &s->id);

  p("Nombre: ", AC_YELLOW);
  scanf(" %s", s->name);

  if (type == POST) {

    p("Tesis: ", AC_YELLOW);
    scanf(" %s", s->data.thesis);

  } else {
    p("Carrera: ", AC_YELLOW);
    scanf(" %s", s->data.degree);
  }

  s->next = NULL;

  addElementToList(s);
  p("Creado \n", AC_YELLOW);
}

void createDummyStudents() {

  struct Student *s1 = (struct Student *)malloc(sizeof(struct Student));
  s1->id = 91;
  strcpy(s1->name, "qwerty");
  s1->type = PRE;
  strcpy(s1->data.degree, "qwerty");
  addElementToList(s1);

  struct Student *s2 = (struct Student *)malloc(sizeof(struct Student));
  s2->id = 92;
  strcpy(s2->name, "asdfg");
  s2->type = PRE;
  strcpy(s2->data.degree, "asdfg");
  addElementToList(s2);

  struct Student *s3 = (struct Student *)malloc(sizeof(struct Student));
  s3->id = 93;
  strcpy(s3->name, "zxcvb");
  s3->type = PRE;
  strcpy(s3->data.degree, "zxcvb");
  addElementToList(s3);

  struct Student *s4 = (struct Student *)malloc(sizeof(struct Student));
  s4->id = 94;
  strcpy(s4->name, "mnbvc");
  s4->type = POST;
  strcpy(s4->data.thesis, "mnbvc");
  addElementToList(s4);

  struct Student *s5 = (struct Student *)malloc(sizeof(struct Student));
  s5->id = 95;
  strcpy(s5->name, "yuiop");
  s5->type = POST;
  strcpy(s5->data.thesis, "yuiop");
  addElementToList(s5);
  printAll();
}
