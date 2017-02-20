package domain;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by Petean Mihai on 2/17/2017.
 */
public class Note {
    protected String text;
    protected Date date;
    protected Date until;

    public void setText(String text) {
        this.text = text;
    }


    public void setDate(Date date) {
        this.date = date;
    }

    public String getUntil() {
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd");
        return dateFormat.format(until);
    }

    public void setUntil(Date until) {
        this.until = until;
    }

    public String getText(){
        return text;
    }

    static public String getDate(){
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd");
        Date date = new Date();
        return dateFormat.format(date);
    }


    public Note(Date from, Date until, String text){
        this.text = text;
        this.date = from;

        this.until = until;
    }

    public Note(String from, String until, String text) throws ParseException {
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd");
        this.text = text;
        this.date = dateFormat.parse(from);
        this.until = dateFormat.parse(until);
    }

    public Note(String text, String until) throws ParseException {
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd");
        this.date = dateFormat.parse(Note.getDate());
        this.text = text;
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd");
        this.until = sdf.parse(until);
        System.out.println(this.until);
    }

    @Override
    public String toString(){
        return getDate() + " " + getUntil() + " " + text;
    }

}
