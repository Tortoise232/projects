package sample;

import controller.TaskController;
import domain.ITask;
import domain.Task;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TableView;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import myUtils.IStringProcessor;
import myUtils.TaskProcessor;
import repository.FileRepository;
import repository.IRepository;
import view.ConsoleDesktopView;
import view.GUIDesktopView;

import java.io.IOException;

public class Main extends Application{

    @Override
    public void start(Stage primaryStage) throws Exception{
        IStringProcessor<ITask> myProcessor = new TaskProcessor();
        IRepository<ITask> repo = new FileRepository<ITask>("tasks",myProcessor);
        TaskController controller = new TaskController(repo);
        GUIDesktopView myView = new GUIDesktopView(controller);
        Parent root = myView.getView();
        primaryStage.setTitle(">TaskHandler");
        primaryStage.setScene(new Scene(root, 350, 275));
        primaryStage.show();
    }


    public static void main(String[] args) throws IOException {
        launch(args);
    }
}
