#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define TASK_NAME_LEN 256
#define TASK_DESC_LEN 256
#define TASK_LIST_SIZE 100

// Task status enum
typedef enum {
    TASK_PENDING,
    TASK_IN_PROGRESS,
    TASK_DONE,
    TASK_STOPPED
} TaskStatus;

// Task struct
typedef struct {
    uint16_t id;
    char name[TASK_NAME_LEN];
    char description[TASK_DESC_LEN];
    TaskStatus status;
    time_t date_created;
    time_t date_updated;
} Task;


// Task constructor
int task_new(Task* task, uint16_t id, const char* name, const char* description);

void task_update_status(Task* task, TaskStatus new_status);

void task_update_name(Task* task, const char* name);

void task_update_description(Task* task, const char* description);

void task_print(const Task* task);

// TaskList struct
typedef struct {
    Task task_list[TASK_LIST_SIZE];
    uint16_t len;
} TaskList;

void tasklist_init(TaskList* list);

void tasklist_destroy(TaskList* list);

int tasklist_push(TaskList* list, const Task* task);

int tasklist_pop(TaskList* list, Task* out_task);