#pragma once
#include "TaskController.h"
#include "UserController.h"

class ApplicationController {
public:
    explicit ApplicationController(decltype(initStorage())& storage)
        : storage(storage), userController(storage), taskController(storage) {}

    int createUser(const std::string& name, const std::string& email) {
        return userController.addUser(name, email);
    }

    std::vector<User> getAllUsers() {
        return userController.listUsers();
    }

    int createTask(const std::string& title, int userId) {
        return taskController.addTask(title, userId);
    }

    std::vector<Task> getTasksForUser(int userId) {
        return taskController.listTasksForUser(userId);
    }

    bool toggleTaskCompletion(int taskId) {
        return taskController.toggleTaskCompletion(taskId);
    }

private:
    decltype(initStorage())& storage;
    UserController userController;
    TaskController taskController;
};
