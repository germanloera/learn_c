
#include "list.h"
#include "student.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void addElementToList(struct Student *newItem) {

  if (root == NULL) {

    root = newItem;
    last = root;

  } else {
    last->next = newItem;
    last = last->next;
  }

  printAll();
}

struct Student *findElement(int id) {

  if (root == NULL) {
    return NULL;
  } else {

    struct Student *current = root;

    while (current != NULL) {

      if (current->id == id) {
        return current;
      } else {
        current = current->next;
      }
    }

    return NULL;
  }
}

void removeElement(int id) {}

void printAll() {

  struct Student *current = root;

  if (current == NULL) {
    p("La lista se encuentra vacia ", AC_RED);
  } else {

    while (current != NULL) {

      ps(current);

      current = current->next;
    }
  }
}

void releaseMemory() {

  if (root != NULL) {

    struct Student *current = root;
    struct Student *next;

    while (current != NULL) {

      next = current->next;
      free(current);
      current = next;

    }
  }

}
