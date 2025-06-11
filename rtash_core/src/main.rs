use std::time::SystemTime;

#[derive(Debug, Copy, Clone)]
enum TaskStatus {
    Pending,
    InProgress,
    Done,
    Stoppped,
}

#[derive(Debug, Copy, Clone)]
struct Task<'a> {
    id: u16,
    name: &'a str,
    discription: &'a str,
    status: TaskStatus,
    date_created: SystemTime,
    data_updated: SystemTime,
}

impl<'a> Task<'a> {
    fn new(id: u16, name: &'a str, discription: &'a str) -> Task<'a> {
        let current_datetime = SystemTime::now();
        Task {
            id,
            name: name,
            discription: discription,
            status: TaskStatus::Pending,
            date_created: current_datetime,
            data_updated: current_datetime,
        }
    }

    fn update_status(&mut self, new_status: TaskStatus) {
        self.status = new_status
    }

    fn update_name(&mut self, name: &'a str) {
        self.name = name
    }

    fn update_description(&mut self, discription: &'a str) {
        self.discription = discription
    }

    fn print(&self) -> () {
        ()
    }
}

struct TaskList {
    task_list: [Task; 100],
    len: u16,
}

impl TaskList {
    fn new() -> Self {
        return Self {
            task_list: [0; 100],
            len: 0,
        };
    }

    fn destroy() -> () {
        unimplemented!()
    }

    fn pop() -> () {
        unimplemented!()
    }
    fn push() -> () {
        unimplemented!()
    }
}

fn main() {}
