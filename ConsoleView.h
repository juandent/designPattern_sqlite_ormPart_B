#pragma once

#include <vector>
#include <iostream>
#include "Model.h"

class ConsoleView {
public:
    void displayUsers(const std::vector<User>& users) {
        std::cout << "\n--- User List ---\n";
        for (const auto& user : users) {
            std::cout << user.id << ". " << user.name << " (" << user.email << ")\n";
        }
    }

    void displayTasks(const std::vector<Task>& tasks) {
        std::cout << "\n--- Task List ---\n";
        for (const auto& task : tasks) {
            std::cout << task.id << ". [" << (task.completed ? "x" : " ") << "] "
                << task.title << "\n";
        }
    }

    void displayMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
};
