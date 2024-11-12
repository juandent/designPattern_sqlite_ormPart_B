#pragma once
#include "Model.h"

class UserController {
public:
    explicit UserController(decltype(initStorage())& storage) : storage(storage) {
        storage.sync_schema();
    }

    int addUser(const std::string& name, const std::string& email) {
        User user{ -1, name, email };
        return storage.insert(user);  // Returns the new user's ID
    }

    std::vector<User> listUsers() {
        return storage.get_all<User>();
    }

private:
    decltype(initStorage())& storage;
};
