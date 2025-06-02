pub mod Task;

pub struct TaskList {
    size: i8,
    list: [Task; 100]
}

impl TaskList {
    fn add(&self, task: Task) -> i8 {
        &self.list[size+1] = task;    
    }

    fn pop(&self, task_id: u32) -> i8 {
        
    }

}
