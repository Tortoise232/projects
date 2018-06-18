package aspects;

import java.io.IOException;
import java.util.List;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public aspect LoggerAspect {
    public Logger logger = Logger.getLogger("app");
    public LoggerAspect(){
        try {
            logger.setUseParentHandlers(false);
            FileHandler fh;
            String filePath = "E:\\Github\\projects\\Dog_2017\\aspectLogFile.txt";
            fh = new FileHandler(filePath);
            logger.addHandler(fh);
            SimpleFormatter formatter = new SimpleFormatter();
            fh.setFormatter(formatter);
            System.out.println("Succesfully setup logger inside: " + filePath);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    pointcut tracing():call(public * *.*(..))&& !(within(LoggerAspect) || call(* javafx..*.*(..)) || call(* java.text.DateFormat.*(..)) || within(view.GUIDesktopView));
    before(): tracing(){
        Object[] args = thisJoinPoint.getArgs();
        String argsToString = "";
        for(Object o : args){
            argsToString += o.toString();
            argsToString += " ";
        }
        logger.log(Level.INFO,"Before: " + thisJoinPointStaticPart.getSignature()  + " " + argsToString);
        //createParams(thisJoinPoint));
    }
    after():tracing(){
        logger.log(Level.INFO, "After: " + thisJoinPointStaticPart.getSignature());
    }
}
