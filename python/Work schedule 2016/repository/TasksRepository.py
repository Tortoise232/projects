'''
Created on 15 Mar 2016

@author: Mihai
'''
#import time
#from _datetime import date
#from _overlapped import NULL

class TasksRepository(object):
    '''
    repository that holds all the task classes
    '''


    def __init__(self):
        '''
        Constructor for the tasks repository
        '''
        self._data = []
        
    
    def addTask(self, newTask):
        '''
        adds a new task to the repository
        '''
        if(self.validateTask(newTask)):
            self._data.append(newTask)
            return True
        else:
            return False
        
    def removeTask(self, taskName):
        '''
        input: taskName - string to be checked with the data inside the repository
        
        '''
        for counter in range(0, len(self._data)):
            if self._data[counter].getName() == taskName:
                return self._data.pop(counter)
        return False
    
    def findByName(self, taskName):
        '''
        input: taskName - string to be found in the repository
        finds a task in the repository by name
        '''
        for counter in range(0, len(self._data)):
            if self._data[counter].getName() == taskName:
                return self._data[counter]
        return False
           
    def modify(self, taskName, updatedTask):
        '''
        replaces a task with the name taskName with another task object (updatedTask)
        '''
        if(self.validateTask(updatedTask)!= True):
            return False
        for counter in range(0, len(self._data)):
            if self._data[counter].getName() == taskName:
                self._data[counter]  = updatedTask            
                return True
            
    def save(self):
        '''
        Saves all the data from the task repository to the tasks.txt file
        '''
        file = open("tasks.txt", "r")
        for counter in self._data:
            file.write(str(counter))
        file.write("end")
        file.close()    
        
    def getAll(self):
        '''
        Returns all the data in the repository
        '''
        return self._data
    
    def validateTask(self,newTask):
        '''
        Validates that a task object is good to be added to the repository
        '''
        if newTask.getDate() == None or newTask.getName() == None or newTask.getName() == "" or newTask.getNr() < 0:
            return False
        if newTask in self._data:
            return False
        '''
        POINTLESS CODE FOR NOW: VERIFY IF DATE IS VALID & VERIFY IF IT IS PAST THIS POINT IN THE PRESENT
        #actualTime = time.strftime("%Y-%m-%d")
        #if actualTime > str(newTask.getDate()):
        # return False
        '''
        return True
        
    
                