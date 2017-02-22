'''
Created on 5 Mar 2016

@author: Mihai
'''
import webbrowser
class website(object):
    '''
    website object
    '''
    
    def __init__(self,name,url):
        self.url = url
        self.name = name
        
    def __eq__(self,other):
        if(self.url == other.url and self.name == other.name) :
            return True
        return False
    
    def getName(self):
        return self.name
    
    def setName(self,newname):
        self.name = newname
    
    def getUrl(self):
        return self.url
    
    def setUrl(self,newurl):
        self.url = newurl
        
    def __str__(self):
        return str(self.name)
    
    
class websiteControl(object):
    '''
    holds repository of websites for school
    '''


    def __init__(self):
        '''
        repository of websites
        '''
        self.list = []
        self.loadFromFile()
        
    def accesWebsite(self,name):
        for counter in self.list:
            if counter.name == name:
                webbrowser.open(counter.url)
        
    def loadFromFile(self):
        file = open("websites.txt","r")
        newline = file.readline()
        while newline != "end":
            newline = newline.split(" ")
            newWebsite = website(str(newline[0]), str(newline[1]))
            self.list.append(newWebsite)
            newline = file.readline()
     
    def saveToFile(self):
        file = open("websites.txt","w")
        for counter in self.list:
            file.write(str(counter.name) + " " + str(counter.url))
        file.write("end")   
    
    def getAll(self):
        listOfStrings = []
        for counter in self.list:
            listOfStrings.append(str(counter))
        return listOfStrings
    