package domain;

/**
 * Created by Petean Mihai on 1/3/2017.
 */
public interface ITask {
    public float getDuration();
    public void setDuration(float Duration);
    public String getText();
    public void setText(String newText);
    public int generateID();
    public int getID();
}
