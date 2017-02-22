'''
Created on 4 Feb 2016

@author: Mihai
'''
from domain.Subject import Subject
from copy import deepcopy

class Repository(object):
    '''
    Repository class to hold all the subject objects
    '''
    

    def __init__(self):
        '''
        Constructor 
        '''
        self._data = []
        self.loadFile()
    
    def addSubject(self,subject):
        '''
        adds a new subject to the repository
        '''
        self._data.append(subject)
    
    def findSubject(self,subjectname):
        '''
        looks for a subject by name
        '''
        for counter in self._data:
            if counter.getName() == subjectname:
                return counter
            
    def removeSubject(self,subjectName):
        '''
        removes a given subject, by finding the object within the repository
        ONLY REMOVES THE FIRST ONE FOUND!!!
        '''    
        for counter in range (0,len(self._data)):
            if self._data[counter].getName() == subjectName:
                return self._data.pop(counter) 
                
    def updateSubject(self,name,newobject):
        '''
        updates the hours and or name of a subject by a given name
        only updates the first one
        '''
        
        for counter in self._data:
            if counter.getName() == name:
                if newobject.getName() == None:
                    counter.setHours( newobject.getHours() )
                if newobject.getHours() == None:
                    counter.setName( newobject.getName() )
                return newobject
    '''   
    DOES NOT FUNCTION AS OF NOW
    def filterLowestAll(self):
        newlist = deepcopy(self._data)
        orderedList = []
        while len(newlist) > 0 :
            mini = newlist[0].getHours()
            miniPoz = 0
            for counter in range (0, len(newlist)):
                if newlist[counter].getHours() < mini :
                    mini = newlist[counter].getHours()
                    miniPoz = counter
            orderedList.append(newlist[counter])
            newlist.pop(counter)
        
        return orderedList
    '''
    def filterLowest(self):
        '''
        finds the subject with the lowest number of hours
        mini - local minimum
        minElem - smallest Subject (by hours)
        '''
        mini = self._data[0].getHours()
        minElem = self._data[0]
        newrepo = deepcopy(self._data)
        for counter in newrepo:
            if counter.getHours() < mini:
                mini = counter.getHours()
                minElem = counter
        return minElem
        
        
    def saveFile(self):
        '''
        saves the repository to a file!
        '''
        file = open("data.txt","w")
        for counter in self._data:
            file.write(str(counter) + "\n")
        file.write("end")
    
    def loadFile(self):
        '''
        loads the repository from a file!
        '''
        file = open("data.txt","r")
        newline = file.readline()
        while newline != "end":
            newline = newline.split(" ")
            newsubject = Subject(int(newline[1]),newline[0])
            self.addSubject(newsubject)
            newline = file.readline()
    
    def addHours(self,name,hours):
        '''
        adds hours to a given subject (found by name)
        '''
        for counter in range(0,len(self._data)):
            if self._data[counter].getName() == name:
                self._data[counter].addHours(hours)
    
    def getAll(self):
        '''
        appends all string of subjects to a list, returns said list LOLOLOLOLOL
        '''
        newList = []
        for counter in self._data:
            newList.append(str(counter))
        return newList
                      
            
#a = Repository()
#a.loadFile()
#for counter in a._data:
    #print (counter)                
                