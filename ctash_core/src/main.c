#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tasklist_init(TaskList *list) { list->len = 0; }

int tasklist_push(TaskList *list, const Task *task) {
  if (list->len >= TASK_LIST_SIZE)
    return -1;
  list->task_list[list->len++] = *task;
  return 0;
}

int tasklist_pop(TaskList *list, Task *out_task) {
  if (list->len == 0)
    return -1;
  if (out_task)
    *out_task = list->task_list[--list->len];
  return 0;
}

int task_new(Task *task, uint16_t id, const char *name,
             const char *description) {
  if (strlen(name) >= TASK_NAME_LEN)
    return -1;
  if (strlen(description) >= TASK_DESC_LEN)
    return -2;
  task->id = id;
  strncpy(task->name, name, TASK_NAME_LEN);
  strncpy(task->description, description, TASK_DESC_LEN);
  task->status = TASK_PENDING;
  task->date_created = time(NULL);
  task->date_updated = task->date_created;
  return 0;
}

void task_update_status(Task *task, TaskStatus new_status) {
  task->status = new_status;
  task->date_updated = time(NULL);
}

void task_update_name(Task *task, const char *name) {
  if (strlen(name) < TASK_NAME_LEN) {
    strncpy(task->name, name, TASK_NAME_LEN);
    task->date_updated = time(NULL);
  }
}

void task_update_description(Task *task, const char *description) {
  if (strlen(description) < TASK_DESC_LEN) {
    strncpy(task->description, description, TASK_DESC_LEN);
    task->date_updated = time(NULL);
  }
}

void task_print(const Task *task) {
  printf("Task ID: %u\n", task->id);
  printf("Name: %s\n", task->name);
  printf("Description: %s\n", task->description);
  printf("Status: %d\n", task->status);
  printf("Created: %ld\n", task->date_created);
  printf("Updated: %ld\n", task->date_updated);
}

int main(int argc, char **argv) {
  char name[TASK_NAME_LEN];

  if (argc < 2) {
    printf("Usage: %s <add|list|done> [args]\n", argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "add") == 0) {
    int nameEnd;
    int discEnd = argc;
    if(argc <= 2) {

      return 1;
    }
    for (int i = 2; i < argc; i++) {
      printf("index is %i \n", i);
      
      if (strcmp(argv[i], ";") ==0 ) {
        nameEnd = i;
        break;
      };
      nameEnd = i;
    }
    name[0] = '\0'; // Start with an empty string
    for (int i = 2; i <= nameEnd; i++) {
        if (i > 2) strlcat(name, " ", TASK_NAME_LEN); // Add space between words
        strlcat(name, argv[i], TASK_NAME_LEN);
    }
    printf("this is the string = %s\n", name);
  }
  
  return 0;
}
