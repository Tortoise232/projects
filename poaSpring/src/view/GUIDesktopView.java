package view;

import controller.NotesController;
import controller.TaskController;
import domain.Note;
import domain.Task;
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


/**
 * Created by Petean Mihai on 1/8/2017.
 */
public class GUIDesktopView  {
    TaskController taskController;
    NotesController notesController;



    //task controller related
    GridPane mainView = new GridPane();
    TableView<Task> taskTable;
    TableColumn idColumn = new TableColumn("ID");
    TableColumn descColumn = new TableColumn("DESCRIPTION");
    TableColumn durationColumn = new TableColumn("DURATION");
    Button taskAddButton = new Button("ADD");
    Button taskRemoveButton = new Button("REMOVE");
    Button taskModifyButton = new Button("MODIFY");
    Button logHours = new Button("LOG HOURS");

    //note controller related
    GridPane noteMainView = new GridPane();
    TableView<Note> noteTable;
    TableColumn startDate = new TableColumn("DATE");
    TableColumn text = new TableColumn("TEXT");
    TableColumn deadline = new TableColumn("UNTIL");
    Button noteAddButton = new Button("ADD");
    Button noteRemoveButton = new Button("REMOVE");


    public void update(){
        taskTable.setItems(taskController.getDataForView());
        noteTable.setItems(notesController.getDataForView());
    }


    public void initNoteTableView(){
        startDate.setCellValueFactory( new PropertyValueFactory<Note,String>("date"));
        text.setCellValueFactory(new PropertyValueFactory<Note,String>("text"));
        deadline.setCellValueFactory(new PropertyValueFactory<Note,String>("until"));
        noteTable = new TableView<>();
       // noteTable.setColumnResizePolicy(CONSTRAINED_RESIZE_POLICY);
        noteTable.getColumns().clear();
        noteTable.getColumns().addAll(startDate,text,deadline);
        noteTable.setItems(this.notesController.getDataForView());
    }

    public void noteAddHandler() {
        GridPane addView = new GridPane();
        Stage addStage = new Stage();
        addStage.setScene(new Scene(addView, 300, 100));
        addStage.setTitle(">Add note");
        //row; description stuff
        Label description = new Label("Text:");
        TextField textField1 = new TextField();
        HBox hb1 = new HBox();
        hb1.getChildren().addAll(description, textField1);
        hb1.setSpacing(10);

        //row; until stuff
        Label duration = new Label("YYYY/MM/DD");
        TextField textField2 = new TextField();
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

        submit.setOnAction(e -> {
            try {
                notesController.addNote(new Note(textField1.getText(), textField2.getText()));
            } catch (Exception e1) {
                e1.printStackTrace();
                addStage.close();
            }

            addStage.close();
        });
    }

    public void noteRemoveButtonHandler(){
        ObservableList<Note> selectedTasks = this.noteTable.getSelectionModel().getSelectedItems();
        System.out.println(selectedTasks);
        selectedTasks.forEach(note -> {
            try {
                this.notesController.removeNote(note);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

    }

    public void initTaskTableView(){
        idColumn.setCellValueFactory( new PropertyValueFactory<Task,String>("ID"));
        descColumn.setCellValueFactory(new PropertyValueFactory<Task,String>("text"));
        durationColumn.setCellValueFactory(new PropertyValueFactory<Task,String>("duration"));
        taskTable = new TableView<>();
        taskTable.getColumns().clear();
        taskTable.getColumns().addAll(idColumn,descColumn,durationColumn);
        taskTable.setItems(this.taskController.getDataForView());

    }

    public void removeButtonHandler(){
        ObservableList<Task> selectedTasks = this.taskTable.getSelectionModel().getSelectedItems();
        System.out.println(selectedTasks);
        selectedTasks.forEach(task -> {
            try {
                this.taskController.removeTask(task.getID());
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
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
                    taskController.addTask(new Task(textField1.getText(), Float.parseFloat((String) textField2.getText())));
                } catch (Exception e1) {
                    e1.printStackTrace();
                    addStage.close();
                }

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
                    taskController.modifyTask(id,textField1.getText(),Float.parseFloat(textField2.getText()));
                } catch (Exception e1) {
                    e1.printStackTrace();
                    modifyStage.close();
                }
                taskTable.setItems(taskController.getDataForView());
                modifyStage.close();
            }
        });
    }

    public void logHoursHandler() {
        GridPane logHoursView = new GridPane();
        Stage logHoursStage = new Stage();
        logHoursStage.setScene(new Scene(logHoursView, 300, 100));
        logHoursStage.setTitle(">Log hours");
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
                    String description = taskTable.getSelectionModel().getSelectedItem().getText();
                    int id = taskTable.getSelectionModel().getSelectedItem().getID();
                    float duration = taskTable.getSelectionModel().getSelectedItem().getDuration() - Float.parseFloat(textField1.getText());
                    if(duration > 0)
                        taskController.modifyTask(id,description,duration);
                    else {
                        taskController.removeTask(id);
                    }
                } catch (Exception e1) {
                    e1.printStackTrace();
                    logHoursStage.close();
                }
                taskTable.setItems(taskController.getDataForView());
               logHoursStage.close();
            }
        });
    }

    public void initButtons() {
        taskAddButton.setOnAction(e -> addButtonHandler());
        taskRemoveButton.setOnAction(e -> removeButtonHandler());
        taskModifyButton.setOnAction(e -> modifyButtonHandler());
        logHours.setOnAction(e -> logHoursHandler());

        noteAddButton.setOnAction(e -> noteAddHandler());
        noteRemoveButton.setOnAction(e -> noteRemoveButtonHandler());

    }




    public GUIDesktopView(TaskController taskCtrl, NotesController noteCtrl){
        this.taskController = taskCtrl;
        this.notesController = noteCtrl;
        initTaskTableView();
        initNoteTableView();
        initButtons();

        this.mainView.addRow(0,new Label("Tasks table: "));
        this.mainView.add(taskTable,0,0,4,4);
        this.mainView.addRow(6, taskAddButton, taskRemoveButton, taskModifyButton,logHours);
       // this.noteMainView.addRow(0,new Label("Notes table: "));
        this.noteMainView.add(noteTable,0,0,4,4);
        this.noteMainView.addRow(6,noteAddButton,noteRemoveButton);
        this.mainView.addColumn(5,noteMainView);

    }
    public GridPane getView(){
        return this.mainView;
    }
}
