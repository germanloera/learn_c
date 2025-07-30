#include <stdio.h>
#include "student.h"

#ifndef FILE_HANDLER
#define FILE_HANDLER

static char filename[] = "StudentRegistration.bin";

void saveRegistrationStudents(struct Student *listStart);
void saveStudentToFile(struct Student *listStart);
void readFullFile();

int readInt(FILE *file);
int readString(FILE *File, char *text);

void writeint(FILE *file, int value);
void writestr(FILE *file, char *value);

void deleteFile();
    

#endif