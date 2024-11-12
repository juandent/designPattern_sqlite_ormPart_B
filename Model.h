#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include <string>
#include <vector>

struct User {
    int id;
    std::string name;
    std::string email;
};

struct Task {
    int id;
    std::string title;
    bool completed;
    int userId; // Foreign key linking the task to a user
};

auto initStorage() {
    using namespace sqlite_orm;
    return make_storage("app.db",
        make_table("users",
            make_column("id", &User::id, primary_key().autoincrement()),
            make_column("name", &User::name),
            make_column("email", &User::email)
        ),
        make_table("tasks",
            make_column("id", &Task::id, primary_key().autoincrement()),
            make_column("title", &Task::title),
            make_column("completed", &Task::completed),
            make_column("user_id", &Task::userId)
        )
    );
}
