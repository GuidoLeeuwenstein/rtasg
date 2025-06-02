use std::time::SystemTime;

enum TaskStatus {
    Pending,
    InProgress,
    Completed,
}

struct Task {
    id: u32,
    title: String,
    description: String,
    status: TaskStatus,
    date_created: SystemTime,
    date_updated: SystemTime
}

impl Task {
    fn new(id: u32, title: String, description: String) -> Self {
        Self {
            id,
            title,
            description,
            status: TaskStatus::Pending,
            date_created: SystemTime::new(),
            date_updated: SystemTime::new()
        };
    }

    fn start(&mut self) {
        self.status = TaskStatus::InProgress;
         self.date_updated = SystemTime::new()
    }

    fn complete(&mut self) {
        self.status = TaskStatus::Completed;
        self.date_updated = SystemTime::new()
    }

}


