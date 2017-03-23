package domain;

import java.util.ArrayList;

/**
 * Created by Petean Mihai on 3/13/2017.
 */
public class Subject {
    private ArrayList<String> thingsDone;
    private int numberOfHours;
    private String name;
    private int id;
    private static int globalID = 0;

    public Subject(String name, String firstHourDescription){
        numberOfHours = 1;
        thingsDone = new ArrayList<>();
        thingsDone.add(firstHourDescription);
        this.name = name;
        this.id = getGlobalID();
    }


    public Subject(String name){
        numberOfHours = 0;
        thingsDone = new ArrayList<>();
        this.name = name;
        this.id = getGlobalID();
    }

    public Subject(String name, ArrayList<String> someThings)
    {
        numberOfHours = someThings.size();
        this.name = name;
        this.thingsDone = someThings;
        this.id = getGlobalID();
    }



    public ArrayList<String> getThingsDone() {
        return thingsDone;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public static int getGlobalID() {
        return globalID;
    }

    public static void setGlobalID(int globalID) {
        Subject.globalID = globalID;
    }

    public void setThingsDone(ArrayList<String> thingsDone) {
        this.thingsDone = thingsDone;
    }

    public int getNumberOfHours() {
        return numberOfHours;
    }

    public void setNumberOfHours(int numberOfHours) {
        this.numberOfHours = numberOfHours;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public static int getID(){
        return ++globalID;
    }
}