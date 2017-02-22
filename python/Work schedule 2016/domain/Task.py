'''
Created on 15 Mar 2016

@author: Mihai
'''
class Task(object):
    '''
    task object contains a deadline (datetime object), a number of hours to be put into it and a name
    '''


    def __init__(self,newDate,newName,newNr):
        '''
        Constructor
        '''
        self._date = newDate
        self._nr = newNr
        self._name = newName
        
    def getDate(self):
        return self._date
    
    def setDate(self,newDateObject):
        self._date = newDateObject
        
    def getDay(self):
        return self._date.day
    
    def setDay(self, newDay):
        self._date.day = newDay
        
    def getMonth(self):
        return self._date.month
    
    def setMonth(self, newMonth):
        self._data.month = newMonth
        
    def getYear(self):
        return self._date.year
    
    def setYear(self, newYear):
        self._date.year = newYear
        
    def getNr(self):
        return self._nr
    
    def setNr(self, newNr):
        self._nr = newNr
        
    def getName(self):
        return self._name
    
    def setName(self, newName):
        self._name = newName
        
    def __eq__(self,other):
        if self.getDate() == other.getDate() and self.getName() == other.getName() and self.getNr() == other.getNr():
            return True
        return False   
    
    def __str__(self):
        return self.getName() + " " + str(self.getNr()) + " " + str(self.getDate())
    