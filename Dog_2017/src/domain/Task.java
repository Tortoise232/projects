package domain;

/**
 * Created by Petean Mihai on 1/3/2017.
 */
public class Task implements ITask {
    protected String text;
    protected static int ID = 0;
    protected float duration;//
    public Task(String desc, int duration){
        this.text = desc;
        this.duration = duration;
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
        return ID++;
    }

    @Override
    public int getID(){
        return this.ID;
    }
}
