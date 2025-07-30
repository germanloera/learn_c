#include "fileHandler.h"
#include "list.h"
#include "student.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saveRegistrationStudents(struct Student *listStart) {

  struct Student *current = listStart;

  while (current != NULL) {

    saveStudentToFile(current);
    current = current->next;
  }
}
void saveStudentToFile(struct Student *item) {
  FILE *file = fopen(filename, "ab");

  if (file == NULL) {
    p("Unable to open the file 2", AC_RED);
    return;
  }

  int studentType = (int)item->type;

  writeint(file, item->id);
  writestr(file, item->name);

  writeint(file, studentType);

  if (item->type == PRE) {
    writestr(file, item->data.degree);

  } else {
    writestr(file, item->data.thesis);
  }

  p("Item Saved", AC_RED);

  fclose(file);
}

void readFullFile() {

  FILE *file = fopen(filename, "rb");

  if (file == NULL) {
    p("Unable to open the file 3", AC_RED);
    return;
  }

  while (feof(file) == 0) {

    char *name = malloc(10);
    char *data = malloc(10);
    int id = readInt(file);
    readString(file, name);
    int type = readInt(file);
    readString(file, data);

    struct Student *s = (struct Student *)malloc(sizeof(struct Student));

    s->id = id;
    strcpy(s->name, name);
    if (type == 0) {
      s->type = PRE;
      strcpy(s->data.degree, data);
    } else {
      s->type = POST;
      strcpy(s->data.thesis, data);
    }

    ps(s);
    addElementToList(s);
  }

  fclose(file);
  printAll();
}

int readInt(FILE *file) {
  int value = 0;
  int result = fread(&value, sizeof(int), 1, file);
  // printf("value: %d \n", value);
  if (result < 1) {
    p("unable to read int value 4", AC_RED);
  }

  return value;
}

int readString(FILE *file, char *text) {

  int size = readInt(file);
  char *value = malloc(size + 1);
  int result;

  if (size > 0) {

    result = fread(value, sizeof(char), size, file);
  
    if (result < 1) {
      p("unable to read string value 5", AC_RED);
    }

    snprintf(text, sizeof(char) * (size+1), "%s", value);

  }

  return result;
}

void writestr(FILE *file, char *value) {
  int size = strlen(value);
  writeint(file, size);
  fwrite(value, sizeof(char), size , file);
}

void writeint(FILE *file, int value) { fwrite(&value, sizeof(int), 1, file); }

void deleteFile() {

  // Attempt to delete the file
  if (remove(filename) == 0) {
    printf("File '%s' deleted successfully.\n", filename);
  } else {
    perror("Error deleting file"); // Prints a system-specific error message
  }
}