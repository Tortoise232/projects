package aspects;

import domain.Observer;
import view.GUIDesktopView;

import java.util.ArrayList;
import java.util.List;

public aspect ObserverAspect {
    //cannot implement like this because it is unsuported by idea
    //declare parents: Contest implements Subject;
    //declare parents: GUIDesktopView implements Observer;

    private List<Observer> observers = new ArrayList<Observer>();;

    private void addObserver(Observer newObs){
        observers.add(newObs);
    }

    private void removeObserver(Observer obs){
        observers.remove(obs);
    }
    private void notifyObservers() {
        for(Observer o : observers)
        {
            if(o!= null) {
                o.update();
                System.out.println("Notified an observer!");
            }
        }
    }

    pointcut observed():(execution(* controller.NotesController.*Note(..)) || execution(* controller.TaskController.*Task(..)));

    after() returning: observed(){
        System.out.println("Notifying observers!");
        notifyObservers();
    }

    after(GUIDesktopView handler): initialization(view.GUIDesktopView.new(..))
            &&this(handler){
        System.out.println("Adding an observer!");
        addObserver(handler);

    }

    before(GUIDesktopView handler):execution(* GUIDesktopView.close())&& this(handler){
        removeObserver(handler);
    }


}
