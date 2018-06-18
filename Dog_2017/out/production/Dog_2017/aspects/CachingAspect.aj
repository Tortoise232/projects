package aspects;

import domain.ITask;
import domain.Note;
import domain.Task;

import java.util.HashMap;

public aspect CachingAspect {
    public HashMap<String, Note> notesCache = new HashMap<String, Note>();
    public HashMap<Integer, ITask> taskCache = new HashMap<Integer, ITask>();

    pointcut findNotePointcut(String key): (execution(* controller.NotesController.findNote(String)) && args(key));
    pointcut findTaskPointcut(int key): (execution(* controller.TaskController.findTask(int)) && args(key));

    pointcut removeNotePointCut(): (execution(* controller.NotesController.removeNote(..)));

    Note around(String key): findNotePointcut(key){
        Note ret = null;
        if(notesCache.containsKey(key)) {
            ret = notesCache.get(key);

        }
        else{
            ret = proceed(key);
            notesCache.put(key, ret);
            System.out.println("Added an item to cache!");
        }
        return ret;
    }

    ITask around(int key): findTaskPointcut(key){
        ITask ret = null;
        if(taskCache.containsKey(key)) {
            ret = taskCache.get(key);
            System.out.println("Found item in cache!");
        }
        else{
            ret = proceed(key);
            taskCache.put(key, ret);
            System.out.println("Added an item to cache!");
        }
        return ret;
    }
}
