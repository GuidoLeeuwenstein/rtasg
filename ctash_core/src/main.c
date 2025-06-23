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
int task_new(Task* task, uint16_t id, const char* name, const char* description) {
    if (strlen(name) >= TASK_NAME_LEN) return -1;
    if (strlen(description) >= TASK_DESC_LEN) return -2;
    task->id = id;
    strncpy(task->name, name, TASK_NAME_LEN);
    strncpy(task->description, description, TASK_DESC_LEN);
    task->status = TASK_PENDING;
    task->date_created = time(NULL);
    task->date_updated = task->date_created;
    return 0;
}

void task_update_status(Task* task, TaskStatus new_status) {
    task->status = new_status;
    task->date_updated = time(NULL);
}

void task_update_name(Task* task, const char* name) {
    if (strlen(name) < TASK_NAME_LEN) {
        strncpy(task->name, name, TASK_NAME_LEN);
        task->date_updated = time(NULL);
    }
}

void task_update_description(Task* task, const char* description) {
    if (strlen(description) < TASK_DESC_LEN) {
        strncpy(task->description, description, TASK_DESC_LEN);
        task->date_updated = time(NULL);
    }
}

void task_print(const Task* task) {
    printf("Task ID: %u\n", task->id);
    printf("Name: %s\n", task->name);
    printf("Description: %s\n", task->description);
    printf("Status: %d\n", task->status);
    printf("Created: %ld\n", task->date_created);
    printf("Updated: %ld\n", task->date_updated);
}

// TaskList struct
typedef struct {
    Task task_list[TASK_LIST_SIZE];
    uint16_t len;
} TaskList;

void tasklist_init(TaskList* list) {
    list->len = 0;
}

void tasklist_destroy(TaskList* list) {
    // No dynamic memory to free in this version
}

int tasklist_push(TaskList* list, const Task* task) {
    if (list->len >= TASK_LIST_SIZE) return -1;
    list->task_list[list->len++] = *task;
    return 0;
}

int tasklist_pop(TaskList* list, Task* out_task) {
    if (list->len == 0) return -1;
    if (out_task) *out_task = list->task_list[--list->len];
    return 0;
}

int main() {
    // Example usage
    TaskList list;
    tasklist_init(&list);
    Task t;
    if (task_new(&t, 1, "Example Task", "This is a description.") == 0) {
        tasklist_push(&list, &t);
        task_print(&t);
    }
    return 0;
} 