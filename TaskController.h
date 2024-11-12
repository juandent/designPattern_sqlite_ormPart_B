#pragma once
#include "Model.h"

class TaskController {
public:
    explicit TaskController(decltype(initStorage())& storage) : storage(storage) {
        storage.sync_schema();
    }

    int addTask(const std::string& title, int userId) {
        Task task{ -1, title, false, userId };
        return storage.insert(task);  // Returns the new task's ID
    }

    std::vector<Task> listTasksForUser(int userId) {
        return storage.get_all<Task>(sqlite_orm::where(sqlite_orm::c(&Task::userId) == userId));
    }

    bool toggleTaskCompletion(int taskId) {
        auto task = storage.get_pointer<Task>(taskId);
        if (task) {
            task->completed = !task->completed;
            storage.update(*task);
            return true;  // Task found and toggled
        }
        return false;  // Task not found
    }

private:
    decltype(initStorage())& storage;
};
