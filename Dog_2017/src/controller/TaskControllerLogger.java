package controller;

import java.io.*;

/**
 * Created by Petean Mihai on 2/5/2017.
 */
public class TaskControllerLogger {
    BufferedWriter logFile;

    public TaskControllerLogger()
    {
        try {
            logFile = new BufferedWriter(new FileWriter("defLogger.txt",true));
        } catch (IOException e) {
            e.printStackTrace();
        }
    };

    public TaskControllerLogger(String name){
        try {
            logFile = new BufferedWriter(new FileWriter(name));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public TaskControllerLogger(BufferedWriter writer){
        logFile = writer;
    }

    public void Log(String action) throws IOException {
        logFile.write(action  + "\n");
        logFile.flush();
    }
}
