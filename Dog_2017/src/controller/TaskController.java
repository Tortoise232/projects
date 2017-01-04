package controller;

import domain.ITask;
import domain.Task;
import repository.IRepository;
import repository.InMemoryRepository;

import java.util.stream.Collector;

/**
 * Created by Petean Mihai on 1/4/2017.
 */
public class TaskController {
    IRepository<ITask> repo;

    public TaskController(IRepository<ITask> givenRepo){
        this.repo = givenRepo;
    }

    public void addTask(ITask newTask){
        repo.addObject(newTask);
    }

    public void removeTask(int id) throws Exception {
        repo.removeObject(this.findTask(id));
    }

    public void removeTask(ITask task){
        repo.removeObject(task);
    }

    public ITask findTask(int id) throws Exception {
        final ITask[] result = new ITask[1];
        repo.getData().stream().filter(task-> task.getID() == id).forEach(task-> result[0] = task);
        if(result.length == 1)
            return result[0];
        else
            throw new Exception("Task was found multiple times;");
    }

    public void modifyTask(int id, String newText,int newDuration) throws Exception {
        ITask task = this.findTask(id);
        task.setDuration(newDuration);
        task.setText(newText);
    }

    public void modifyTask(ITask modifiedTask) throws Exception {
        ITask task = this.findTask(modifiedTask.getID());
        task = modifiedTask;
    }
}
