package myUtils;

import domain.Note;

import java.text.ParseException;
import java.util.Date;

/**
 * Created by Petean Mihai on 2/17/2017.
 */
public class NotesProcessor implements IStringProcessor<Note>{

    @Override
    public Note processString(String toProcess) throws ParseException {
        String[] cutString = toProcess.split(" ");
        return new Note(cutString[0], cutString[1], cutString[2]);
    }


}
