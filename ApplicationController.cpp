#include "ApplicationController.h"

#include <iostream>

#include "ConsoleView.h"
#include "Model.h"


int main() {
    auto storage = initStorage();
    ApplicationController appController(storage);
    ConsoleView view;

    int choice;
    std::string name, email, title;
    int userId, taskId;

    while (true) {
        std::cout << "\n--- Application Menu ---\n";
        std::cout << "1. Create User\n2. List Users\n3. Create Task\n4. List Tasks for User\n";
        std::cout << "5. Toggle Task Completion\n6. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter user name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter user email: ";
            std::getline(std::cin, email);
            appController.createUser(name, email);
            view.displayMessage("User created successfully.");
            break;

        case 2:
            view.displayUsers(appController.getAllUsers());
            break;

        case 3:
            std::cout << "Enter task title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter user ID for the task: ";
            std::cin >> userId;
            appController.createTask(title, userId);
            view.displayMessage("Task created successfully.");
            break;

        case 4:
            std::cout << "Enter user ID to list tasks: ";
            std::cin >> userId;
            view.displayTasks(appController.getTasksForUser(userId));
            break;

        case 5:
            std::cout << "Enter task ID to toggle completion: ";
            std::cin >> taskId;
            if (appController.toggleTaskCompletion(taskId)) {
                view.displayMessage("Task completion toggled.");
            }
            else {
                view.displayMessage("Task not found.");
            }
            break;

        case 6:
            view.displayMessage("Exiting program.");
            return 0;

        default:
            view.displayMessage("Invalid option. Try again.");
        }
    }
}
