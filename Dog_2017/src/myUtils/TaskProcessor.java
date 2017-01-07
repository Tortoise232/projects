package myUtils;

import domain.ITask;
import domain.Task;

/**
 * Created by Petean Mihai on 1/7/2017.
 */
public class TaskProcessor implements IStringProcessor<ITask> {

    @Override
    public ITask processString(String toProcess) {
        String[] cutString = toProcess.split("\\| ");
        ITask newTask = new Task();
        newTask.setID(Integer.parseInt(cutString[0].replaceAll("[^0-9]","")));
        newTask.setText(cutString[1].split(" ")[0]);
        newTask.setDuration(Float.parseFloat(cutString[2].replaceAll("[a-z]","")));
        return newTask;
    }

    @Override
    public int processID(String toProcess) {
        String[] cutString = toProcess.split("\\| ");
        return Integer.parseInt(cutString[0].replaceAll("[^0-9]",""));
    }


}
