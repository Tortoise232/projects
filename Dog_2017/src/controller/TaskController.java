package controller;

import domain.ITask;
import domain.Task;
import javafx.collections.FXCollections;
import javafx.collections.ObservableArray;
import javafx.collections.ObservableList;
import repository.IRepository;
import repository.InMemoryRepository;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collector;

/**
 * Created by Petean Mihai on 1/4/2017.
 */
public class TaskController {
    IRepository<ITask> repo;

    public TaskController(IRepository<ITask> givenRepo){
        this.repo = givenRepo;
    }

    public void addTask(ITask newTask) throws Exception {
        if(this.findTask(newTask.getID()) != null) {
            int[] maxID = {0};
            repo.getData().forEach((ITask task) ->{
             if(task.getID() > maxID[0])
                 maxID[0] = task.getID();
                    }
             );
            newTask.setID(maxID[0] + 1);
        }
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

    public void modifyTask(int id, String newText,float newDuration) throws Exception {
        ITask task = this.findTask(id);
        task.setDuration(newDuration);
        task.setText(newText);
    }

    public void modifyTask(ITask modifiedTask) throws Exception {
        ITask task = this.findTask(modifiedTask.getID());
        task = modifiedTask;
    }

    public List<ITask> getRepoTasks(){
        return this.repo.getData();
    }

    public ObservableList<Task> getDataForView(){

       ArrayList<Task> result = new ArrayList<Task>();
        this.repo.getData().forEach((ITask task)->{
            Task tempTask = new Task();
            tempTask.setID(task.getID());
            tempTask.setDuration(task.getDuration());
            tempTask.setText(task.getText());
            result.add(tempTask);
        });
        return FXCollections.observableArrayList(result);
    }
}
