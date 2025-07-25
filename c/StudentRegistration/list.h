#include <stdio.h>
#include "student.h"
#include "utils.h"

#ifndef LIST_H
#define LIST_H

void addElementToList(struct Student *newItem);

struct Student* findElement(int id);

void removeElement(int id);

void printAll(void);

void releaseMemory();

#endif