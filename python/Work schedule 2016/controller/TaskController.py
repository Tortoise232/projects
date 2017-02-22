'''
Created on 16 Mar 2016

@author: Mihai
'''
from domain.Task import Task

class TaskController(object):
    '''
    Deals with operations in the TaskRepository (regarding tasks)
    '''


    def __init__(self, repository):
        '''
        Constructor
        '''
        self._repo = repository
        
    def addTask(self,newDate,newName,newNr):
        '''
        returns true if a new task object has been added to the repository, false otherwise
        '''
        newTask = Task(newDate,newName,newNr)
        if self._repo.addTask(newTask) :
            return True
        else:
            return False    
        
    def removeTask(self,taskName):
        '''
        removes a task from the repository, returns true if the task was deleted and false if it was not
        '''
        if(self._repo.removeTask(taskName)):
            return True
        else:
            return False
        
    def updateTask(self,taskName,newDate,newNr):
        '''
        updates a task from the repository
        '''
        newTask = Task(newDate, taskName, newNr)
        if self._repo.modify(taskName, newTask) == True :
            return True
        else:
            return False

    def getAll(self):
        return self._repo.getAll()