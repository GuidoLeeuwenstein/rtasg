use std::{time::SystemTime};

#[derive(Debug, Copy, Clone)]
enum TaskStatus {
    Pending,
    InProgress,
    Done,
    Stoppped,
}

#[derive(Debug, Copy, Clone)]
struct Task {
    id: u16,
    name: [u8; 256],
    discription: [u8; 256],
    status: TaskStatus,
    date_created: SystemTime,
    data_updated: SystemTime,
}

impl Task {
    fn new(id: u16, name: &str, discription: &str) -> Result<Task, &'static str> {
        let current_datetime = SystemTime::now();
        if name.len() > 256 {
           return Err("Name to long");
        }
        if discription.len() > 256 {
           return Err("Name to long");
        }

        let mut name_arr = [0;256];
        let mut descritpion_arr = [0;256];
        &name_arr.copy_from_slice(name.as_bytes());
        &descritpion_arr.copy_from_slice(name.as_bytes());

        return Ok(Task {
            id,
            name: name_arr,
            discription: descritpion_arr,
            status: TaskStatus::Pending,
            date_created: current_datetime,
            data_updated: current_datetime,
        })
    }

    fn update_status(&mut self, new_status: TaskStatus) {
        self.status = new_status
    }

    fn update_name(&mut self, name: &str) {
        self.name.copy_from_slice(name.as_bytes());
    }

    fn update_description(&mut self, discription: &str) {
        self.discription.copy_from_slice(discription.as_bytes());
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
            task_list: [{Task::new(id, name, discription)}; 100],
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
