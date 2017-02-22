from repository.Repository import Repository 
from controller.Controller import Controller
from ui.UI import UI
from repository.TasksRepository import TasksRepository
from controller.TaskController import TaskController
from ui.TaskUI import TaskUI

taskRepository = TasksRepository()
taskController = TaskController(taskRepository)
taskUI = TaskUI(taskController)
repository = Repository()
controller = Controller(repository)
ui = UI(controller, taskUI)
ui.mainLoop()
