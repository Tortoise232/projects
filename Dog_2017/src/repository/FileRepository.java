package repository;

import myUtils.IStringProcessor;

import java.io.*;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Petean Mihai on 1/3/2017.
 */
public class FileRepository<T> implements IRepository<T> {
    protected String fileName;
    //after this many operations update the contents of the file with the current in-memory data
    protected int maxUnsavedOperations = 3;
    protected int currentNo = 0;
    protected List<T> temporaryHold; //why? because of ease, I guess.
    protected IStringProcessor<T> stringProcessor;
    public FileRepository(String fileName,IStringProcessor<T> processor ) throws IOException {
        this.temporaryHold = new ArrayList<T>();
        this.fileName = fileName;
        this.stringProcessor = processor;
        BufferedReader dataLoader = null;
        try {
            dataLoader = new BufferedReader(new FileReader(fileName + ".txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        String object = dataLoader.readLine();
        while(object != null) {
            T computedObject = this.stringProcessor.processString(object);
            this.addObject(computedObject);
            object = dataLoader.readLine();
        }
    }

    public FileRepository(String fileName, int maxOperations, IStringProcessor<T> processor){
        this.fileName = fileName;
        this.temporaryHold = new ArrayList<T>(20);
        this.maxUnsavedOperations = maxOperations;
        this.stringProcessor = processor;
    }

    public FileRepository(){
        this.fileName = "undefinedRepo" + Calendar.HOUR_OF_DAY + "_" + Calendar.MINUTE;
        this.temporaryHold = new ArrayList<T>(20);
        this.maxUnsavedOperations = 3;
    }

    @Override
    public void addObject(T object) {
        this.temporaryHold.add(object);
        if(++currentNo >= maxUnsavedOperations) {
            updateFile();
            currentNo = 0;
        }
    }

    @Override
    public void removeObject(T object) {
        temporaryHold.remove(object);
        if(++currentNo >= maxUnsavedOperations) {
            updateFile();
            currentNo = 0;
        }
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

    @Override
    public int getSize() {
        return this.temporaryHold.size();
    }

    public void updateFile(){

        try {
            BufferedWriter bufferedWriter= new BufferedWriter(new FileWriter(this.fileName + ".txt") );
            PrintWriter dataLoader = new PrintWriter(bufferedWriter);
            temporaryHold.forEach(object ->{
                    dataLoader.write(object.toString() + "\n");
            });
            dataLoader.close();
            System.out.println("Changes were saved!");
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
    //this does not work for reasons I haven't yet investigated
    @Override
    protected void finalize(){
        System.out.println("Do you want to save your changes? (y/n)");
        Scanner scanner = new Scanner(System.in);
        String option = scanner.nextLine();
        if(option.startsWith("y"))
        {
            this.updateFile();
        }
    }
}