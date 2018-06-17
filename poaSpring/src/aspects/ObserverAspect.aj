package aspects;

import view.GUIDesktopView;

public aspect ObserverAspect {
    pointcut observed(GUIDesktopView view):(execution(* *.GUIDesktopView.note*(..)))  && this(view);
    after(GUIDesktopView view) returning: observed(view){
        System.out.println("Notifying observers!");
        view.update();
    }

}
