'''
Created on 4 Feb 2016

@author: Mihai
'''

class Controller(object):
    '''
    Controlls operations regarding the repository
    '''


    def __init__(self, repository):
        '''
        Constructor
        '''
        self._repo = repository
        
    def addSubject(self,subject):
        '''
        adds a subject to the repository
        '''
        return self._repo.addSubject(subject)
    
    def removeSubject(self,name):
        '''
        removes a subject from the repository by name
        '''
        return self._repo.removeSubject(name)
    
    def filterLowest(self):
        '''
        filters the repository, returning the lowest subject (by hours invested)
        '''
        return self._repo.filterLowest()
    
    def updateSubject(self,oldSubjectName, newSubject):
        '''
        updates a subject found by name, updating both hours and/or name
        '''
        return self._repo.updateSubject(oldSubjectName, newSubject)
    
    def addHours(self,name,hours):
        '''
        adds hours to a subject by its name
        '''
        self._repo.addHours(name,hours)
    
    def getAll(self):
        return self._repo.getAll()
        