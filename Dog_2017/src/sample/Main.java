package sample;

import controller.TaskController;
import domain.ITask;
import domain.Task;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import myUtils.IStringProcessor;
import myUtils.TaskProcessor;
import repository.FileRepository;
import repository.IRepository;
import repository.InMemoryRepository;
import view.DesktopView;

import java.io.IOException;

public class Main{
    /*
    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = new Group();
        Image newImage = new Image("Dog2017.jpg");
        ImageView iv1 = new ImageView();
        iv1.setImage(newImage);

        primaryStage.setTitle("Hello World");
        primaryStage.setScene(new Scene(root, 300, 275));
        primaryStage.show();
    }
    */

    public static void main(String[] args) throws IOException {
        //launch(args);
        IStringProcessor<ITask> myProcessor = new TaskProcessor();
        IRepository<ITask> repo = new FileRepository<ITask>("tasks",myProcessor);
        TaskController controller = new TaskController(repo);
        DesktopView newView = new DesktopView(controller);
        newView.mainLoop();
    }
}
