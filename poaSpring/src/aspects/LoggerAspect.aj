package aspects;

import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public aspect LoggerAspect {
    public Logger logger = Logger.getLogger("app");
    pointcut tracing():call(public * *.*(..))&& !(within(LoggerAspect) || call(* javafx..*.*(..)) || call(* java.text.DateFormat.*(..)));
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
