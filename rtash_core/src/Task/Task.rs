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
}

impl Task {
    fn new(id: u32, title: String, description: String) -> Self {
        Self {
            id,
            title,
            description,
            status: TaskStatus::Pending,
        }
    }

    fn start(&mut self) {
        self.status = TaskStatus::InProgress;
    }

    fn complete(&mut self) {
        self.status = TaskStatus::Completed;
    }

    fn get_status(&self) -> &TaskStatus {
        &self.status
    }
}


