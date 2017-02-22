package controller;

import domain.ITask;
import domain.Task;
import javafx.collections.FXCollections;
import javafx.collections.ObservableArray;
import javafx.collections.ObservableList;
import repository.FileRepository;
import repository.IRepository;
import repository.InMemoryRepository;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.stream.Collector;

/**
 * Created by Petean Mihai on 1/4/2017.
 */
public class TaskController {
    IRepository<ITask> repo;
    TaskControllerLogger logger;
    public TaskController(IRepository<ITask> givenRepo){
        this.repo = givenRepo;
        this.logger = new TaskControllerLogger();
    }

    public String getDate(){
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        Date date = new Date();
        return dateFormat.format(date);
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
        logger.Log(getDate() + ": ADDED " + newTask.getText() + " WITH " + newTask.getDuration() + " HOURS");

    }

    public void removeTask(int id) throws Exception {
        ITask taskToRemove = repo.removeObject(this.findTask(id));
        logger.Log(getDate() + ": REMOVED " + taskToRemove.getText());
    }

    public void removeTask(ITask task) throws Exception{
        ITask taskToRemove = repo.removeObject(task);
        logger.Log(getDate() + ": REMOVED " + taskToRemove.getText());
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
        boolean loggedHours = false;

        ITask task = this.findTask(id);
        float oldDuration = task.getDuration();
        if(task.getText() == newText && newDuration < task.getDuration())
            loggedHours = true;
        task.setDuration(newDuration);
        task.setText(newText);
        if(loggedHours)
            logger.Log(getDate() + ": LOGGED " + (oldDuration - newDuration) + " HOURS ON TASK " + newText);
        else
            logger.Log(getDate() + ": MODIFIED " + task.getText() + " WITH " + task.getDuration() + " HOURS TO " + newText + " WITH " + newDuration + " HOURS");
    }

    public void modifyTask(ITask modifiedTask) throws Exception {
        ITask task = this.findTask(modifiedTask.getID());
        task = modifiedTask;
        logger.Log(getDate() + ": MODIFIED " + task.getText() + " WITH " + task.getDuration() + " HOURS TO " + modifiedTask.getText() + " WITH " + modifiedTask + " HOURS");
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
