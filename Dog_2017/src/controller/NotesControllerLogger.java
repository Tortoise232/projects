package controller;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Created by Petean Mihai on 3/8/2017.
 */
public class NotesControllerLogger {
    BufferedWriter logFile;
    public NotesControllerLogger()
    {
        try {
            logFile = new BufferedWriter(new FileWriter("defNotesLogger.txt",true));
        } catch (IOException e) {
            e.printStackTrace();
        }
    };

    public NotesControllerLogger(String name){
        try {
            logFile = new BufferedWriter(new FileWriter(name));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public NotesControllerLogger(BufferedWriter writer){
        logFile = writer;
    }

    public void Log(String action) throws IOException {
        logFile.write(action  + "\n");
        logFile.flush();
    }
}


