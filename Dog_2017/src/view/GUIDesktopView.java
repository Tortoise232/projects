package view;

import controller.TaskController;
import domain.Task;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import javafx.util.converter.NumberStringConverter;

import java.util.Collection;

/**
 * Created by Petean Mihai on 1/8/2017.
 */
public class GUIDesktopView  {
    TaskController controller;
    String descriptionField;
    float durationField;
    int IDField;
    GridPane mainView = new GridPane();
    TableView<Task> taskTable;
    TableColumn idColumn = new TableColumn("ID");
    TableColumn descColumn = new TableColumn("DESCRIPTION");
    TableColumn durationColumn = new TableColumn("DURATION");

    Button addButton = new Button("ADD");
    Button removeButton = new Button("REMOVE");
    Button modifyButton  = new Button("MODIFY");
    Button logHours = new Button("LOG HOURS");

    public void initTableView(){
        idColumn.setCellValueFactory( new PropertyValueFactory<Task,String>("ID"));
        descColumn.setCellValueFactory(new PropertyValueFactory<Task,String>("text"));
        durationColumn.setCellValueFactory(new PropertyValueFactory<Task,String>("duration"));
        taskTable = new TableView<>();
        taskTable.getColumns().clear();
        taskTable.getColumns().addAll(idColumn,descColumn,durationColumn);
        taskTable.setItems(this.controller.getDataForView());

    }

    public void removeButtonHandler(){
        ObservableList<Task> selectedTasks = this.taskTable.getSelectionModel().getSelectedItems();
        System.out.println(selectedTasks);
        selectedTasks.forEach(task -> {
            try {
                this.controller.removeTask(task.getID());
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
        taskTable.setItems(this.controller.getDataForView());
    }

    public void addButtonHandler() {
        GridPane addView = new GridPane();
        Stage addStage = new Stage();
        addStage.setScene(new Scene(addView, 300, 100));
        addStage.setTitle(">Add task");
        //row; description stuff
        Label description = new Label("Description:");
        TextField textField1 = new TextField();
        HBox hb1 = new HBox();
        hb1.getChildren().addAll(description, textField1);
        hb1.setSpacing(10);

        //row; duration stuf
        Label duration = new Label("Duration:");
        TextField textField2 = new TextField();
        textField2.setTextFormatter(new TextFormatter<>(new NumberStringConverter()));
        HBox hb2 = new HBox();
        hb2.getChildren().addAll(duration, textField2);
        hb2.setSpacing(10);

        Button submit = new Button("SUBMIT");
        HBox hb3 = new HBox();
        hb3.getChildren().add(submit);
        hb3.setAlignment(Pos.CENTER);


        addView.addRow(0, hb1);
        addView.addRow(1, hb2);
        addView.addRow(2, submit);
        addView.setAlignment(Pos.CENTER);
        addStage.show();

        submit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                try {
                    controller.addTask(new Task(textField1.getText(), Float.parseFloat((String) textField2.getText())));
                } catch (Exception e1) {
                    e1.printStackTrace();
                    addStage.close();
                }
                taskTable.setItems(controller.getDataForView());
                addStage.close();
            }
        });
    }

    public void modifyButtonHandler(){

        GridPane modifyView = new GridPane();
        Stage modifyStage = new Stage();
        modifyStage.setScene(new Scene(modifyView, 300, 100));
        modifyStage.setTitle(">Modify task");
        //row; description stuff
        Label description = new Label("Description:");
        TextField textField1 = new TextField();
        HBox hb1 = new HBox();
        hb1.getChildren().addAll(description, textField1);
        hb1.setSpacing(10);

        //row; duration stuf
        Label duration = new Label("Duration:");
        TextField textField2 = new TextField();
        textField2.setTextFormatter(new TextFormatter<>(new NumberStringConverter()));
        HBox hb2 = new HBox();
        hb2.getChildren().addAll(duration, textField2);
        hb2.setSpacing(10);

        Button submit = new Button("SUBMIT");
        HBox hb3 = new HBox();
        hb3.getChildren().add(submit);
        hb3.setAlignment(Pos.CENTER);


        modifyView.addRow(0, hb1);
        modifyView.addRow(1, hb2);
        modifyView.addRow(2, submit);
        modifyView.setAlignment(Pos.CENTER);
        modifyStage.show();

        submit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                try {
                    int id = taskTable.getSelectionModel().getSelectedItem().getID();
                    controller.modifyTask(id,textField1.getText(),Float.parseFloat(textField2.getText()));
                } catch (Exception e1) {
                    e1.printStackTrace();
                    modifyStage.close();
                }
                taskTable.setItems(controller.getDataForView());
                modifyStage.close();
            }
        });
    }

    public void logHoursHandler() {
        GridPane logHoursView = new GridPane();
        Stage logHoursStage = new Stage();
        logHoursStage.setScene(new Scene(logHoursView, 300, 100));
        logHoursStage.setTitle(">Modify task");
        //row; description stuff
        Label description = new Label("Duration:");
        TextField textField1 = new TextField();
        textField1.setTextFormatter(new TextFormatter<>(new NumberStringConverter()));
        HBox hb1 = new HBox();
        hb1.getChildren().addAll(description, textField1);
        hb1.setSpacing(10);
        Button submit = new Button("SUBMIT");
        logHoursView.addRow(0,hb1);
        logHoursView.addRow(1,submit);
        logHoursStage.show();
        submit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                try {
                    int id = taskTable.getSelectionModel().getSelectedItem().getID();
                    float duration = taskTable.getSelectionModel().getSelectedItem().getDuration() - Float.parseFloat(textField1.getText());
                    if(duration > 0)
                        controller.modifyTask(id,textField1.getText(),duration);
                    else {
                        controller.removeTask(id);
                    }
                } catch (Exception e1) {
                    e1.printStackTrace();
                    logHoursStage.close();
                }
                taskTable.setItems(controller.getDataForView());
               logHoursStage.close();
            }
        });
    }

    public void initButtons() {
        addButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent e) {
                addButtonHandler();
            }
        });
        removeButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent e) {
                removeButtonHandler();
            }
        });
        modifyButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent e) {
                modifyButtonHandler();
            }
        });
        logHours.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent e) {
                logHoursHandler();
            }
        });

    }




    public GUIDesktopView(TaskController ctrl){
        this.controller = ctrl;
        initTableView();
        initButtons();
        this.mainView.add(taskTable,0,0,4,4);
        this.mainView.addRow(5,addButton,removeButton,modifyButton,logHours);
        this.mainView.autosize();

    }
    public GridPane getView(){
        return this.mainView;
    }
}
