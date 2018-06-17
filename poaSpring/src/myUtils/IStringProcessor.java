package myUtils;

import java.text.ParseException;

/**
 * Created by Petean Mihai on 1/7/2017.
 */
//this is created because i don't know generics well enough. a repository holding data of type a will have a type a processor attached
public interface IStringProcessor<T> {
       T processString(String toProcess) throws ParseException;
}
