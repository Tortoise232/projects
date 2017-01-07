package myUtils;

/**
 * Created by Petean Mihai on 1/7/2017.
 */
public interface IStringProcessor<T> {
        public T processString(String toProcess);
        public int processID(String toProcess);
}
