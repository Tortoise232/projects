package aspects;

import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public aspect PerformanceAspect {
    private Logger logger= Logger.getLogger("PerformanceAspect");

    public PerformanceAspect(){
        try {
            logger.setUseParentHandlers(false);
            FileHandler fh;
            String filePath = "E:\\Github\\projects\\Dog_2017\\aspectPerformanceLogFile.txt";
            fh = new FileHandler(filePath);
            logger.addHandler(fh);
            SimpleFormatter formatter = new SimpleFormatter();
            fh.setFormatter(formatter);
            System.out.println("Succesfully setup performance logger inside: " + filePath);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    pointcut controllerTasks(): execution(* controller..*(..));
    pointcut domainTasks(): execution(* domain..*(..));
    pointcut repoTasks(): execution(* repository..*(..));
    pointcut toMonitor(): controllerTasks() || domainTasks() || repoTasks();

    Object around(): toMonitor(){
        long start = System.nanoTime();
        try {
            return proceed();
        } finally {
            long time  = System.nanoTime() - start;
            logger.log(Level.INFO,	thisJoinPointStaticPart.getSignature().toShortString() + " completed in " + time);
        }
    }
}
