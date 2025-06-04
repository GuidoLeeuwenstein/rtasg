use std::{collections::HashMap, time::SystemTime};

enum TaskStatus {
    Pending,
    InProgress,
    Completed,
}

struct Task {
    id: i8,
    title: String,
    description: String,
    status: TaskStatus,
    date_created: SystemTime,
    date_updated: SystemTime
}

pub struct TaskList<'a> {
    list: [Some<Task>; 100],
    table: HashMap<i8, &'a Task>
}

impl Task {
    fn new(id: i8, title: String, description: String) -> Self {
        return Self {
            id,
            title,
            description,
            status: TaskStatus::Pending,
            date_created: SystemTime::now(),
            date_updated: SystemTime::now()
        };
    }

    fn start(&mut self) {
        self.status = TaskStatus::InProgress;
         self.date_updated = SystemTime::now()
    }

    fn complete(&mut self) {
        self.status = TaskStatus::Completed;
        self.date_updated = SystemTime::now()
    }

}



impl TaskList<'a>{
    fn new() -> Self {
        return Self {
            list : [None; 100],
            table : HashMap::new()
        }
    }

    fn add(&self, task: Task) -> Result {
    }

    fn pop(&self, task_id: u32) -> i8 {
        
    }

}
