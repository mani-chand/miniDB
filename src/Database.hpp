#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Table.hpp"
#include <vector>
#include <string>

class Database {
private:
    std::string name;
    std::vector<Table> tables;

    bool checkTableExist(const std::string& table_name) const {
        for (const auto& table : tables) {
            if (table.getTableName() == table_name) {
                return true;
            }
        }
        return false;
    }

public:
    Database(const std::string& db_name)
        : name(db_name) {}

    bool createTable(const std::string& table_name) {
        if (checkTableExist(table_name)) {
            return false;
        }

        tables.emplace_back(table_name);
        return true;
    }
};

#endif