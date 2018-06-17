package view;

import controller.TaskController;
import domain.ITask;
import domain.Task;
import repository.FileRepository;

import java.util.Scanner;

/**
 * Created by Petean Mihai on 1/5/2017.
 */
public class ConsoleDesktopView {
    TaskController myController;

    public ConsoleDesktopView(TaskController controller){
        this.myController = controller;
    }

    public void addTask()  {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Give task description: ");
        String description = scanner.nextLine();
        System.out.println("Give task duration");
        float duration = scanner.nextFloat();
        ITask newTask = new Task(description,duration);
        try {
            this.myController.addTask(newTask);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void removeTask(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Give task ID");
        int id = scanner.nextInt();
        try {
            this.myController.removeTask(id);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void modifyTask(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Give task ID: ");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Give new description: ");
        String newDesc = scanner.nextLine();
        System.out.println("Give new duration: ");
        float newDuration = scanner.nextFloat();
        try {
            this.myController.modifyTask(id,newDesc,newDuration);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void showTasks(){
        this.myController.getRepoTasks().forEach(task-> System.out.println(task));
    }

    public void mainLoop(){
        Scanner scanner = new Scanner(System.in);
        String rawOption = "start";
        while(rawOption != "quit" ){
            System.out.print("Input command: ");
            rawOption = scanner.next();
            String option[] = rawOption.split(" ");
            switch(option[0]) {
                case "add":
                    this.addTask();
                    System.out.println("Add successful!");
                    break;
                case "remove":
                    this.removeTask();
                    System.out.println("Remove successful!");
                    break;
                case "modify":
                    this.modifyTask();
                    System.out.println("Modification successful!");
                    break;
                case "show":
                    System.out.println(" ID | DESCRIPTION                    | DURATION");
                    this.showTasks();
                    break;
                case "quit":
                    return;
                default:
                    break;
            }

        }
    }

}
