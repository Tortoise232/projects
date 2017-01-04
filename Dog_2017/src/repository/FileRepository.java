package repository;

import java.io.*;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

/**
 * Created by Petean Mihai on 1/3/2017.
 */
public class FileRepository<T> implements IRepository<T> {
    protected String fileName;
    //after this many operations update the contents of the file with the current in-memory data
    protected int maxUnsavedOperations = 3;
    protected int currentNo = 0;
    protected List<T> temporaryHold; //why? because of ease, I guess.

    public FileRepository(String fileName) throws IOException {
        BufferedReader dataLoader = null;
        try {
            dataLoader = new BufferedReader(new FileReader(fileName));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        String object = dataLoader.readLine();
        while(object != null) {
            object = dataLoader.readLine();
            T newObj = null;
            newObj.equals(object);
            temporaryHold.add(newObj);
        }
    }

    public FileRepository(String fileName, int maxOperations){
        this.fileName = fileName;
        this.maxUnsavedOperations = maxOperations;
    }

    public FileRepository(){
        String filename = "undefinedRepo" + Calendar.HOUR_OF_DAY + ":" + Calendar.MINUTE;
        this.temporaryHold = new ArrayList<T>();
        this.maxUnsavedOperations = 3;
    }

    @Override
    public void addObject(T object) {
        temporaryHold.add(object);
        if(++currentNo >= maxUnsavedOperations)
            updateFile();
    }

    @Override
    public void removeObject(T object) {
        temporaryHold.remove(object);
        if(++currentNo >= maxUnsavedOperations)
            updateFile();
    }

    @Override
    public List<T> getData() {
        return temporaryHold;
    }

    @Override
    public void setData(List<T> data) {
        this.temporaryHold = data;
        updateFile();
    }

    public void updateFile(){
        try {
            BufferedWriter dataLoader = new BufferedWriter(new FileWriter(fileName));
            temporaryHold.forEach(object ->{
                try {
                    dataLoader.write(object.toString());
                    dataLoader.newLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}