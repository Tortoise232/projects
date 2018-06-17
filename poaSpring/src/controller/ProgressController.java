package controller;

import domain.Subject;
import domain.Task;
import repository.IRepository;

/**
 * Created by Petean Mihai on 3/13/2017.
 */
public class ProgressController {
    private IRepository<Subject> repo;

    public IRepository<Subject> getRepo() {
        return repo;
    }

    public void setRepo(IRepository<Subject> repo) {
        this.repo = repo;
    }

    //Hour to subject because progress is measured in hours
    void addHourToSubject(String subjectName, String description) throws Exception {
        Subject subject = findSubject(subjectName);
        if(subject == null) {
            repo.addObject(new Subject(subjectName, description));
            return;
        }
        subject.getThingsDone().add(description);
        subject.setNumberOfHours(subject.getNumberOfHours() + 1);
    }

    Subject findSubject(String subjectName) throws Exception {
        final Subject[] result = new Subject[1];
        repo.getData().stream().filter(subject -> subject.getName() == subjectName).forEach(subject-> result[0] = subject);
        if(result.length == 1)
            return result[0];
        else
            throw new Exception("Subject was found multiple times;");
    }

    void removeSubject(String subjectName) throws Exception {
        repo.removeObject(findSubject(subjectName));
    }

    //warning: this removes the last n hours, not a given hour interval! thing about your mistakes, people.
    void removeHours(String subjectName, int numberOfHours) throws Exception {
        Subject subject = findSubject(subjectName);
        subject.getThingsDone().subList(0,subject.getThingsDone().size() - numberOfHours);
    }



}
