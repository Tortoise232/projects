'''
Created on 4 Feb 2016

@author: Mihai
'''

class Subject(object):
    '''
    Subject to put hours into
    '''


    def __init__(self,nrofhours,name):
        '''
        Constructor 
        '''
        self._hours = nrofhours
        self._name = name
         
    def getName(self):
        '''
        returns the name of the given subject
        '''
        return self._name
    
    def setName(self,newname):
        '''
        updates the name of a given subject
        '''
        if newname != "":
            self._name = newname
        
    def getHours(self):
        '''
        returns the hours of the given subject
        '''    
        return self._hours
    
    def setHours(self,newhours):
        '''
        updates the hours of a given subject
        '''
        self._hours = newhours
    
    def addHours(self,nrofhours):
        '''
        adds hours to a given subject
        '''
        self._hours += nrofhours
    
        
    def __repr__ (self):
        '''
        returns a string representation of the subject
        '''
        return self._name + " " + str(self._hours)
    
    
    def __eq__(self,other):
        '''
        equality condition between two subject objects
        '''
        if self.getHours() == other.getHours() and self.getName() == other.getName():
            return True
        return False
    
    