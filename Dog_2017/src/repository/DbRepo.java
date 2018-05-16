package repository;

import com.mysql.cj.x.protobuf.MysqlxDatatypes;
import domain.Note;

import javax.activation.DataSource;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.sql.*;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;

public class DbRepo implements IRepository<Note> {
    private Connection con;
    public DbRepo(){
        String url = "jdbc:mysql://localhost:3306/dogdatabase";
        String username = "root";
        String password = "";
        try {
            Class.forName("com.mysql.jdbc.Driver");
        }
        catch (Exception e){
            e.printStackTrace();
        }
        System.out.println("Connecting database...");
        try {
            con = DriverManager.getConnection(url, username, password);
            System.out.println("Database connected!");
        } catch (SQLException e) {
            throw new IllegalStateException("Cannot connect the database!", e);
        }
    }
    @Override
    public void addObject(Note object) {
        try {
            Statement stmt = con.createStatement();
            stmt.execute("INSERT INTO note (text, date, until) VALUES('" + object.getText() + "',' " +  Note.getDate() + "','" + object.getUntil() + "');");
            stmt.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }

    @Override
    public Note removeObject(Note object) {
        try {
            Statement stmt = con.createStatement();
            stmt.execute("DELETE FROM note WHERE text='" + object.getText()  + "';");
            stmt.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public List<Note> getData() {
        List<Note> result = null;
        try {
            result = new ArrayList<Note>();
            Statement stmt = con.createStatement();
            ResultSet res = stmt.executeQuery("SELECT * FROM note");
            while(res.next()){
                try {
                    result.add(new Note(res.getString("date"), res.getString("until"), res.getString("text")));
                } catch (ParseException e) {
                    e.printStackTrace();
                    return null;
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
        return result;
    }

    @Override
    public void setData(List<Note> data) {

    }

    @Override
    public int getSize() {
        return 0;
    }
}
