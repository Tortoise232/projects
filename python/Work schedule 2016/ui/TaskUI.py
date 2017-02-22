'''
Created on 19 Mar 2016

@author: Mihai
'''

class TaskUI(object):
    '''
    UI dealing with I/O of the Task Controller, to be called from the main ui
    '''


    def __init__(self, taskController):
        '''
        Constructor
        '''
        self._controller = taskController
    
    
    def showOpt(self):
        print("1.Print all tasks")
        print("2.Add a new task")
        print("3.Remove a task")
        print("4.Update a task")
        print("x.Exit task sub-menu")
        
    def printAll(self):
        tasks =  self._controller.getAll()
        for counter in tasks:
            print(str(counter))   
        
    def addTask(self):
        print("Give task name: ")
        taskName = input()
        print("Give task date in the format YYYY-MM-DD: ") 
        taskDate = input()
        print("Give number of hours required to complete task: ")
        taskNr = int(input())
        if self._controller.addTask(taskDate, taskName, taskNr):   
            print("Task successfully added!")
        else:
            print("Addition of task failed!")
            
    def removeTask(self):
        print("Give task name:")
        taskName = input()
        if self._controller.removeTask(taskName):
            print("Task successfully removed!")
        else:
            print("Removal failed!")
            
    def updateTask(self):
        print("Give task name: ")
        taskName = input()
        print("Give new date for task in the format YYYY-MM-DD: ")
        taskDate = input()
        print("Give new number of hours required to complete task: ")
        taskNr = int(input())
        if self._controller.updateTask(taskName, taskDate, taskNr):
            print("Task successfully updated!")
        else:
            print("Update failed!")
            
    def mainLoop(self):
        while True:
            try:
                self.showOpt()
                option = input()
                if option == '1':
                    self.printAll()
                if option == '2':
                    self.addTask()
                if option == '3':
                    self.removeTask()
                if option == '4':
                    self.updateTask()
                if option == 'x':
                    break
            except ValueError as e:
                print(e)
        