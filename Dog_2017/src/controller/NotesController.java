package controller;

import domain.Note;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import myUtils.NotesProcessor;
import repository.FileRepository;
import repository.IRepository;

import java.io.IOException;
import java.text.ParseException;
import java.util.ArrayList;

/**
 * Created by Petean Mihai on 2/17/2017.
 */
public class NotesController {
    IRepository<Note> repo;

    public NotesController(IRepository<Note> repo){
        this.repo = repo;
    }

    public NotesController(){
        try {
            this.repo = new FileRepository<>("notes",new NotesProcessor());
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public void addNote(Note myNote){
        repo.addObject(myNote);
    }

    public void removeNote(Note myNote){
        repo.removeObject(myNote);
    }

    public void removeNote(String text) throws Exception {
        repo.removeObject(findNote(text));
    }

    public Note findNote(String text) throws Exception {
        final Note[] result = new Note[1];
        repo.getData().stream().filter(note -> note.getText() == text).forEach(note -> result[0] = note);
        if(result.length == 1)
            return result[0];
        else
            throw new Exception("Note was found multiple times;");
    }

    public Note findNote(Note myNote) throws Exception {
        return findNote(myNote.getText());
    }

    public ObservableList<Note> getDataForView(){
        ArrayList<Note> result = new ArrayList<>();
        this.repo.getData().forEach((Note note)->{
            Note tempNote = null;
            try {
                tempNote = new Note(note.getDate(),note.getUntil(),note.getText());
            } catch (ParseException e) {
                e.printStackTrace();
            }
            result.add(tempNote);
        });
        return FXCollections.observableArrayList(result);
    }

}
