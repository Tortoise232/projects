package domain;


import com.sun.deploy.util.StringUtils;

import java.util.Arrays;

/**
 * Created by Petean Mihai on 1/3/2017.
 */
public class Task implements ITask {
    protected String text;
    protected static int globalID = 0;
    protected int ID;
    protected float duration;//
    public Task(String desc, float duration){
        this.text = desc;
        this.duration = duration;
        this.ID = generateID();
    }

    public Task(){
        this.text = "undefined";
        this.duration = -1;
    }

    @Override
    public float getDuration() {
        return duration;
    }

    @Override
    public void setDuration(float duration) {
        this.duration = duration;
    }

    @Override
    public String getText() {
        return text;
    }

    @Override
    public void setText(String newText) {
        this.text = newText;
    }

    @Override
    public int generateID(){
       return globalID++;
    }

    @Override
    public int getID(){
        return this.ID;
    }

    @Override
    public void setID(int newID) {
        this.ID = newID;
    }

    @Override
    public String toString(){
        char[] array = new char[30 - this.text.length()];
        Arrays.fill(array, ' ');
        String result =  "(" + this.ID + ") | " + this.text + String.valueOf(array) + " | " + this.duration + "hr";
        if(this.duration != 1)
            result += "s";
        return result;
    }

}
