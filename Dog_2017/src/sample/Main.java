package sample;

import controller.NotesController;
import controller.TaskController;
import domain.ITask;
import domain.Task;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TableView;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
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
        FileRepository<ITask> repo = new FileRepository<>("tasks",myProcessor);
        TaskController controller = new TaskController(repo);
        GUIDesktopView myView = new GUIDesktopView(controller, new NotesController());
        Parent root = myView.getView();
        primaryStage.setTitle(">Dog2017");
        primaryStage.setScene(new Scene(root, 500, 500));
        primaryStage.show();
        primaryStage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            public void handle(WindowEvent we) {
                repo.updateFile();
            }
        });
    }


    public static void main(String[] args) throws IOException {
        launch(args);
    }
}
