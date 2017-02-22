'''
Created on 4 Feb 2016

@author: Mihai
'''
from domain.Subject import Subject
from websiteControl.websiteControl import websiteControl
import os

class UI(object):
    '''
    User Interface, meant to interact and receive input / provide output 
    '''


    def __init__(self, controller, taskUi):
        '''
        Constructor
        '''
        self._controller = controller
        self._webController = websiteControl()
        self._taskUI = taskUi
        
    def addTask(self):
        print("Give task Date: YYYY-MM-DD")
        newDate = input()
        newDate = newDate.split("-")
        
    def showOpt(self):
        '''
        shows the options within the application
        '''
        print("1.Add a new subject")
        print("2.Remove a subject")
        print("3.Print all subjects")
        print("4.Add hours to a subject")
        print("5.Change subject name or amount of hours")
        print("6.Show worst subject (least hours invested)")
        print("7.Browse subject")
        print("8.Enter task submenu")
        print("x Quit application")
    
    def addSubject(self):
        '''
        adds a new subject by a given name and attributes it 0 hours
        '''
        print("Give subject name:")
        newName = input()
        newHours = 0
        newSubject = Subject(newHours,newName)
        self._controller.addSubject(newSubject)
        
    def removeSubject(self):
        '''
        removes a subject by asking for name and removing by said name
        '''
        print("Give subject name:")
        newName = input()
        self._controller.removeSubject(newName)
    
    def printAllSubjects(self):
        '''
        prints all the subjects in the list as strings (Name Nr_of_hours)
        '''
        self.cls()
        print("\n")
        subjectList = self._controller.getAll()
        for counter in subjectList:
            print (counter)
        print("\n")
            
    def addHours(self):
        '''
        adds a number of hours to a given subject
        '''
        print("Give subject name:")
        newName = input()
        print("Give number of hours invested:")
        try:
            newHours = int(input())
        except:
            return False
        if newHours <= 0:
            raise ValueError("Invalid number of hours!")
        self._controller.addHours(newName,newHours)
        
    def updateSubject(self):
        '''
        updates a subject , finding it by name (can update any of the 2 parameters, really inefficient)
        newName - name by witch the subject is found
        newNameSub - name for the change
        newHoursSUb - number of hours for the change
        '''
        print("Give subject name:")
        newName = input()
        print("1 Change name")
        print("2 Change hours")
        print("3 Change both")
        newNameSub = None
        newHoursSub = None
        opt = input()
        if opt == '1':
            print("Give subject name:")
            newNameSub = input()
        if opt == '2':
            print("Give subject hours:")
            newHoursSub = int(input())
        if opt == '3':
            print("Give subject name:")
            newNameSub = input()
            print("Give subject hours:")
            newHoursSub = int(input())
        
        newObject = Subject(newHoursSub,newNameSub)
        self._controller.updateSubject(newName,newObject)
        print("Change successful!")
    
    def filterWorst(self):
        '''
        prints the worst of the subjects (by hours invested)
        '''
        self.cls()
        print("Least amount of time invested in:\n")
        print(str(self._controller.filterLowest()))
        print("\n")
    
    def filterWorstAll(self):
        '''
        DOES NOT WORK AS OF NOW
        prints all the subjects in ascending hour order
        '''
        self.cls()
        print(str(self._controller._repo.filterLowestAll()))
        print("\n")
        
    def web(self):
        self.printAllWebsites()
        print("What would like to acces:\n");
        option = input()
        self._webController.accesWebsite(str(option))
    
    def printAllWebsites(self):    
        tempList = self._webController.getAll()
        for counter in tempList:
            print(counter) 
            
    def cls(self):
        os.system('cls')
        
    def mainLoop(self):
        while True:
            try:
                self.showOpt()
                option = input()
                if option == '1':
                    self.addSubject()
                elif option == '2':
                    self.removeSubject()
                elif option == '3':
                    self.printAllSubjects()
                elif option == '4':
                    self.addHours()
                elif option == '5':
                    self.updateSubject()
                elif option == '6':
                    self.filterWorst()
                elif option == '7':
                    self.web();
                elif option == '8':
                    self._taskUI.mainLoop()
                elif option == 'x':
                    self._controller._repo.saveFile()
                    self._webController.saveToFile()
                    break
                if option != '6' and option != '3':
                    self.cls()
            except ValueError as error:
                print(error)

